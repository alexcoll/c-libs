#include "mymath.h"

double getMinValue(const double * vals, int size) {
    double min = vals[0];
    double prev_min = min;
    for (int i = 1; i < size; i++) {
        prev_min = min;
        min = fmin(prev_min, vals[i]);
    }
    return min;
}

double getMaxValue(const double * vals, int size) {
    double max = vals[0];
    double prev_max = max;
    for (int i = 1; i < size; i++) {
        prev_max = max;
        max = fmax(prev_max, vals[i]);
    }
    return max;
}

double getScaledValue(double oldValue, double oldMin, double oldMax, double newMin, double newMax) {
    double oldRange = (oldMax - oldMin);
    double newRange = (newMax - newMin);
    double newValue = (((oldValue - oldMin) * newRange) / oldRange) + newMin;
    return newValue;
}
