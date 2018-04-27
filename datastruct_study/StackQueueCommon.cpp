#include <iostream>
#include "StackAndQueue.h"

//判断一个表达式中的小括号是否正确(先进后出的例子)
int match(char exp[], int n) {

	//队列的定义

	char stack[MAXSIZE];
	int top = -1;

	for (int i = 0; i < n; i++) {
		if (exp[i] == '(') {
			//进栈
			stack[++top] = exp[i];
		}

		if (exp[i] == ')') {
			if (top == -1) {
				return 0;
			}
			else {
				//出栈
				top--;
			}
		}
	}
	if (top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}