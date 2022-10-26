#include "PIDFunctions.h"
#include <cmath>
#include <iostream>

using namespace std;



double findProportionValue(const double &Kp, double &pastValue, double &currentValue) {
    double proportionValue;
    proportionValue = currentValue - (pastValue / 2);
    return proportionValue;
}


double findIntegralVal(const double &Ki, double &errorVal, double &timeVal, double previousIntegral){
    double integralVal;


    return integralVal;
}


double findDerivativeValue(const double &Kd, double &errorVal, double &timeVal) {



}