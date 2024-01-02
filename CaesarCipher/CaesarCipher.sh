#!/usr/bin/sh

javac -h . CaesarCipher.java
g++ -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o libCaesarCipher.so CaesarCipher.cpp

java -Djava.library.path=. CaesarCipher
