@echo off

javac -h . Q2.java
x86_64-w64-mingw32-g++ -I"%JAVA_HOME%\include" -I"%JAVA_HOME%\include\win32" -shared -o Q2C.dll Q2.cpp

# substitute name and id here
java -Djava.library.path=. Q2 tuna 1112223339
