//
// Created by 손민균 on 26. 10. 5.
//
#include <iostream>
#include <string>
using namespace std;

int main () {
    string expression;
    cin >> expression;

    string number;
    int total = 0;
    int number_buffer = 0;
    int buffer_mode = 0;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            number.append(expression.substr (i, 1));
        }
        else {
            if (buffer_mode == 0) {
                number_buffer = stoi (number);
                total += number_buffer;
                number_buffer = 0;
                if (expression[i] == '-') buffer_mode = 1;
            }
            else {
                if (expression[i] == '+') {
                    number_buffer += stoi (number);
                }
                else {
                    number_buffer += stoi (number);
                    total -= number_buffer;
                    number_buffer = 0;
                }
            }
            number = "";
        }
    }
    if (buffer_mode == 0) {
        number_buffer = stoi (number);
        total += number_buffer;
    }
    else {
        number_buffer += stoi (number);
        total -= number_buffer;
    }

    cout << total << endl;
    return 0;
}