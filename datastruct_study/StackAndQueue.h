#ifndef _StackAndQueue_H_

#define _StackAndQueue_H_

#include "Student.h"

#define MAXSIZE 30

#define TRUE 1

#define FALSE 0

#define ERROR 2

//判断一个表达式中的小括号是否正确
int match(char exp[], int n);

//运算函数
int op(int a, char op, int b);

//后缀表达式的计算
int com(char exp[]);

//不带头节点的链栈的初始化
void initLinkedStack(Student *&students);

//判断不带头节点的链栈判断是否是空链
int isEmptyLinkedStack(Student * student);

//不带头节点的链栈进栈实现
void pushForLinkedStack(Student *&students,Student *p);

//不带头节点的链栈出栈实现
void popForLinkedStack(Student *&students);

#endif