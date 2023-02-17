#include <iostream>
#include <string>
#include"../headers/stack.h"
#include<stack>
#include<cmath>
#include <cctype>
#include<sstream>



using namespace std;


void instructions() {

    cout << "Welcome to the calculator program!" << endl;
    cout << "To use the calculator, enter one of the following commands:" << endl;
    cout << "? - push a number onto the stack" << endl;
    cout << "= - print the top number on the stack" << endl;
    cout << "+ - add the top two numbers on the stack" << endl;
    cout << "- - subtract the top two numbers on the stack" << endl;
    cout << "* - multiply the top two numbers on the stack" << endl;
    cout << "/ - divide the top two numbers on the stack" << endl;
    cout << "s - sum all the numbers on the stack and push the result" << endl;
    cout << "a - calculate the average of all the numbers on the stack and push the result" << endl;
    cout << "x - swap the top two numbers on the stack" << endl;
    cout << "q - quit the program" << endl << endl;
}


// Get a command from the user
char get_command()
{
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter>:";

    while (waiting) {

        cin >> command;
        command = tolower(command);
        if (command == '?' || command == '=' || command == '+' ||
            command == '-' || command == '*' || command == '/' ||
            command == 'q' || command == 'x' || command == 's' || command == 'a')  waiting = false;


        else {
            cout << "Please enter a valid command:" << endl
                << "[?]push to stack   [=]print top" << endl
                << "[+] [-] [*] [/] [x] [s] [a]  are arithmetic operations" << endl
                << "[Q]uit." << endl;
        }
    }
    return command;
}


bool do_command(char command, Stack& numbers)
/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
      has been applied to the Stack of numbers given by the second parameter.
      A result of true is returned unless command == 'q'.
Uses: The class Stack.
*/

{
    double p, q;
    switch (command) {
    case '?':
        // Add a value in the stack
        cout << "Enter a real number: " << flush;
        cin >> p;
        if (numbers.push(p) == overflow)
            cout << "Warning: Stack full, lost number" << endl;
        break;

    case '=':
        // Show the top value in the stack
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else
            cout << p << endl;
        break;
    case '/':
        // Add the top 2 numbers in the stack
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q / p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;
    case '*':
        // Add the top 2 numbers in the stack
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q * p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case '-':
        // Add the top 2 numbers in the stack
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q - p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case '+':
        // Add the top 2 numbers in the stack
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q + p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case 'a':
        // Calculate the average of all the values in the stack

        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {

            double sum = 0;
            int counter = 0;

            while (!numbers.empty()) {
                numbers.top(p);
                sum = sum + p;
                numbers.pop();
                counter++;

            }
            sum = sum / counter;
            numbers.push(sum);
        }

        break;

    case 's':
        // Calculate the sum of all the values in the stack
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {

            double sum = 0;

            while (!numbers.empty()) {
                numbers.top(p);
                sum = sum + p;
                numbers.pop();

            }

            numbers.push(sum);
        }
        break;

    case 'x':
        // Exchange the top 2 values in the stack
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            double holder;
            double holder2;

            numbers.top(holder);
            numbers.pop();
            if (numbers.top(holder2) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(holder);
            }
            else {
                numbers.pop();
                numbers.push(holder);
                numbers.push(holder2);
            }

        }
        break;

        // Quit the program with a greeting
    case 'q':
        cout << "Calculation finished.\n";
        cout << "Greetings from Karam :D" << endl;
        return false;
    }
    return true;
}





