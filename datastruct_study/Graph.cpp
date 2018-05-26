#include <iostream>
#include "graph.h"
#include "print.h"

int visited[MAXSIZE];

//ͼ�ı��� v������� �㷨����ȡһ���ڵ���ʣ�Ȼ����������������
//�ٽӶ��㣬�ݹ��������δ�����ʹ��Ķ��㣨��ͨͼ��
void DFS(AGraph * G, int v) {

	//�߽ڵ㶨��
	AcrNode *p;

	//��v�ڵ���Ϊ�ѷ���
	visited[v] = 1;
	
	//���ʸýڵ�Ķ���
	printf("%c", G->adjList[v].data);

	//pָ�򶥵�v�ĵ�һ����
	p = G->adjList[v].firstAcr;

	while (p != NULL) {
		
		//��������ߵĶ�������û�б����ʹ�����ݹ����
		if (visited[p->adjvex] == 0) {

			DFS(G, p->adjvex);
			
		}
		//pָ����һ���ߵ��յ�
		p = p->nextArc;
	}
}

//ͼ�Ĺ��������������(��ͨͼ)
void BFS(AGraph * G, int v, int visit[MAXSIZE]) {
	
	AcrNode *p;
	
	//���г�ʼ�� ͷָ�룬βָ��Ϊ0
	int que[MAXSIZE], front = 0, rear = 0;

	int j;

	//���� ����Ϊ�ѷ���
	printf("%c", G->adjList[v].data);

	visit[v] = 1;

	//��ǰ����v����
	rear = (rear + 1) % MAXSIZE;
	que[rear] = v;

	//�ӿյ�ʱ��˵�������Ѿ����
	while (front != rear) {
		
		//�������
		front = (front + 1) % MAXSIZE;

		//�ѳ��Ӷ��㸳ֵ��j
		j = que[front];

		//pָ����Ӷ���j�ĵ�һ����
		p = G->adjList[j].firstAcr;

		//��p�������ڽӵ���δ�����ʵĶ������
		while (p!=NULL) {
			
			//��ǰ�ڵ�δ�����ʣ������
			if (visit[p->adjvex] == 0) {

				//�ȷ��ʲ����Ϊ�ѷ���
				printf("%c", G->adjList[p->adjvex].data);
				visit[p->adjvex] = 1;
				
				//�ö������
				rear = (rear + 1) % MAXSIZE;
				que[rear] = p->adjvex;

			}
			//pָ��j����һ����
			p = p->nextArc;
		}
	}
}

//���ڷ���ͨͼ�����������������
void dfs(AGraph *g) {

	//��i��ʾÿ������
	int i;

	//ѭ������
	for (i = 0; i < g->n; i++) {
		//����ýڵ�û�б����ʹ�
		if (visited[i] == 0) {

			DFS(g,i);
		}
	}

}

//���ڷ���ͨͼ�Ĺ��������������
void bfs(AGraph *g) {
	
	//��i��ʾÿ������
	int i;

	//ѭ������
	for (i = 0; i < g->n; i++) {
		//����ýڵ�û�б����ʹ�
		if (visited[i] == 0) {

			BFS(g, i, visited);
		}
	}
}


//����ͨͼ�о�������Ķ���v����Զ��һ������
//���ض���Ϊ��Զ��һ���������� vΪ�����Ķ�������
//���ݹ�ȱ�����ԭ��ʵ�����������һ�����ӵ�Ԫ��
int BFS(AGraph * G, int v) {
	
	AcrNode *p;

	//���г�ʼ�� ͷָ�룬βָ��Ϊ0
	int que[MAXSIZE], front = 0, rear = 0;

	int j;

	//���� ����Ϊ�ѷ���
	printf("%c", G->adjList[v].data);

	visited[v] = 1;

	//��ǰ����v����
	rear = (rear + 1) % MAXSIZE;
	que[rear] = v;

	//�ӿյ�ʱ��˵�������Ѿ����
	while (front != rear) {

		//�������
		front = (front + 1) % MAXSIZE;

		//�ѳ��Ӷ��㸳ֵ��j
		j = que[front];

		//pָ����Ӷ���j�ĵ�һ����
		p = G->adjList[j].firstAcr;

		//��p�������ڽӵ���δ�����ʵĶ������
		while (p != NULL) {

			//��ǰ�ڵ�δ�����ʣ������
			if (visited[p->adjvex] == 0) {

				//�ȷ��ʲ����Ϊ�ѷ���
				printf("%c", G->adjList[p->adjvex].data);
				visited[p->adjvex] = 1;

				//�ö������
				rear = (rear + 1) % MAXSIZE;
				que[rear] = p->adjvex;

			}
			//pָ��j����һ����
			p = p->nextArc;
		}
	}

	//���һ�����ӵ�Ԫ��
	return j;
}


//�ж�һ������ͼ�Ƿ���һ����������ͼ��һ�����������ǣ�1.��ͨ��2.����Ϊ����-1
//vΪ������������ vnΪ�ڵ�����enΪ����������������㷨��
void getNodeAndEdgeByDFS(AGraph * G, int v, int &vn, int &en) {
	
	AcrNode *p;

	//����v����
	visited[v] = 1;
	
	//������+1
	++vn;

	p = G->adjList[v].firstAcr;

	while (p != NULL) {
		
		//����+1
		++en;
	
		//������ʹ���ֻ���ӱ���
		if (visited[p->adjvex]==0) {

			getNodeAndEdgeByDFS(G, p->adjvex, vn, en);
		}

		p = p->nextArc;
	}
}

//�ж�һ������ͼ�Ƿ���һ����������ͼ��һ�����������ǣ�1.��ͨ��2.����Ϊ����-1
int GisTree(AGraph * G) {
	//�������ͱ���Ϊ0
	int vn = 0, en = 0;
	//���㶥�����ͱ���
	getNodeAndEdgeByDFS(G, 0, vn, en);
	//������ʹ��Ķ�������ͼ�еĶ��������˵����ͨ
	//���ұ������ڶ�����-1 en/2����Ϊ����ͼ����ʵ��ͳ��������
	if (vn == G->n && (G->n - 1) == en / 2) {
		return 1;
	}
	else {
		return 0;
	}
}