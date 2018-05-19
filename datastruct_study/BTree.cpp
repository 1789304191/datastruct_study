#include <iostream>
#include "BTree.h"
#include "StackAndQueue.h"

//ȫ�ּ�������
int COUNT = 0;

//������������������������������
int comp(BTNode * p) {
	int a, b;
	//�����ǰ����������������ΪNULL��ô��Ϊ����ʽ
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

//��������Ŀ���
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

		//��¼������
		int max = 0;

		//ѭ��������LNOΪ������
		//���������ͬ�������Ԫ�ؾ��ǿ���
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

void visit(BTNode * p) {
	//����ͷ�ڵ�
	printf("%c\n", p->c);
}

void visit(TBTNode * p) {
	//����ͷ�ڵ�
	printf("%c\n", p->data);
}

//�������Ż������ķǵݹ�ʵ��(����)
void preOrderNonRecurision(BTNode * p) {
	if (p != NULL) {
		
		//����һ�����ɽڵ��ջ
		BTNode *stack[MAXSIZE];

		//��ʼ��ջ
		int top = -1;

		//��ջ�ڵ�
		BTNode *q;

		//���ڵ���ջ
		stack[++top] = p;

		//��ջ�в�Ϊ��ʱ
		while (top != -1) {

			//��ջ
			q = stack[top--];

			//���ʽڵ�
			visit(q);

			//����Һ��Ӵ��ڣ��Һ�������ջ����Ϊջ���Ƚ��������������������
			if (q->rchild != NULL) {
				//���ﲻ����top++
				stack[++top] = q->rchild;
			}

			//������Ӵ��ڣ�������ջ
			if (q->lchild != NULL) {
				stack[++top] = q->lchild;
			}
		}
	
	}
	
}

//�������Ż������ķǵݹ�ʵ�֣�����
void inOrderNonRecurision(BTNode * bt) {

	if (bt != NULL) {
		
		//1.��ʼ��ջ
		BTNode *stack[MAXSIZE];
		int top = -1;

		//2.��ջԪ��
		BTNode * p;
		p = bt;

		while (top != -1 || p != NULL) {
			
			//����ջ���ڵ㣬������Ӵ�����������ջ
			while (p != NULL) {
				stack[++top] = p;
				p = p->lchild;
			}

			if (top != -1) {
				//��ʱû���������ջ
				p = stack[top--];
				visit(p);
				//����Ƿ����Һ��ӣ����������ջ
				p = p->rchild;

				/*
				����   1
					2		4
				3		5
				�������Ϊ 3��2��5��1��4
				��Ϊ������1ʱ��ջΪ�գ�������Ҫ�ж�p�Ƿ�Ϊ��
				��ʹѭ������

				�ܽ᣺1.��������ջ
					  2.Ȼ�����ӳ�ջ���ж��Ƿ����Һ��ӣ��еĻ����Һ��ӽ�ջ
					  3.�Һ��ӳ�ջ��Ȼ����ڵ��ջ ��ʱջΪ�ա�
					  4.�Һ��ӽ�ջ���Һ��ӳ�ջ
				*/
			}
		}
	
	}
}

//�������Ż������ķǵݹ�ʵ�֣�����
void postOrderNonRecurision(BTNode * bt) {
	if (bt != NULL) {
		//1.��ʼ������ջ
		
		//����ջ
		BTNode * stack1[MAXSIZE];
		int top1 = -1;

		//�����ջ
		BTNode * stack2[MAXSIZE];
		int top2 = -1;

		//��ջԪ��
		BTNode *p = NULL;

		//���ڵ���ջ
		stack1[++top1] = bt;

		//��ջ��Ϊ��
		while (top1 != -1) {
			
			//����ջ��ջԪ��
			p = stack1[top1--];
			
			//�����ջ��ջ
			stack2[++top2] = p;

			//����Һ��Ӳ�ΪNULL���ջ��֮ǰ�������Һ����Ƚ�����Ϊջ���Ƚ����
			//������������ջ�ĳ��������պ��෴
			if (p->lchild != NULL) {
				stack1[++top1] = p->lchild;
			}
			if (p->rchild != NULL) {
				stack1[++top1] = p->rchild;
			}
			//���������stack1�ĳ�ջ����������Ľ�ջ
			//�������������ջ��Ԫ�ؽ��г�ջ�����Ϳ�����
		}

		while (top2 != -1) {
			//��ջ�����м�Ϊ�����������
			visit(stack2[top2--]);
		}
	}
}

//����������������
void InThread(TBTNode * p, TBTNode * &pre) {
	if (p != NULL) {

		//�ݹ����������Ի� ��Ϊ�����������˳�����ж����������Ƿ�Ϊ�գ�
		//���p��������Ϊ����ָ��ǰ��pre�����pre��������Ϊ�գ����������ĺ�̽ڵ�Ϊp��Ȼ��pre=p; pre���ڵ������Ǳ�����һ���ڵ㣬pΪ��ǰ���ʵĽڵ�
		InThread(p->lchild, pre);

		if (p->lchild == NULL) {
			//������ǰ����ǰ������
			p->lchild = pre;
			p->ltag = 1;
		}

		//���ǰ�����ĺ������ΪNULL
		if (pre != NULL && pre->rchild == NULL) {
			//����ǰ�����ĺ������
			pre->rchild = p;
			pre->rtag = 1;
		}

		//��ǰ�����ָ��ǰ���
		pre = p;

		//�ݹ����������Ի�
		InThread(p->rchild, pre);
	}

}

//ͨ���������������������������
void creatInThread(TBTNode * root) {

	TBTNode *pre = NULL;

	if (root != NULL) {

		InThread(root, pre);

		//�������һ���ڵ� ��Ϊ��������� p�ĺ��Ϊnull
		pre->rchild = NULL;
		pre->rtag = 1;
	}

}

//�������µĵ�һ���ڵ���㷨����pΪ��������������������
//�㷨ԭ����ltag���Ϊ0���ʾ�ýڵ���������
TBTNode * First(TBTNode *p) {
	while (p->ltag == 0) {
		p = p->lchild;
	}
	return p;
}

//�����������������У��ڵ�p�������µĺ�̽ڵ�
TBTNode * Next(TBTNode *p) {
	//���rtag��ʾ��̽ڵ�
	if (p->rtag == 1) {
		return p->rchild;
	}
	else {
		//first����������������p->rchildΪ���ڵ�ʱ������ǰ���������˳���µ�һ���ڵ㡣
		return First(p->rchild);
	}
}

//������������������
void InOder(TBTNode * root) {
	//first���������µ�һ���ڵ㣬next�����̽ڵ�
	for (TBTNode *p = First(root); p != NULL; p = Next(p)) {
		visit(p);
	}
}


//ǰ����������������Ϊ��ǰ�����Է��ʽڵ������ǰ��
void preThread(TBTNode *p, TBTNode *&pre) {
	if (p != NULL) {

		//���Ϊ��ָ�룬��Ϊ����
		if (p->lchild == NULL) {
			//ǰ��
			p->lchild = pre;
			p->ltag = 1;
		}

		if (pre!=NULL && pre->rchild == NULL) {
			//���
			pre->rchild=p;
			pre->rtag = 1;
		}
		
		pre = p;

		//������������ �����ָ��ż����ݹ飺ԭ��������ʶ��Ϊ��������ôp->lchildΪǰ������ǰ���Ѿ����Ի���
		if (p->ltag == 0){
			preThread(p->lchild, pre);
		}
		

		//������������
		if (p->rtag == 0) {
			preThread(p->rchild, pre);
		}

	}

}


//ǰ�������������ı���
void preOrder(TBTNode * root) {

	if (root != NULL) {
		
		TBTNode *p = root;

		while(p!=NULL){

			//����ָ�벻������ʱ���ʾ������������
			while (p->ltag==0) {
				visit(p);
				p = p->lchild;
			}
			//��ʱp����ָ��Ϊ������Ϊǰ�� �ȷ���p
			visit(p);
			//��ʱpһֱָ�����̲����Ƿ�Ϊ����rchild�ɱ�ʾ������Ҳ�ɱ�ʾָ��
			p = p->rchild;

		}
	}

}

//��������������
void postThread(TBTNode *p, TBTNode *&pre) {

	if (p != NULL) {

		//������
		postThread(p->lchild, pre);

		//������
		postThread(p->rchild, pre);

		if (p->lchild == NULL) {
			p->lchild = pre;
			p->ltag = 1;
		}

		if (pre != NULL && pre->rchild == NULL) {
			pre->rchild = p;
			pre->rtag =1;
		}
	
		pre = p;
	}

}