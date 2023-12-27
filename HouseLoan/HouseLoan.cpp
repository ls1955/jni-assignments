#include <jni.h>
#include <math.h>
#include <iostream>
#include "HouseLoan.h"
using namespace std;

JNIEXPORT jfloat JNICALL Java_HouseLoan_calculateMonthyPayment(
    JNIEnv *env,
    jobject obj,
    jint loanAmount,
    jfloat interestRate,
    jint paymentPerYear,
    jint numberOfYears
) {
    jfloat r = (jfloat) interestRate;
    jfloat n = (jfloat) paymentPerYear;
    jfloat t = (jfloat) numberOfYears;

    return (loanAmount * (r / n)) / (1 - pow((1 + (r / n)), (-1 * n * t)));
}
