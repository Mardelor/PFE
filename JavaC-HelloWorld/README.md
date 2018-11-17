## Quick start
Create output directory:
mkdir out

Compile:
make.sh

Test different jar executable:
java -Djava.library.path=./out -jar ./out/\[JarName\].jar

## What is it ?
This sub-project is about using JNI (Java Native Interface) to create C library such as ezTrace plugins
and Java Wrapper Class

Here are three little examples : 
* hello.jar : Simple hello world in C call in Java - **Done**
* hellothread.jar \[n\] \[t\] : Creates n Java Threads which print their pthread ID every second during t seconds - **Done** 
* helloarg.jar : Call C fonctions with both primitives types and object exchange between Java & C - **Not done yet**
