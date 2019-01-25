#define _GNU_SOURCE // for asprintf
#include <stdio.h>
#include <GTG.h>
#include "hadooptrace_ev_codes.h"
#include "eztrace_convert.h"

int eztrace_convert_hadoop_init();
int handle_hadoop_events(eztrace_event_t *ev);

void handle_hadoop_map_entry();
void handle_hadoop_map_exit();

void handle_hadoop_reduce_entry();
void handle_hadoop_reduce_exit();

void print_hadoop_stats();
int handle_hadoop_stats(eztrace_event_t *ev);

/* Constructor of the plugin.
 * This function registers the current module to eztrace_convert
 */
struct eztrace_convert_module hadoop_module;
void libinit(void) __attribute__ ((constructor));
void libinit(void) {
    /* Specify the initialization function.
     * This function will be called once all the plugins are loaded
     * and the trace is started.
     * This function usually declared StateTypes, LinkTypes, etc.
     */
    hadoop_module.init = eztrace_convert_hadoop_init;

    /* Specify the function to call for handling an event
     */
    hadoop_module.handle = handle_hadoop_events;

    /* Specify the function to call for handling an event when eztrace_stats is called
     */
    hadoop_module.handle_stats = handle_hadoop_stats;

    /* Print the results of statistics
     */
    hadoop_module.print_stats = print_hadoop_stats;

    /* Specify the module prefix */
    hadoop_module.module_prefix = EZTRACE_HADOOP_EVENTS_ID;

    asprintf(&hadoop_module.name, "hadoop");
    asprintf(&hadoop_module.description, "Module for Hadoop library");

    hadoop_module.token.data = &hadoop_module;

    /* Register the module to eztrace_convert */
    eztrace_convert_register_module(&hadoop_module);

    printf("module Hadoop loaded\n");
}

void libfinalize(void) __attribute__ ((destructor));
void libfinalize(void) {
    printf("unloading module Hadoop\n");
}

/*
 * This function will be called once all the plugins are loaded
 * and the trace is started.
 * This function usually declared StateTypes, LinkTypes, etc.
 */
int eztrace_convert_hadoop_init() {
    addEntityValue("map_alias", "ST_Thread", "Doing Map", GTG_SEABLUE);
    addEntityValue("reduce_alias", "ST_Thread", "Doing Reduce", GTG_YELLOW);
    return 0;
}

/* declare a few variable for computing statistics */
static int nb_map_calls = 0;
static int nb_reduce_calls = 0;
static float total_time_in_map = 0;
static float total_time_in_reduce = 0;
static float last_start_time_map = 0;
static float last_start_time_reduce = 0;

/* Function called for handling an event when eztrace_stats is called
 * It shall return 1 if the event was handled successfully or
 * 0 otherwise.
 */
int handle_hadoop_stats(eztrace_event_t *ev) {
    /* depending on the event code, let's count the number of calls to function1 and function2
     * for both function, compute the average duration of the function call
     */
    switch (LITL_READ_GET_CODE(ev)) {
        case EZTRACE_HADOOP_MAP_PROLOG:
            nb_map_calls++;
            last_start_time_map = CURRENT;
            break;
        case EZTRACE_HADOOP_MAP_EPILOG:
            /* WARNING: this does not support support reentrant calls to function1.
             */
            total_time_in_map += CURRENT - last_start_time_map;
            break;

        case EZTRACE_HADOOP_REDUCE_PROLOG:
            nb_reduce_calls++;
            last_start_time_reduce = CURRENT;
            break;
        case EZTRACE_HADOOP_REDUCE_EPILOG:
            /* WARNING: this does not support support reentrant calls to function2.
             */
            total_time_in_reduce += CURRENT - last_start_time_reduce;
            break;

        default:
            /* The event was not handled */
            return 0;
    }
    return 1;
}

/* Print the results of statistics.
 */
void print_example_stats() {
    printf("\nLibHadoop:\n");
    printf("-----------\n");

    if (nb_map_calls) {
        /* Only print this when calls to function1 were detected */
        printf("%d calls to Map\n", nb_map_calls);
        printf("\taverage duration: %f us\n",
               total_time_in_map / nb_map_calls);
    }

    if (nb_reduce_calls) {
        /* Only print this when calls to function2 were detected */
        printf("%d calls to Reduce\n", nb_reduce_calls);
        printf("\taverage duration: %f us\n",
               total_time_in_reduce / nb_reduce_calls);
    }
}
