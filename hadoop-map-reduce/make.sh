#!/usr/bin/env bash
AGENT_DIRECTORY_SRC=hadoop-agent/src;
APP_DIRECTORY_SRC=hadoop-application/src;

cd ~/Projects/PFE/hadoop-map-reduce/target;
rm ./*;

javac ../${AGENT_DIRECTORY_SRC}/main/java/*.java ../${APP_DIRECTORY_SRC}/main/java/*.java -d ./;
jar cvfm agent.jar ../${AGENT_DIRECTORY_SRC}/main/resources/MANIFEST.MF DurationAgent.class DurationTransformer.class;
jar cvfm app.jar ../${APP_DIRECTORY_SRC}/main/resources/MANIFEST.MF MapClass.class ReduceClass.class WordCount.class;
