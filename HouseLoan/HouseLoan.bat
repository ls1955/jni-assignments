@echo off

javac -h . HouseLoan.java
x86_64-w64-mingw32-gcc -I"%JAVA_HOME%\include" -I"%JAVA_HOME%\include\win32" -shared -o HouseLoan.dll HouseLoan.cpp

java -Djava.library.path=. HouseLoan
