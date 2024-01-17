#include <jni.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include <iomanip>
#include "HouseLoan.h"
using namespace std;

float to2Decimal(double val) {
    return round(value * 100.0) / 100.0;
}

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

    jfloat result = ((jfloat) loanAmount * (r / n)) / (1 - pow((1 + (r / n)), (-1 * n * t)));

    // round to 2 decimal places as given output is in 2 decimal places
    return to2Decimal(result);
}

JNIEXPORT void JNICALL Java_HouseLoan_printAmortizationTable(
    JNIEnv *env,
    jobject obj,
    jint loanAmount,
    jfloat interestRate,
    jfloat montlyPayment
) {
    cout << "---------------------------------------------------------" << endl;
    cout << "| NO | Montly Payment | Interest | Principal | Balance  |" << endl;
    cout << "|  0 |                |          |           | " << loanAmount << "    |" << endl;

    // get object's class reference
    jclass klass = env->GetObjectClass(obj);
    // get method ID for *calculatePrinciplePayment* to call it later
    jmethodID pCallback = env->GetMethodID(klass, "calculatePrincipalPayment", "(IFF)F");

    jdouble balance = (jdouble) loanAmount;

    for (int i = 1 ; i <= 12; i++) {
        jdouble interest = balance * (interestRate / 12);
        jdouble principal = env->CallDoubleMethod(obj, pCallback, monthlyPayment, interest);
        balance -= principal;

        // round all values to 2 decimal places
        principal = to2Decimal(principal);
        balance = to2Decimal(principal);
        interest = to2Decimal(interest);

        // print the rows...
        cout << "| " << setw(2) << i << " |     ";
        cout << montlyPayment << "    |   ";
        cout << fixed << setprecision(2) << setw(5) << interest;
        cout  << "  |  " << principal << "  | " << setw(8) << balance << " |" << endl;
    }

    cout << "---------------------------------------------------------" << endl;
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
