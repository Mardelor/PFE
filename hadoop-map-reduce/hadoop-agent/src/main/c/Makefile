JAVA_HOME=/usr/lib/jvm/java-8-openjdk

BIN = libhadooptrace.so

all :
	gcc -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -shared -o $(BIN) hadooptrace.c -fPIC -ldl
