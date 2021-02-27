#include <iostream>
int add (int a, int b) {
    return a + b;
}

int sub (int a, int b) {
    return a - b;
}

int mul (int a, int b) {
    return a * b;
}

int divi (int a, int b) {
    return a / b;
}

void calc(int a, char ex, int b) {
    if (ex == '+') {
       std::cout <<  add(a, b);
    }

    if (ex == '-') {
        std::cout << sub(a, b);
    }

    if (ex == '/') {
        std::cout << divi(a, b);
    }

    if (ex == '*') {
        std::cout << mul(a, b);
    }
}
int main()
{
    int a;
    char b;
    int c;
    std::cout << "enter an expression (example 2 + 5)" << std::endl;
    std::cout << "enter number" << std::endl;
    std::cin >> a;
    std::cout << "enter expresion" << std::endl;
    std::cin >> b;
    std::cout << "enter number" << std::endl;
    std::cin >> c;

    calc(a, b, c);
}
