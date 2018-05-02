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
	if (op == '+') {
		return a + b;
	}
	else if (op == '-') {
		return a - b;
	}
	else if (op == '*') {
		return a * b;
	}else {
		if (b == 0) {
			return ERROR;
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


//不带头节点的链栈的初始化
void initLinkedStack(Student *&students) {
	students = NULL;
	printf("\n链栈初始化成功。。。\n");
}

//判断头节点的链栈判断是否是空链
int isEmptyLinkedStack(Student * student) {
	if (student == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

//不带头节点的链栈进栈实现(需要改变值&)
void pushForLinkedStack(Student *&students, Student *p)
{
	p->next = students;
	students = p;
}

//不带头节点的链栈出栈实现
void popForLinkedStack(Student *&students) {
	Student * p;
	p = students->next;
	students->next = NULL;
	free(students);
	students = p;
	/*
		或者
		p=students
		students=p->next;
		free(p);
	*/
}

//两个顺序栈共享同一块存储区的入栈操作 stNo表示入哪一个栈
int push(SqStack &st, int stNo, int x) {
	//栈不满才能入栈
	if (st.top[0] != st.top[1]) {
		//入栈1
		if (stNo == 0) {
			st.elem[++st.top[0]] = x;
			return TRUE;
		}
		else if (stNo == 1) {
			st.elem[--st.top[1]] = x;
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else {
		return FALSE;
	}

}

//两个顺序栈共享同一块存储区的出栈操作 stNo表示入哪一个栈 x表示接受的出栈元素
int pop(SqStack &st, int stNo, int &x) {
	//判断是否是空栈
	if (stNo == 0) {
		if (st.top[0] == -1) {
			return FALSE;
		}
		else {
			x = st.elem[st.top[0]--];
			return TRUE;
		}
	}
	else if (stNo == 1){
		//这里不能等于maxsize-1因为maxsize-1还可以放入值
		if (st.top[1] == MAXSIZE) {
			return FALSE;
		}
		else {
			x = st.elem[st.top[1]++];
			return TRUE;
		}
	}
	else {
		return FALSE;
	}

}

//两个顺序栈共享同一块存储区的初始化
void init(SqStack &st) {
	st=*((SqStack *)malloc(sizeof(SqStack)));
	st.top[0] = -1;
	st.top[1] = MAXSIZE;
}


