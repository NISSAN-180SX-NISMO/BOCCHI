#pragma once
#include "Utils.h"


namespace Makloren  {
    long double sin(long double x, int iters = 20){
        int shift = normalize(x);
        long double result = x;
        long double xx = x * x;
        long long unsigned fact = 1;
        for (int i = 1; i < iters; ++i){
            x*= -xx;
            fact *= (2 * i) * (2 * i + 1);
            result += (long double)(x / fact);
        }
        long double res = shift * result;
        return res;
    }

    long double cos (long double x, int iters = 30) {
        int sign = 1;
        if (x < 0) x = -x;
        while (x > dtor(90)) {
            if (x >= (double)dtor(360)) {
                x -= dtor(360);
            } else if (x > dtor(270)) {
                x = dtor(360) - x;
                sign = 1;
            } else if (x > dtor(180)) {
                x -= dtor(180);
                sign = -1;
            } else if (x > dtor(90)) {
                x -= (x - dtor(90)) * 2;
                sign = -1;
            }
        }
        long double result = 1;
        long double xx = x * x;
        x = 1;
        long long unsigned fact = 1;
        for (int i = 1; i < iters; ++i){
            x*= -xx;
            fact *= (2 * i - 1) * (2 * i);
            result += (long double)(x / fact);
        }
        return sign * result;
    }
}