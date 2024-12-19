#include <iostream>
#include <string>
#include "arrayStack.h"
#include "linkedStack.h"

int getMenuChoice();
std::string getExpression();
int precedence(char c);
std::string convertExpression(std::string userExpression);
float doMath(std::string postfixExpression);


int main() {
    int menuChoice;
    std::string userExpression;
    std::string postfixExpression; 

    do {
    menuChoice = getMenuChoice();

    switch(menuChoice){
        case 1:
            userExpression = getExpression();
            postfixExpression = convertExpression(userExpression);
            std::cout << std::endl << "Postfix: " << postfixExpression << std::endl;
            std::cout << std::endl << "Final Answer: " << doMath(postfixExpression) << std::endl;
            break;
        case 2:
            std::cout << std::endl << "Did not implement." << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << std::endl << "Invalid option!" << std::endl;
            break;
        }
    }while(menuChoice != 0);


    return 0;
}


int getMenuChoice(){
    int userChoice;

    std::cout << std::endl << "POSTFIX APP" << std::endl;
    std::cout << "1. Input the infix form" << std::endl;
    std::cout << "2. Extra Credit" << std::endl;
    std::cout << "0. Exit " << std::endl;

    std::cin >> userChoice;
    return userChoice;
}

std::string getExpression() {
    std::string userExpression;
    std::cout << std::endl << "Enter the infix arithmetic expression:\n";
    std::cin.ignore();
    std::getline(std::cin, userExpression);

    return userExpression;
}

int precedence(std::string c) { // obtained from GeekForGeeks
    if (c == "/" || c == "*") {
        return 2;
    }
    else if (c == "+" || c == "-") {
        return 1;
    }
    else {                          // Using these two functions fixed a bug when          
        return 0;                   // comparing precedence in the convertExpression() function
    }
}

int precedence(char c) { // obtained from GeekForGeeks
    if (c == '/' || c == '*') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

std::string convertExpression(std::string userExpression) {
    LinkedStack<std::string> operatorStack;
    std::string postfixExpression;

    for (int i = 0; i < userExpression.length(); i++) {
        char c = userExpression[i];
        
        if (c == ' ') {
            continue;
        }

        if (std::isdigit(c)) {
            postfixExpression += c;
        }
        else if (c == '(') {
            operatorStack.push(std::string(1, c));
        }
        else if (c == ')') {
            while (!operatorStack.isEmpty() && operatorStack.peek() != "(") {
                postfixExpression += operatorStack.peek();
                operatorStack.pop();
            }
            operatorStack.pop(); // removes '('
        }
        else {
            while (!operatorStack.isEmpty() && precedence(c) <= precedence(operatorStack.peek()[0])) {
                    postfixExpression += operatorStack.peek();
                    operatorStack.pop();
                   }
                   operatorStack.push(std::string(1, c));
        }
        
    }

    while (!operatorStack.isEmpty()) {
        postfixExpression += operatorStack.peek();
        operatorStack.pop();
    }

    return postfixExpression;
}

float doMath(std::string postfixExpression) {
    LinkedStack<float> operandStack;
    float numInput;

    for (int i = 0; i < postfixExpression.length(); i++ ) {
        char c = postfixExpression[i];

        if (std::isdigit(c)) {
            operandStack.push(std::stoi(std::string(1,c)));
        }
        else {
            float temp1, temp2;
            temp1 = operandStack.peek();
            operandStack.pop();
            temp2 = operandStack.peek();
            operandStack.pop();

            if (c == '*') {
                operandStack.push(temp2 * temp1);
            }
            else if (c == '/') {
                operandStack.push(temp2 / temp1);
            }
            else if (c == '+') {
                operandStack.push(temp2 + temp1);
            }
            else if (c == '-') {
                operandStack.push(temp2 - temp1);
            }
            else {
                throw "Invalid Operator";
            }
        }
        
    }
    return operandStack.peek();
}