#include <jni.h>
#include <iostream>
#include "CaesarCipher.h"
using namespace std;

JNIEXPORT jstring JNICALL Java_CaesarCipher_getInput(JNIEnv *env, jobject obj) {
    string input;
    cout << "Enter your input: ";
    cin >> input;

    // convert input to C++ String to C String, then to jstring
    return env->NewStringUTF(input.c_str());
};

JNIEXPORT jstring JNICALL Java_CaesarCipher_encrypt(
    JNIEnv *env,
    jobject obj,
    jstring plaintext,
    jint key
) {
    const char *plaintextStr = env->GetStringUTFChars(plaintext, NULL);
    string result;

    for (char chr : plaintextStr) {
        if (chr >= 'A' && chr <= 'Z') {
            result += ((chr - 'A' + key) % 26 + 'A');
        } else if (chr >= 'a' && chr <= 'z') {
            result += ((chr - 'a' + key) % 26 + 'a');
        } else {
            result += chr;
        }
    }

    return env->NewStringUTF(result.c_str());
};

JNIEXPORT jstring JNICALL Java_CaesarCipher_decrypt(
    JNIEnv *env,
    jobject obj,
    jstring ciphertext,
    jint key
) {
    const char *ciphertextStr = env->GetStringUTFChars(ciphertext, NULL);
    string result;

    for (char chr : ciphertextStr) {
        if (chr >= 'A' && chr <= 'Z') {
            result += ((chr - 'A' - key) % 26 + 'A');
        } else if (chr >= 'a' && chr <= 'z') {
            result += ((chr - 'a' - key) % 26 + 'a');
        } else {
            result += chr;
        }
    }

    return env->NewStringUTF(result.c_str());
};
