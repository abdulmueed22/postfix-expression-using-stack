#include <iostream>
#include <string>

using namespace std;

bool isOperand(char c) {
    return isdigit(c);
}

int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            return 0;
    }
}

int evaluatePostfixExpression(const string& postfix) {
    int stack[100]; // Array-based stack (adjust the size as needed)
    int top = -1;

    size_t i = 0;
    while (i < postfix.length()) {
        char c = postfix[i];
        if (isOperand(c)) {
            stack[++top] = c - '0'; // Convert char to integer and push to the stack
        } else {
            int operand2 = stack[top--];
            int operand1 = stack[top--];
            int result = performOperation(c, operand1, operand2);
            stack[++top] = result; // Push the result onto the stack
        }
        i++;
    }

    return stack[top];
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    int result = evaluatePostfixExpression(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}

