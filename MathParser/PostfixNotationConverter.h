#pragma once
#include <map>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>


class PostfixNotationConverter {
private:
    std::string infixExpr;
    std::stack<std::string> stack; //	Инициализация стека, содержащий операторы в виде символов
    std::stack<std::string> history; //	Инициализация стека, содержащий операторы в виде символов
    void putOperator(std::string word, int i) {
        if (word == "-" && isOperator(history.top()) && operationPriority[history.top()] < 5)
            word = "~"; //	Если да - преобразуем его в тильду


        while (stack.size() > 0 && ( operationPriority[stack.top()] >= operationPriority[word])) {
            postfixExpr.push_back(stack.top()); //	Заносим в выходную строку все операторы из стека,
            stack.pop();                        //  имеющие более высокий приоритет
        }

        stack.push(word); //Заносим в стек оператор
        history.push(word);
    }
    void putEndingParenthesis  (std::string word) {
        //	Заносим в выходную строку из стека всё вплоть до открывающей скобки
        while (stack.size() > 0 && stack.top() != "(") {
            postfixExpr.push_back(stack.top());
            stack.pop();
        }
        //	Удаляем открывающуюся скобку из стека
        stack.pop();
        history.push(word);
        if (operationPriority[stack.top()] == 5) {
            postfixExpr.push_back(stack.top());
            history.push(stack.top());
            stack.pop();
        }
    }
    void putOpeningParenthesis (std::string word) {
        stack.push(word);
        history.push(word);
    }
    void putNumber (std::string word) {
        postfixExpr.push_back(word);
        history.push(word);
    }
    void putEpsilon(std::string word){
        postfixExpr.push_back(word);
        history.push(word);
    }
protected:
    std::vector<std::string> postfixExpr; //	Выходная строка, содержащая постфиксную запись
    std::map<std::string, unsigned> operationPriority {
            {"(", 0},
            {"+", 1},
            {"-", 1},
            {"*", 2},
            {"/", 2},
            {"^", 3},
            {"~", 4},	//	Унарный минус
            {"sin", 5},
            {"cos", 5},
            {"tg", 5},
            {"ctg", 5},
            {"lg", 5},
            {"ln", 5}
    };

    bool isEpsilon(std::string word){
        return word == "e";
    }
    bool isNumber (std::string word) {
        if (word == "-") return false;
        for (auto ch : word)
            if ((ch < 48 || ch > 57) && ch != '.' && ch != '-')
                return false;
        return true;
    }
    bool isOpeningParenthesis (std::string word) {
        return word == "(";
    }
    bool isEndingParenthesis  (std::string word) {
        return word == ")";
    }
    bool isOperator(std::string word) {
        return std::find_if(operationPriority.begin(), operationPriority.end(),
                            [word](std::pair<std::string, unsigned> current)
                            { return current.first == word; })
               != operationPriority.end();
    }

    void toPostfix(std::string infixExpr) {
        for (int i = 0; i < infixExpr.size(); i++) {
            std::string word;
            if (infixExpr[i] == ' ') continue;
            else if (infixExpr[i] == '(') word = "(";
            else if (infixExpr[i] == ')') word = ")";
            else {
                for (int j = i; infixExpr[j] != ' ' && infixExpr[j] != '(' &&
                                infixExpr[j] != ')' && j < infixExpr.size(); ++j, ++i)
                    word += infixExpr[j];
                --i;
            }
            if      (isEpsilon(word)) putEpsilon(word);
            else if (isNumber(word)) putNumber(word);
            else if (isOpeningParenthesis(word)) putOpeningParenthesis(word);
            else if (isEndingParenthesis(word)) putEndingParenthesis(word);
            else if (isOperator(word)) putOperator(word, i);
        }

        while (!stack.empty()) { //	Заносим все оставшиеся операторы из стека в выходную строку
            postfixExpr.push_back(stack.top());
            stack.pop();
        }
    }
public:
    PostfixNotationConverter(std::string expression) {
        this->infixExpr = expression;
        toPostfix(infixExpr);
    }
    std::string getPostfixExpr() {
        std::string output;
        for (auto el : this->postfixExpr)
            output += el + " ";
        return output;
    }
};