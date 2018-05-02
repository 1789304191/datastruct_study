#ifndef _StackAndQueue_H_

#define _StackAndQueue_H_

#include "Student.h"

#define MAXSIZE 30

#define TRUE 1

#define FALSE 0

#define ERROR 2

//����˳��ջ����ͬһ��洢���Ľṹ�����
typedef struct {
	int elem[MAXSIZE];
	int top[2];
}SqStack;

//�ж�һ�����ʽ�е�С�����Ƿ���ȷ
int match(char exp[], int n);

//���㺯��
int op(int a, char op, int b);

//��׺���ʽ�ļ���
int com(char exp[]);

//����ͷ�ڵ����ջ�ĳ�ʼ��
void initLinkedStack(Student *&students);

//�жϲ���ͷ�ڵ����ջ�ж��Ƿ��ǿ���
int isEmptyLinkedStack(Student * student);

//����ͷ�ڵ����ջ��ջʵ��
void pushForLinkedStack(Student *&students,Student *p);

//����ͷ�ڵ����ջ��ջʵ��
void popForLinkedStack(Student *&students);

//����˳��ջ����ͬһ��洢������ջ���� stNo��ʾ����һ��ջ
int push(SqStack &st,int stNo,int x);

//����˳��ջ����ͬһ��洢���ĳ�ջ���� stNo��ʾ����һ��ջ x��ʾ���ܵĳ�ջԪ��
int pop(SqStack &st, int stNo, int &x);

//����˳��ջ����ͬһ��洢���ĳ�ʼ��
void init(SqStack &st);

#endif