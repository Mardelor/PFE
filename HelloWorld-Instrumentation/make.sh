#!/usr/bin/env bash
cd ~/Projects/PFE/HelloWorld-Instrumentation/;
rm out/*.class out/*.jar;

javac -cp ./lib/javassist-3.14.0-GA.jar src/HelloWorld.java src/HelloWorldAgent.java src/HelloWorldTransformer.java -d ./out/;
cd out;
jar cvfm app.jar resources/application/MANIFEST.MF HelloWorld.class;
jar cvfm agent.jar resources/instrumentation/MANIFEST.MF HelloWorldAgent.class HelloWorldTransformer.class;
