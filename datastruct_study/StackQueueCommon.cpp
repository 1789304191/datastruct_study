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