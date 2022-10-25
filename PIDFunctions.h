#ifndef QUADCOPTER_PIDFUNCTIONS_H
#define QUADCOPTER_PIDFUNCTIONS_H

double findProportionValue(const double &Kp, double &errorVal, double &timeVal);
double findIntegralVal(const double &Ki, double &errorVal, double &);
double findDerivativeValue(const double &Kd, double &errorVal, double &timeVal);

#endif //QUADCOPTER_PIDFUNCTIONS_H
