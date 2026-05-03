#include <iostream>
using namespace std;

int main() {

    double num1, num2;   // to store numbers
    char op;             // to store operator

    cout << "===== SIMPLE CALCULATOR =====\n";

    // Step 1: Input numbers
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Step 2: Choose operation
    cout << "Choose operation (+, -, *, /): ";
    cin >> op;

    // Step 3: Perform operation using switch
    switch(op) {

        case '+':
            cout << "Result = " << num1 + num2 << endl;
            break;

        case '-':
            cout << "Result = " << num1 - num2 << endl;
            break;

        case '*':
            cout << "Result = " << num1 * num2 << endl;
            break;

        case '/':
            // Important: handle divide by zero
            if (num2 == 0) {
                cout << "Error! Division by zero is not allowed.\n";
            } else {
                cout << "Result = " << num1 / num2 << endl;
            }
            break;

        default:
            cout << "Invalid operator!\n";
    }

    return 0;
}