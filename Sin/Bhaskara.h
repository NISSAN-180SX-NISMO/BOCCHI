#pragma once
#include "Utils.h"


namespace Bhaskara {
    long double sin (long double x){
        int sign = normalize(x);
        long double result = sign * (16 * x * (pi - x))/(5 * pi * pi - 4 * x * (pi - x));
        return result;
    }
}