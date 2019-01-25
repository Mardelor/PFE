JAVA_HOME=/usr/lib/jvm/java-8-openjdk

BIN = libhadooptrace.so

LDFLAGS=-L/usr/local/lib
CFLAGS=-I/usr/local/include -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux

all :
	gcc --shared -o $(BIN) hadooptrace.c -fPIC $(CFLAGS) $(LDFLAGS) -ldl -llitl -leztrace

clean :
	rm -f $(BIN)
