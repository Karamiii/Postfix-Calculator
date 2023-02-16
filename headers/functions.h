#pragma once

int performOperation(char operation, int operand1, int operand2);
int evaluatePostfixExpression(std::string);
void introduction();
void instructions();
char get_command();
bool do_command(char, Stack &);