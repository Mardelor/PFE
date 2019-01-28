JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64

BIN = libeztrace-hadoop.so libeztrace-autostart-hadoop.so libeztrace-convert-hadoop.so

LDFLAGS=-L/usr/local/lib
CFLAGS=-I/usr/local/include -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -g

all : $(BIN)

libeztrace-autostart-hadoop.so: hadooptrace.c
	gcc --shared -o libeztrace-autostart-hadoop.so hadooptrace.c -fPIC $(CFLAGS) $(LDFLAGS) -ldl -llitl -leztrace -DEZTRACE_AUTOSTART

libeztrace-hadoop.so: hadooptrace.c
	gcc --shared -o libeztrace-hadoop.so hadooptrace.c -fPIC $(CFLAGS) $(LDFLAGS) -ldl -llitl -leztrace

libeztrace-convert-hadoop.so: eztrace_convert_hadooptrace.c
	gcc --shared -o libeztrace-convert-hadoop.so eztrace_convert_hadooptrace.c -fPIC $(CFLAGS) $(LDFLAGS) -ldl -llitl -leztrace

clean :
	rm -f $(BIN)
