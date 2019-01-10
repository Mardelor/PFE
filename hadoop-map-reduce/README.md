## Hadoop-map-reduce
WordCount with Java instrumentation

### Quick start
Use Maven to setUp Env:

    mvn clean install
    
Make sure output directory doesn't exist, that you initialized JAVA_HOME environment variable and run :

    rm -rf hadoop-application/src/main/resources/output
    cd ${HOME}/.../hadoop-map-reduce/hadoop-agent/src/main/c
    gcc -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -shared -o libhadooptrace.so hadooptrace.c -pthread
    cd ${HOME}/.../hadoop-map-reduce
    java -Djava.library.path=./hadoop-agent/src/main/c -javaagent:./hadoop-agent/target/hadoop-agent-1.0-SNAPSHOT.jar -jar hadoop-application/target/hadoop-application-1.0-SNAPSHOT.jar hadoop-application/src/main/resources/input.txt hadoop-application/src/main/resources/output

Last command doesn't work at the moment : it seam's that, when the `agent` recompile the app, it cannot import external classes,
in our case the class which defines natives methods...
Possible Solution :
* Use static methods to avoid instanciation
* Generate class during agent-time and map native method directly