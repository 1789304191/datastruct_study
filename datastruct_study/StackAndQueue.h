#ifndef _StackAndQueue_H_

#define _StackAndQueue_H_

#include "Student.h"

#define MAXSIZE 30

#define TRUE 1

#define FALSE 0

#define ERROR 2

//两个顺序栈共享同一块存储区的结构体设计
typedef struct {
	int elem[MAXSIZE];
	int top[2];
}SqStack;

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

//两个顺序栈共享同一块存储区的入栈操作 stNo表示入哪一个栈
int push(SqStack &st,int stNo,int x);

//两个顺序栈共享同一块存储区的出栈操作 stNo表示入哪一个栈 x表示接受的出栈元素
int pop(SqStack &st, int stNo, int &x);

//两个顺序栈共享同一块存储区的初始化
void init(SqStack &st);

#endif