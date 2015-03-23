#include <stdlib.h>
#include <math.h>

extern double getMinValue(const double * vals, int size);
extern double getMaxValue(const double * vals, int size);
double getScaledValue(double oldValue, double oldMin, double oldMax, double newMin, double newMax);
