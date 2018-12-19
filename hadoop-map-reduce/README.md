## Hadoop-map-reduce
WordCount with Java instrumentation

### Quick start
Use Maven to setUp Env:

    mvn clean install
    
Make sure output directory doesn't exist and run :

    rm -rf hadoop-application/src/main/resources/output
    cd ${HOME}/.../hadoop-map-reduce
    java -javaagent:./hadoop-agent/target/hadoop-agent-1.0-SNAPSHOT.jar -jar hadoop-application/target/hadoop-application-1.0-SNAPSHOT.jar hadoop-application/src/main/resources/input.txt hadoop-application/src/main/resources/output

    java -cp ./hadoop-agent/target/hadoop-agent-1.0-SNAPSHOT.jar -Djava.library.path=./hadoop-agent/src/main/c -javaagent:./hadoop-agent/target/hadoop-agent-1.0-SNAPSHOT.jar -jar hadoop-application/target/hadoop-application-1.0-SNAPSHOT.jar hadoop-application/src/main/resources/input.txt hadoop-application/src/main/resources/output
