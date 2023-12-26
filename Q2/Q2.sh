#!/usr/bin/sh

javac -h . Q2.java
g++ -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o libQ2C.so Q2.cpp

# substitute name and id here
java -Djava.library.path=. Q2 tuna 1112223339
