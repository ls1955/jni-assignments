#include <jni.h>
#include <iostream>
#include "Process.h"
using namespace std;

JNIEXPORT void JNICALL Java_Process_calculate(JNIEnv *env, jobject obj) {
    jint n1;
    jint n2;

    cout << "Key in your first number here: ";
    cin >> n1;

    cout << "Key in your second number here: ";
    cin >> n2;

    // NOTE: from provided outputs, looks like n1 will always be bigger than n2
    if (n1 < n2) {
        swap(n1, n2);
    }

    // get object's class reference
    jclass klass = env->GetObjectClass(obj);
    // get method ID for *add* to call it later
    jmethodID addCallback = env->GetMethodID(klass, "add", "(II)I");
    // get method ID for *multiple* to call it later
    jmethodID multipleCallback = env->GetMethodID(klass, "multiple", "(II)I");

    jint addResult = env->CallIntMethod(obj, addCallback, n1, n2);
    jint subResult = n1 - n2;
    jint multResult = env->CallIntMethod(obj, multipleCallback, n1, n2);
    jint divResult = (jint) n1 / n2;

    cout << "The addition of two numbers = " << addResult << endl;
    cout << "The subtraction of two numbers = " << subResult << endl;
    cout << "The multiplication of two numbers = " << multResult << endl;
    cout << "The division of two numbers = " << divResult << endl;
}
