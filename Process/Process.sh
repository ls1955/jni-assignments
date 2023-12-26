#!/usr/bin/sh

javac -h . Process.java
g++ -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o libCProcess.so Process.cpp

java -Djava.library.path=. Process
