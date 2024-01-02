@echo off

javac -h . Process.java
x86_64-w64-mingw32-gcc -I"%JAVA_HOME%\include" -I"%JAVA_HOME%\include\win32" -shared -o Process.dll Process.cpp

java -Djava.library.path=. Process
