#include <iostream>
#include "StackAndQueue.h"

//�ж�һ�����ʽ�е�С�����Ƿ���ȷ(�Ƚ����������)
int match(char exp[], int n) {

	//���еĶ���

	char stack[MAXSIZE];
	int top = -1;

	for (int i = 0; i < n; i++) {
		if (exp[i] == '(') {
			//��ջ
			stack[++top] = exp[i];
		}

		if (exp[i] == ')') {
			if (top == -1) {
				return 0;
			}
			else {
				//��ջ
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

//���㺯��
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

//��׺���ʽ�ļ���
int com(char exp[]) {
	int op(int a, char op, int b);
	//abΪ��������cΪ������
	int i,a, b, c;
	//��ʼ��ջ
	int stack[MAXSIZE];
	int top = -1;
	char opt;
	for (i = 0; exp[i] != '\0'; i++) {
		if (exp[i] > '0'&&exp[i] < '9') {
			//��������־ͽ�ջ  �ַ���ת������Ҫ��0
			//�����ַ�'0'-'9'����Ч���ַ�����asciiֵ�ǵ����������ģ�'0'��ASCII��48 ����������
			stack[++top] = exp[i] - '0';
		}
		else {
			//������ַ���������ջ����
			opt = exp[i];
			b = stack[top--];
			a = stack[top--];
			c = op(a, opt, b);
			stack[++top]= c;
		}
	}
	return stack[top];
}


//����ͷ�ڵ����ջ�ĳ�ʼ��
void initLinkedStack(Student *&students) {
	students = NULL;
	printf("\n��ջ��ʼ���ɹ�������\n");
}

//�ж�ͷ�ڵ����ջ�ж��Ƿ��ǿ���
int isEmptyLinkedStack(Student * student) {
	if (student == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

//����ͷ�ڵ����ջ��ջʵ��(��Ҫ�ı�ֵ&)
void pushForLinkedStack(Student *&students, Student *p)
{
	p->next = students;
	students = p;
}

//����ͷ�ڵ����ջ��ջʵ��
void popForLinkedStack(Student *&students) {
	Student * p;
	p = students->next;
	students->next = NULL;
	free(students);
	students = p;
	/*
		����
		p=students
		students=p->next;
		free(p);
	*/
}



