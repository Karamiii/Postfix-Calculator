#include <iostream>
#include <string>
#include"../headers/stack.h"


using namespace std;



void introduction() {
    // TODO
}
void instructions() {

    //TODO

}


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
             << "[+] [-] [*] [/] [x]  are arithmetic operations" << endl
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
        cout << "Enter a real number: " << flush;
        cin >> p;
        if (numbers.push(p) == overflow)
            cout << "Warning: Stack full, lost number" << endl;
        break;

    case '=':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else
            cout << p << endl;
        break;

    case '+':
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

        //   Add options for further user commands.

    case 'q':
        cout << "Calculation finished.\n";
        return false;
    }
    return true;
}

