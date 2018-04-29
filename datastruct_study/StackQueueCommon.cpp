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

//运算函数
int op(int a, char op, int b) {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
	if (op == '/') {
		if (b == 0) {
			printf("Error");
		}
		else {
			return a / b;
		}
	}

}

//后缀表达式的计算
int com(char exp[]) {
	int op(int a, char op, int b);
	//ab为运算数，c为运算结果
	int i,a, b, c;
	//初始化栈
	int stack[MAXSIZE];
	int top = -1;
	char opt;
	for (i = 0; exp[i] != '\0'; i++) {
		if (exp[i] > '0'&&exp[i] < '9') {
			//如果是数字就进栈  字符型转整形需要减0
			//数字字符'0'-'9'是有效的字符，其ascii值是递增且连续的，'0'的ASCII是48 以下依次是
			stack[++top] = exp[i] - '0';
		}
		else {
			//如果是字符则连续出栈两次
			opt = exp[i];
			b = stack[top--];
			a = stack[top--];
			c = op(a, opt, b);
			stack[++top]= c;
		}
	}
	return stack[top];
}