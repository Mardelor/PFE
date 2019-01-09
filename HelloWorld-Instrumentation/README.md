## Quick start
Compile :

	./make.sh

Test app :

	java -jar ./out/app.jar

Test instrumented app :

	java -javaagent:./out/agent.jar -jar ./out/app.jar

## What is it ?
This sub-project is about using a java agent to instrument − adding byte code to an existing jar file with Javassist − a hello world app.

## Use Javassist
To create an agent to instrument an application, you need to :
* Compile your application, the agent and the transformer. 
* Create your app tar with a MANIFEST.MF that specifies where your Main-Class is.
* Create your agent tar with your agent, your transformer and a MANIFEST.MF that specifies that the Premain-Class is in the agent.

The agent calls the transformer that looks up desired methods to edit.
