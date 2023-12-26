#include <jni.h>
#include <iostream>
#include "Q2.h"
using namespace std;

JNIEXPORT void JNICALL Java_Q2_sayHello(JNIEnv *env, jobject obj, jstring name, jint id) {
    // grab last digit of student ID (1194455555) as loop amount
    jint count = id % 10;
    // convert jstring into C-string
    const char *nameStr = env->GetStringUTFChars(name, NULL);
    jint i;

    for (i = 0; i < count; i++) {
        cout << "Hello, " << nameStr << endl;
    }
}
