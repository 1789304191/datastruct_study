#include <iostream>
#include "graph.h"
#include "print.h"

int main() {

	//�ڽӱ�Ĵ���
	AGraph *G = (AGraph *) malloc(sizeof(AGraph));

	//����
	G->e = 10;

	//������
	G->n = 5;

	//ͼ�ĸ�������ֵ
	G->adjList[0].data = 'A';
	G->adjList[1].data = 'B';
	G->adjList[2].data = 'C';
	G->adjList[3].data = 'D';
	G->adjList[4].data = 'E';

	//ͼ�ı�
	AcrNode * a1 = (AcrNode *)malloc(sizeof(AcrNode));
	AcrNode * a2 = (AcrNode *)malloc(sizeof(AcrNode));;
	AcrNode * a3 = (AcrNode *)malloc(sizeof(AcrNode));;
	AcrNode * b1 = (AcrNode *)malloc(sizeof(AcrNode));;
	AcrNode * c1 = (AcrNode *)malloc(sizeof(AcrNode));;
	AcrNode * c2 = (AcrNode *)malloc(sizeof(AcrNode));;
	AcrNode * d1 = (AcrNode *)malloc(sizeof(AcrNode));;
	AcrNode * d2 = (AcrNode *)malloc(sizeof(AcrNode));;
	AcrNode * d3 = (AcrNode *)malloc(sizeof(AcrNode));;
	AcrNode * e1 = (AcrNode *)malloc(sizeof(AcrNode));;
	
	//����ָ��Ľڵ��λ��
	//����A�ı�
	a1->adjvex = 1;
	a2->adjvex = 2;
	a3->adjvex = 3;
	a1->nextArc = a2;
	a2->nextArc = a3;
	a3->nextArc = NULL;

	//����B�ı�
	b1->adjvex = 0;
	b1->nextArc = NULL;

	//����C�ı�
	c1->adjvex = 0;
	c2->adjvex = 3;
	c1->nextArc = c2;
	c2->nextArc = NULL;

	//����D�ı�
	d1->adjvex = 0;
	d2->adjvex = 2;
	d3->adjvex = 4;
	d1->nextArc = d2;
	d2->nextArc = d3;
	d3->nextArc = NULL;

	//����E�ı�
	e1->adjvex = 3;
	e1->nextArc = NULL;

	//����һ���߸�ֵ����������
	G->adjList[0].firstAcr = a1;
	G->adjList[1].firstAcr = b1;
	G->adjList[2].firstAcr = c1;
	G->adjList[3].firstAcr = d1;
	G->adjList[4].firstAcr = e1;

	//1.������ȱ���ͼ
	//DFS(G, 0);

	//2.������ȱ���ͼ
	//int visit[MAXSIZE] = { 0,0,0,0,0,0,0 };
	//int v1[MAXSIZE]; ���鲻��ʼĬ�ϲ���Ϊ0
	//printInt(v1[1]);
	//BFS(G, 0, visit);

	//3.����ͨͼ��ĳһ��������Զ·���Ķ������
	//printInt(BFS(G, 4));

	//4.������Ͷ�����
	//int n=0, e=0;
	//getNodeAndEdgeByDFS(G, 0, n, e);
	//printInt(n); printInt(e);

	//5.�ж�����ͼ�Ƿ�����
	//printInt(GisTree(G));

	//6.�ж϶���i��j֮���Ƿ���·��
	//printInt(DFSTrave(G, 0, 4));

	//7.����ͼ���ڽӾ���Ĵ���
	MGragh * M = (MGragh *)malloc(sizeof(MGragh));
	//��������
	VertexType * vex0 = (VertexType *)malloc(sizeof(VertexType));
	VertexType * vex1 = (VertexType *)malloc(sizeof(VertexType));
	VertexType * vex2 = (VertexType *)malloc(sizeof(VertexType));
	VertexType * vex3 = (VertexType *)malloc(sizeof(VertexType));
	VertexType * vex4 = (VertexType *)malloc(sizeof(VertexType));
	vex0->no = 0;
	vex1->no = 1;
	vex2->no = 2;
	vex3->no = 3;
	vex4->no = 4;
	//������Ϣ
	M->vex[0] = * vex0;
	M->vex[1] = * vex1;
	M->vex[2] = * vex2;
	M->vex[3] = * vex3;
	M->vex[4] = * vex4;
	//����Ϣ ���趥���붥��֮ǰû�б���ȨֵΪ100
	M->edges[0][0] = 100;
	M->edges[0][1] = 5;
	M->edges[0][2] = 1;
	M->edges[0][3] = 2;
	M->edges[0][4] = 100;

	M->edges[1][0] = 5;
	M->edges[1][1] = 100;
	M->edges[1][2] = 3;
	M->edges[1][3] = 100;
	M->edges[1][4] = 4;

	M->edges[2][0] = 1;
	M->edges[2][1] = 3;
	M->edges[2][2] = 100;
	M->edges[2][3] = 6;
	M->edges[2][4] = 2;

	M->edges[3][0] = 2;
	M->edges[3][1] = 100;
	M->edges[3][2] = 6;
	M->edges[3][3] = 100;
	M->edges[3][4] = 3;

	M->edges[4][0] = 100;
	M->edges[4][1] = 4;
	M->edges[4][2] = 2;
	M->edges[4][3] = 3;
	M->edges[4][4] = 100;
	
	//5������ 8����
	M->n = 5;
	M->e = 8;

	//8.��С���������ۣ�����ķ�㷨
	int sum = 0;
	Prim(*M, 0, sum);
	printInt(sum);
}