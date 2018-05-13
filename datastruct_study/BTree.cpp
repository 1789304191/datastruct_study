#include <iostream>
#include "BTree.h"
#include "StackAndQueue.h"

//ȫ�ּ�������
int COUNT = 0;

//������������������������������
int comp(BTNode * p) {
	int a, b;
	//�����ǰ����������������ΪNULL��ô��Ϊ���ʽ
	if (p->lchild != NULL && p->rchild != NULL) {
		a = comp(p->lchild);
		b = comp(p->rchild);
		return op(a, p->c, b);
	}
	else {
		return p->c - '0';
	}
}

//��������������������
int getDepth(BTNode * p) {

	if (p == NULL) {
		return 0;
	}
	else {

		int LD = getDepth(p->lchild);

		int RD = getDepth(p->rchild);

		return (LD > RD ? LD : RD) + 1;
	}
	
}

//ͨ������������ҽڵ�
void search(BTNode * p, BTNode * &q, char key) {
	if (p != NULL) {
		if (p->c == key) {
			q = p;
		}
		else {
			search(p->lchild, q, key);
			//������������鵽�ˣ��Ͳ���������
			if (q == NULL) {
				search(p->rchild, q, key);
			}
		}
	}
}

//ͨ������������ҵ�k���ڵ�
void searchBykeyIndexPre(BTNode * p, int num) {

	if (p != NULL) {
		COUNT++;
		if (COUNT == num) {
			printf("%c", p->c);
		}
		if (COUNT <= num) {
			searchBykeyIndexPre(p->lchild, num);
			searchBykeyIndexPre(p->rchild, num);
		}
	}
}

//ͨ������������ҵ�k���ڵ�
void searchBykeyIndexCenter(BTNode * p, int num) {

	if (p != NULL) {

		searchBykeyIndexCenter(p->lchild, num);

		COUNT++;
		if (COUNT == num) {
			printf("%c", p->c);
		}

		searchBykeyIndexCenter(p->rchild, num);
	}
}

//ͨ������������ҵ�k���ڵ�
void searchBykeyIndexAfter(BTNode * p, int num) {

	if (p != NULL) {

		searchBykeyIndexAfter(p->lchild, num);

		searchBykeyIndexAfter(p->rchild, num);

		COUNT++;

		if (COUNT == num) {
			printf("%c", p->c);
		}
	}
}


//��α���
void level(BTNode *p) {
	//���ף���β
	int front, rear;

	//����һ��ѭ������
	BTNode *que[MAXSIZE];

	//����Ϊ��
	front = rear = 0;

	//���ӽڵ�
	BTNode *q;

	if (p != NULL) {

		//���ڵ����
		rear = (rear + 1) % MAXSIZE;
		que[rear] = p;

		//�����в�Ϊ��
		while (front != rear) {
			
			//ͷ�ڵ����
			front = (front + 1) % MAXSIZE;
			q = que[front];

			//����ͷ�ڵ�
			printf("%c\n", q->c);

			//�����������Ϊ�գ����������ĸ��ڵ����
			if (q->lchild != NULL) {
				rear = (rear + 1) % MAXSIZE;
				que[rear] = q->lchild;
			}

			//�����������Ϊ�գ����������ĸ��ڵ����
			if (q->rchild != NULL) {
				rear = (rear + 1) % MAXSIZE;
				que[rear] = q->rchild;
			}
		}
	}
}

//��������Ŀ��
int maxNode(BTNode *p) {
	
	//1.�ȶ���һ�����У������е�ÿһ���ṹ�����һ���ڵ�͸ýڵ�Ĳ��
	St que[MAXSIZE];

	//���ף���β
	int front, rear;

	//��ǰ�ڵ�Ĳ��
	int LNO;

	//��ʼ������(Ϊ��)
	front = rear = 0;

	//���ӽڵ�
	BTNode *q;

	if (p != NULL) {

		//���
		++rear;
		//�������
		que[rear].p = p;
		//�������ڲ������Ϊ1
		que[rear].lno = 1;

		//�����в�Ϊ��
		while (rear != front) {
			
			//��������
			++front;
			q = que[front].p;
			LNO = que[front].lno;

			//������Ӳ�ΪNULL
			if (q->lchild != NULL) {
				//��ջ
				++rear;
				que[rear].p = q->lchild;
				//��ż�1 �������ϲ�
				que[rear].lno = LNO + 1;
			}

			//����Һ��Ӳ�ΪNULL
			if (q->rchild != NULL) {
				++rear;
				que[rear].p = q->rchild;
				que[rear].lno = LNO + 1;
			}
		}

		//��¼�����
		int max = 0;

		//ѭ��������LNOΪ������
		//���������ͬ�������Ԫ�ؾ��ǿ��
		for (int i = 1; i < LNO; i++) {
			//��¼��ͬ��ŵ�Ԫ��
			int n = 0;
			//����j����1����Ϊque�Ǵӵ�һ��λ�ÿ�ʼ��ӵ�
			for (int j = 1; j <= rear; j++) {
				if (que[j].lno == i) {
					n++;
				}
			}
			if (n > max) {
				max = n;
			}
		}
		return max;
	}
	else {
		return 0;
	}


}
