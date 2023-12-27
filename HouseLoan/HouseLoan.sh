#!/usr/bin/sh

javac -h . HouseLoan.java
g++ -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o libHouseLoan.so HouseLoan.cpp

java -Djava.library.path=. HouseLoan
