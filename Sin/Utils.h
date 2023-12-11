#pragma once
#define pi 3.14159265358979323846

long double dtor(long double degrees){
    return degrees * pi / 180;
}
long double rtod(long double radians) {
    return radians / pi * 180;
}

int normalize(long double& x){
    int sign = 1;
    if (x < 0) {
        x = -x;
        sign = -1;
    }
    while (x > dtor(90)) {
        if (x >= (double)dtor(360)) {
            x -= dtor(360);
        } else if (x > dtor(270)) {
            x = dtor(360) - x;
            sign = -1;
        } else if (x > dtor(180)) {
            x -= dtor(180);
            sign = -1;
        } else if (x > dtor(90)) {
            x -= (x - dtor(90)) * 2;
            sign = 1;
        }
    }
    return sign;
}