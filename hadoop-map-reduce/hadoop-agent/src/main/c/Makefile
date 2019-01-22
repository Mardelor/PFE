JAVA_HOME=/usr/lib/jvm/java-8-openjdk

all :
	gcc -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -shared -o libhadooptrace.so hadooptrace.c -pthread
