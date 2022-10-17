#include "PIDFunctions.h"
#include <cmath>
#include <iostream>

using namespace std;

double findErrorValue(double &leftSideTilt, double &rightSideTilt) {
    double errorValue;
    errorValue = leftSideTilt - rightSideTilt;
    return errorValue;
}


double findProportionValue(const double &Kp, double &errorVal, double &timeVal) {
    double proportionValue;
    proportionValue = Kp * (errorVal * timeVal);
    return proportionValue;
}

double findIntegralVal(const double &Ki, double &errorVal, double &)
