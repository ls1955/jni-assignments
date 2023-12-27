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

JNIEXPORT void JNICALL Java_HouseLoan_printAmortizationTable(
    JNIEnv *env,
    jobject obj,
    jint loanAmount,
    jfloat interestRate,
    jfloat montlyPayment
) {
    cout << "--------------------------------------------------------" << endl;
    cout << "| NO | Montly Payment | Interest | Principal | Balance |" << endl;
    cout << "|  0 |                |          |           | " << loanAmount << endl;

    // get object's class reference
    jclass klass = env->GetObjectClass(obj);
    // get method ID for *calculatePrinciplePayment* to call it later
    jmethodID pCallback = env->GetMethodID(klass, "calculatePrincipalPayment", "(IFF)F");

    jfloat balance = (jfloat) loanAmount;

    for (int i = 1 ; i <= 12; i++) {
        jfloat principal = env->CallFloatMethod(
            obj, pCallback, (jint) balance, interestRate, montlyPayment
        );
        balance -= principal;

        // TODO: Calculate the interest, maybe include another native method?
        cout << "|  " << i << " |  " << montlyPayment << " | " << principal << " | " << balance << endl;
    }
};

JNIEXPORT jfloat JNICALL Java_HouseLoan_calculatePrincipalPayment(
    JNIEnv *env,
    jobject obj,
    jint loanAmount,
    jfloat interestRate,
    jfloat montlyPayment
) {
    jfloat mp = montlyPayment;
    jfloat olb = (jfloat) loanAmount;
    jint monthsAmount = 12;

    return mp - (olb * (interestRate / monthsAmount));
};
