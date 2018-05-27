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

//�ж϶���i�Ͷ���j֮���Ƿ���·��
int DFSTrave(AGraph * G, int i, int j) {
	
	//������������������������j�������ˣ�˵����·��
	DFS(G, i);

	if (visited[j] == 0) {
		return 0;
	}
	else {
		return 1;
	}

}

//ͼ��С����������������ķ�㷨 gΪͼ��v0��ʾĳһ���� ��sumΪ��С����������
void Prim(MGragh g, int v0, int &sum) {
	
	//lowcostΪ��ŵ�ǰ��������ʣ����������̱ߵ�Ȩֵ
	//��3����032���ɵ������䵽����1��Ȩֵ��СΪ3������lowcost[1]=3
	//vset[i]=1��ʾi�����Ѿ������뵽���У�=0��ʾû��
	int lowcost[MAXSIZE], vset[MAXSIZE], v;

	int i, j, k, min;

	v = v0;

	for (i = 0; i < g.n; i++) {
		
		//��һ����Ϊ�˼��㶥��v0���������������Ȩֵ
		lowcost[i] = g.edges[v0][i];

		//�ڵ㻹δ��������
		vset[i] = 0;
	}

	//��v0��������
	vset[v0] = 1;

	//sum���������ۼ�����Ȩֵ
	sum = 0;

	for (i = 0; i < g.n - 1; i++) {

		//MAXSIZE������һ����ͼ������Ȩֵ����ĳ���
		min = MAXSIZE;

		//��ѭ������ѡ����ѡ���е�Ȩֵ��Сֵ
		for (j = 0; j < g.n; j++) {
			
			//ѡ����ǰ�����������ඥ����̱�����̵�һ�� ���һ�δ���뵽����
			if (vset[j] == 0 && lowcost[j] < min) {

				//��ֵ��Сֵ
				min = lowcost[j];
				
				//k��Ϊ�����������еĶ���
				k = j;
			}
		}

		//���������Сֵ�Ķ��㲢������
		vset[k] = 1;
		v = k;

		//������sum��¼����С��������Ȩֵ
		sum += min;

		//�������ѭ���Ըղ���Ķ���vΪý����º�ѡ��
		for (j = 0; j < g.n; j++) {
			
			//Ѱ��û�в���Ķ��㲢�Ҷ���j���²���Ķ���v��Ȩֵ���С��
			//ԭ����v0��Ȩֵ����ô�ͰѶ���j��v��Ȩֵ����Ϊj���������Ȩֵ
			if (vset[j] == 0 && g.edges[v][j] < lowcost[j]) {

				//����Ȩֵ
				lowcost[j] = g.edges[v][j];
			}
		}
	}

}

Road road[MAXSIZE];

//���岢�鼯����
int v[MAXSIZE];

//�ڲ��鼯�в��Ҹ��ڵ�ĺ���
int getRoot(int a) {

	//�ڲ��ҹ�����a�᲻�ϱ仯��ֱ��a=v[a]ʱ�����Ǹ��ڵ�
	/*
		0 0			0
		1 0		1	2	3
		2 0			4
		3 0
		4 2
	*/
	while (a != v[a]) {
		a = v[a];
	}
	return a;
}


//����ķ�㷨�����õ��ı߸���Ȩֵ���� roadΪ�ߣ�eΪ�ߵ�����
void sortEdges(Road * road[], int E) {

	Road *p = (Road *)malloc(sizeof(Road));

	for (int i = 0; i < E; i++) {
		for (int j = 0; j < E-i-1; j++) {
			if (road[j]->w > road[j+1]->w) {

				p->a = road[j + 1]->a;
				p->b = road[j + 1]->b;
				p->w = road[j + 1]->w;

				road[j + 1]->a = road[j]->a;
				road[j + 1]->b = road[j]->b;
				road[j + 1]->w = road[j]->w;

				road[j]->a = p->a;
				road[j]->b = p->b;
				road[j]->w = p->w;
			}
		}
	}
	
}

//ͼ����С��������������³˹�����㷨 roadΪ�� sumΪȨֵ gΪ�ڽӾ���
void Kruskal(MGragh g, int &sum, Road * road[]) {
	
	int i;

	int N, E, a, b;

	//nΪ������
	N = g.n;

	//eΪ����
	E = g.e;

	sum = 0;

	for (i = 0; i < N; i++) {
		//����˫�׽ڵ��ʾ�� v[i]=i��ʾi�����˫�׵����Լ�
		v[i] = i;
	}

	//�߰�Ȩֵ��С����
	sortEdges(road,E);

	//ѭ������ȡȨֵ��С�ıߣ��жϱߵ��������Ƿ��й�ͬ��˫�׽ڵ�
	//�������ô�ͻ��γɻ�·������������ѭ��
	for (i = 0; i < E; i++) {

		printf("�ߣ�%d-->%d,w=%d\n", road[i]->a, road[i]->b, road[i]->w);
		
		//a�����˫�׽ڵ�
		a = getRoot(road[i]->a);

		//b�����˫�׽ڵ�
		b = getRoot(road[i]->b);

		printf("���ڵ㣺%d��%d,w=%d\n", a, b, road[i]->w);

		//�������ͬһ�����ڵ���ab�߲���֮��a�ڵ��˫�׽ڵ�Ϊb
		if (a != b) {

			//a�ڵ��˫��Ϊv[b]
			v[a] = b;

			//����Ȩֵ
			sum += road[i]->w;
		}
	}

}