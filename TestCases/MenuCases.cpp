#ifndef LISTING
#include <cmath>
#endif
#include "MenuCases.h"
#include "../Sin/Makloren.h"
#include "../Sin/Bhaskara.h"
#include "../Sin/CORDIC.h"
#include "../MathParser/MathParser.h"

void MenuCase1_1::exec() {
   int a,b;
   std::cout << "Enter a: "; std::cin >> a;
   std::cout << "Enter b: "; std::cin >> b;
   std::cout << a << " + " << b << " = " << a + b << std::endl;
    system("pause");
}

void MenuCase1_2::exec() {
    int a,b;
    std::cout << "Enter a: "; std::cin >> a;
    std::cout << "Enter b: "; std::cin >> b;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    system("pause");
}

void MenuCase1_3::exec() {
    int a,b;
    std::cout << "Enter a: "; std::cin >> a;
    std::cout << "Enter b: "; std::cin >> b;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    system("pause");
}

void MenuCase1_4::exec() {
    int a,b;
    std::cout << "Enter a: "; std::cin >> a;
    std::cout << "Enter pow: "; std::cin >> b;
    std::cout << a << " ^ " << pow << " = " << std::pow(a, b) << std::endl;
    system("pause");
}

void MenuCase2_1_1::exec() {
    double a;
    std::cout << "Enter angle a: "; std::cin >> a;
    std::cout.precision(15);
    std::ostream::fixed;
    std::cout << "sin(a) = " << Makloren::sin(a) << std::endl;
    std::cout << "precision vs. std::sin = " << std::abs(std::sin(a) - Bhaskara::sin(a)) << std::endl;
    system("pause");
}

void MenuCase2_1_2::exec() {
    double a;
    std::cout << "Enter angle a: "; std::cin >> a;
    std::cout.precision(15);
    std::ostream::fixed;
    std::cout << "sin(a) = " << Bhaskara::sin(a) << std::endl;
    std::cout << "precision vs. std::sin = " << std::abs(std::sin(a) - Bhaskara::sin(a)) << std::endl;
    system("pause");
}

void MenuCase2_1_3::exec() {
    double a;
    std::cout << "Enter angle a: "; std::cin >> a;
    std::cout.precision(15);
    std::ostream::fixed;
    CORDIC cordic(20);
    std::cout << "sin(a) = " << cordic.sin(a) << std::endl;
    std::cout << "precision vs. std::sin = " << std::abs(std::sin(a) - cordic.sin(a)) << std::endl;
    system("pause");
}

void MenuCase2_2::exec() {
    std::string expr;
    std::cout << "Enter expression: ";
    getline(std::cin, expr);
    std::cout << "result: " << MathParser::eval(expr) << std::endl;
    system("pause");
}

void MenuCase3::exec() {

    system("start C:\\SFML\\SFMLproject\\x64\\Debug/SFMLproject.exe");
}