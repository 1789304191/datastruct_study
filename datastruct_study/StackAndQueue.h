#ifndef _StackAndQueue_H_

#define _StackAndQueue_H_

#define MAXSIZE 30

//判断一个表达式中的小括号是否正确
int match(char exp[], int n);

//运算函数
int op(int a, char op, int b);

//后缀表达式的计算
int com(char exp[]);

#endif