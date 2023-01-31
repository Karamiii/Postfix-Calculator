#include <iostream>
#include<string>
#include"../headers/stack.h"
#include"../headers/functions.h"

using namespace std;


//char get_command();
//bool do_command(char, Stack &);

int main()
/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/

{
   Stack stored_numbers;
   introduction();
   instructions();
   while (do_command(get_command(), stored_numbers));
}


