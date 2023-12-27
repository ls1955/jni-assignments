#include <jni.h>
#include <math.h>
#include <iostream>
#include "HouseLoan.h"
using namespace std;

JNIEXPORT jfloat JNICALL Java_HouseLoan_calculateMonthlyPayment(
    JNIEnv *env,
    jobject obj,
    jint loanAmount,
    jfloat interestRate,
    jint paymentPerYear,
    jint numberOfYears
) {
    jfloat r = interestRate;
    jfloat n = (jfloat) paymentPerYear;
    jfloat t = (jfloat) numberOfYears;

    return ((jfloat) loanAmount * (r / n)) / (1 - pow((1 + (r / n)), (-1 * n * t)));
}
