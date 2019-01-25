JAVA_HOME=/usr/lib/jvm/java-8-openjdk

BIN = libhadooptrace.so libhadooptrace-convert.so

LDFLAGS=-L/usr/local/lib
CFLAGS=-I/usr/local/include -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux

all : $(BIN)

libhadooptrace.so:
	gcc --shared -o libhadooptrace.so hadooptrace.c -fPIC $(CFLAGS) $(LDFLAGS) -ldl -llitl -leztrace -DEZTRACE_AUTOSTART

libhadooptrace-convert.so:
	gcc --shared -o libhadooptrace-convert.so eztrace_convert_hadooptrace.c -fPIC $(CFLAGS) $(LDFLAGS) -ldl -llitl -leztrace
clean :
	rm -f $(BIN)
