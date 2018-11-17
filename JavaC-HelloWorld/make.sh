#!/usr/bin/env bash
echo "Cleaning output directory...";
rm -rf ./out/*;
cd out;

echo "Compiling C library...";
gcc -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -shared -o libhelloworld.so ../src/c/helloworld.c;
gcc -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -shared -o libhellothread.so ../src/c/hellothread.c -pthread;

echo "Compiling Java Programs...";
javac ../src/java/*/*.java -d ./;
jar cvfm hello.jar ../META-INF/hello/MANIFEST.MF ./hello/HelloWorld.class;
jar cvfm hellothread.jar ../META-INF/hellothread/MANIFEST.MF ./hellothread/HelloThread.class;
