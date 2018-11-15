% HadoopTrace
% Rémy Zirnheld

## Hadoop Trace

Créer un plugin ezTrace pour Hadoop en Java 

* Prendre en main l'interface d'instrumentation Java & l'appel de fonctions écrites en C par un programme Java 
* Implémenter les classes permettant l'instrumentation des classes Hadoop :
  Mapper, Reducer, Configured
* Créer le plugin ezTrace en C & le Wrapper Java correspondant
* Interfacer Instrumentation Java & Plugin ezTrace

![](images/hadoop.jpg){ width=35% }  +  ![](images/ezTrace.jpg){ width=35% }

## L'Application : WordCount
![Application Test - WordCount](images/mapreduce-fonctionnement.png)

## Plugin ezTrace pour Hadoop-Java
![Schéma de fonctionnement Java + ezTrace](images/hadoopTrace.png)

