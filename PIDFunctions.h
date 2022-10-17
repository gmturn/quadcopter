#ifndef QUADCOPTER_PIDFUNCTIONS_H
#define QUADCOPTER_PIDFUNCTIONS_H

double findErrorValue(double &leftSideTilt, double &rightSideTilt);
double findProportionValue(const double &Kp, double &errorVal, double &timeVal);
double findIntegralVal(const double &Ki, double &errorVal, double &);


#endif //QUADCOPTER_PIDFUNCTIONS_H
