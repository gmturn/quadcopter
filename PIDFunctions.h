#ifndef QUADCOPTER_PIDFUNCTIONS_H
#define QUADCOPTER_PIDFUNCTIONS_H

double findProportionValue(const double &Kp, double &pastValue, double &currentValue);  // P(t) = X1 - (X2 / 2)
double findIntegralVal(const double &Ki, double &errorVal, double &);
double findDerivativeValue(const double &Kd, double &errorVal, double &timeVal);

#endif //QUADCOPTER_PIDFUNCTIONS_H
