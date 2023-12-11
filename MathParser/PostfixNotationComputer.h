#pragma once
#include "PostfixNotationConverter.h"
#include <sstream>
#include <cmath>
#include <iostream>


class PostfixNotationComputer : public PostfixNotationConverter {
private:
    long double Execute(std::string op, long double first, long double second){
        switch (*op.c_str()) {
            case '+': return first + second;
            case '-': return first - second;
            case '*': return first * second;
            case '/': return first / second;
            case '^': return std::pow(first, second);
            default: return 0;
        }
    }
    long double Execute(std::string func, long double x){
        if (func == "sin")  return std::sin(x);
        if (func == "cos")  return std::cos(x);
        if (func == "tg")   return std::tan(x);
        if (func == "ctg")  return 1 / std::tan(x);
        if (func == "ln")   return std::log(x);
        if (func == "lg")   return std::log10(x);
        if (func == "~")    return -x;
        return 0;
    }

    std::stack<long double> locals; // Стек для хранения чисел
    int counter = 0; //	Счётчик действий
    void calcEpsilon() {
        locals.push(std::exp(1));
    }
    void calcNumber(std::string word) {
        locals.push([](const std::string& str) {
            std::istringstream iss(str);
            long double result;
            iss >> result;
            return result;
        }(word));
    }
    void calcOperator(std::string word) {
        counter += 1; //	Прибавляем значение счётчику
        //	Проверяем, является ли данный оператор унарным
        if (operationPriority[word] == 4 || operationPriority[word] == 5)
        {
            //	Проверяем, пуст ли стек: если да - задаём нулевое значение,
            //	еси нет - выталкиваем из стека значение
            long double last;
            if (locals.size() > 0) {
                last = locals.top();
                locals.pop();
            } else last = 0;
            locals.push(Execute(word,last)); //	Получаем результат операции и заносим в стек
#ifdef DEBUG
            std::cout << counter << ") " << word  << "(" << last << ") = " << locals.top() << std::endl;
#endif
            return;
        }
        //	Получаем значения из стека в обратном порядке
        long double second;
        if (locals.size() > 0) {
            second = locals.top();
            locals.pop();
        } else second = 0;

        long double first;
        if (locals.size() > 0) {
            first = locals.top();
            locals.pop();
        } else first = 0;

        locals.push(Execute(word, first, second)); //	Получаем результат операции и заносим в стек

#ifdef DEBUG
        std::cout << counter << ") " << first << " " << word << " " << second << " = " << locals.top() << std::endl;
#endif
    }
public:
    PostfixNotationComputer(std::string expression) : PostfixNotationConverter(expression) {}
    long double Calc() {
        //	Проходим по строке
        for (const auto& word : postfixExpr) {
            if (isEpsilon(word)) calcEpsilon();
            else if (isNumber(word)) calcNumber(word);
            else if (isOperator(word)) calcOperator(word);
        }

        //	По завершению цикла возвращаем результат из стека
#ifdef DEBUG
        auto temp = locals.top();
        locals.pop();
        std::cout << "result = " << temp << std::endl;
        return temp;
#else
        return locals.top();
#endif
    }
};