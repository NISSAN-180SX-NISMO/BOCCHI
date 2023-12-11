#pragma once
#include "cmath"
#include "Utils.h"

class  CORDIC {
private:
    int iterations;
    long double* rotation_angles;
    long double K;
public:
    CORDIC (int iterations) {   // precompute
        this->iterations = iterations;              // ���-�� ��������
        rotation_angles = new long double[iterations];   // �������� �����
        K = std::cos(std::atan(1));                 // ������ ���� ������������
        for (int i = 0; i < iterations; ++i) {
            long double tg = (long double)1 / (2 << i);
            rotation_angles[i] = std::atan(tg);     // ������� ���� � ���������� � ������
            K *= std::cos(std::atan(tg));           // ����������� ��������
        }
    }
    long double sin(long double angle) {
        int shift = normalize(angle);
        long double X = 0, Y = 1;
        int sign = 1;
        long double current_angle = 45 * pi / 180;
        for (int i = 0; i < iterations; ++i) {
            long double tg = (long double)1 / (2 << i);

            if (current_angle - angle > std::numeric_limits<double>::epsilon()) sign = -1; // current_angle < angle ?
            else sign = 1;
            current_angle += sign * rotation_angles[i];
            long double x = X - sign * tg * Y;
            long double y = sign * tg * X + Y;
            X = x;
            Y = y;
        }
        long double result = K * Y * shift;
        return result;
    }
};