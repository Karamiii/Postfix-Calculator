#include <iostream>
#include<string>
#include"../headers/stack.h"
#include"../headers/functions.h"
#include<sstream>
#include<stack>
#include <cctype>
#include<cmath>
#include<cstring>



using namespace std;

void calculate(stack<double>&, stack<char>&);
void secondary();
void instructionsSecondary();


int main(int argc, char* argv[])
/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/
{
       // Check for the flag
      if (argc > 1 && strcmp(argv[1], "-p") == 0) {
        Stack stored_numbers;
        instructions();
        while (do_command(get_command(), stored_numbers));

      }
      else {
        //instructionsSecondary();
        while(true){
        secondary();
        }
      }
      return 0;

}

void secondary() {

    // Read input from user
    string input;
    getline(cin, input);

    // Use stringstream to separate input into individual numbers and operators
    stringstream ss(input);

    // Use stacks to store numbers and operators
    stack<double> numStack;
    stack<char> opStack;
    stack<double> numStack2;
    stack<char>opStack2;

    // Initialize variables for parsing input
    int num = 0;
    char ch;

    // Loop through input string character by character
    while (ss.get(ch)) {
        if (isdigit(ch)) {
            // If the character is a digit, add it to the current number
            num = num * 10 + (ch - '0'); // Multiply by 10 and add the new digit
        }
        else if (ch == ' ') {
            // If the character is a space, the current number is finished
            // Push it onto the numStack and reset the number to zero for the next number
            if (num != 0) {
                numStack.push(num);
                num = 0; // Reset the number to zero for the next number
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == 'a' || ch == 's' || ch == 'x' || ch == '^' || ch == '%' || ch == 'v' || ch == 'q') {
            // If the character is an operator, push it onto the opStack
            opStack.push(ch);
        }
        else {
            // If the character is not a digit, space, or operator, it is an invalid character
            cerr << "Error: invalid character '" << ch << "'"  << endl << "Exiting program..."<< endl;
            exit(1);
        }
    }

    // Push the last number onto the numStack
    if (num != 0) {
        numStack.push(num);
    }

    // Flip the stack order
    while (!numStack.empty()) {
        numStack2.push(numStack.top());
        numStack.pop();
    }

    cout << endl;

    // Flip the stack order
    while (!opStack.empty()) {
        opStack2.push(opStack.top());
        opStack.pop();
    }

    cout << endl;

    // Perform calculations on the numStack based on the operators in opStack
    while (!opStack2.empty()) {
        calculate(numStack2, opStack2);
    }

    // Output the final result
    cout << "result: " << numStack2.top() << endl << endl;

}



// This function performs a calculation with the top two values in the numStack and the top operator in the opStack
void calculate(stack<double>& numStack2, stack<char>& opStack2) {

    double value1;
    double value2;
    char operand;
    double sum;
    int value = 2;

    // Get the top two values from the numStack


    // Get the top operator from the opStack
    operand = opStack2.top();
    opStack2.pop();

    // Perform the appropriate calculation based on the operator
    switch (operand) {
    case '+':
        value1 = numStack2.top();
        numStack2.pop();
        value2 = numStack2.top();
        numStack2.pop();
        sum = value1 + value2;
        numStack2.push(sum);
        break;

    case '-':
        value1 = numStack2.top();
        numStack2.pop();
        value2 = numStack2.top();
        numStack2.pop();
        sum = value1 - value2;
        numStack2.push(sum);
        break;

    case '*':
        value1 = numStack2.top();
        numStack2.pop();
        value2 = numStack2.top();
        numStack2.pop();
        sum = value1 * value2;
        numStack2.push(sum);
        break;

    case '/':
        value1 = numStack2.top();
        numStack2.pop();
        value2 = numStack2.top();
        numStack2.pop();
        sum = value1 / value2;
        numStack2.push(sum);
        break;

    case '%':
        value1 = numStack2.top();
        numStack2.pop();
        value2 = numStack2.top();
        numStack2.pop();
        sum = fmod(value1, value2);
        numStack2.push(sum);
        break;

    case '^':
        value1 = numStack2.top();
        numStack2.pop();
        value2 = numStack2.top();
        numStack2.pop();
        sum = pow(value1, value2);
        numStack2.push(sum);
        break;

    case 's':

        // Calculate the sum of any remaining values in the numStack
        while (!numStack2.empty()) {
            sum = sum + numStack2.top();
            numStack2.pop();
        }
        numStack2.push(sum);
        break;

    case 'a':
        // Calculate the average of any remaining values in the numStack
        while (!numStack2.empty()) {
            value++;
            sum = sum + numStack2.top();
            numStack2.pop();
        }
        sum = sum / value;
        numStack2.push(sum);
        break;

    case 'x':
        // Exchange the top two values in the numStack
        value1 = numStack2.top();
        numStack2.pop();
        value2 = numStack2.top();
        numStack2.pop();
        numStack2.push(value2);
        numStack2.push(value1);
        break;

    case 'v':
        value1 = numStack2.top();
        numStack2.pop();
        sum = sqrt(value1);
        numStack2.push(sum);
        break;

    case 'q':
        cout << "Bye bye :( " << endl;
        cout << "Greetings from Karam :)" << endl;
        exit(0);

    }




}



void instructionsSecondary()
{
    cout << "Welcome to the postix Calculator program!" << endl;
    cout << "Enter a space-separated list of numbers and operations." << endl;
    cout << "Operations: + (add), - (subtract), * (multiply), / (divide), % (modulus)," << endl << " ^ (exponent), s(sum), a(average), x(exchange), v(square root), q(quit)" << endl;
    cout << "Example: 5 3 + 2 * 8 -" << endl;
    cout << "This will calculate: ((5 + 3) * 2) - 8 = 8" << endl;
}




