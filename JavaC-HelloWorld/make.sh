#!/usr/bin/env bash
rm out/*.o out/*.so out/*.jar out/*.class;
cd out;
gcc -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -c ../src/HelloWorld.c -o HelloWorld.o;
gcc -shared -L ./ HelloWorld.o -o libHelloWorld.so;

javac ../src/*.java -d ./;
jar cvfm hello.jar ./MANIFEST.MF HelloWorld.class;