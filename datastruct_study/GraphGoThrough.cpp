#include <iostream>
#include "graph.h"
#include "print.h"
#include "MGraph.h"

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
	//int sum = 0;
	//Prim(*M, 0, sum);
	//printInt(sum);

	//9.�߸���Ȩֵ����
	Road * road1 = (Road *)malloc(sizeof(Road));
	Road * road2 = (Road *)malloc(sizeof(Road));
	Road * road3 = (Road *)malloc(sizeof(Road));
	Road * road4 = (Road *)malloc(sizeof(Road));
	Road * road5 = (Road *)malloc(sizeof(Road));
	Road * road6 = (Road *)malloc(sizeof(Road));
	Road * road7 = (Road *)malloc(sizeof(Road));
	Road * road8 = (Road *)malloc(sizeof(Road));
	road1->a = 2;
	road1->b = 0;
	road1->w = 1;
	
	road2->a = 3;
	road2->b = 0;
	road2->w = 2;

	road3->a = 4;
	road3->b = 3;
	road3->w = 3;

	road4->a = 1;
	road4->b = 4;
	road4->w = 4;

	road5->a = 0;
	road5->b = 1;
	road5->w = 5;

	road6->a = 4;
	road6->b = 2;
	road6->w = 2;

	road7->a = 1;
	road7->b = 2;
	road7->w = 3;

	road8->a = 2;
	road8->b = 3;
	road8->w = 6;
	Road * road[8] = { road1,road2,road3,road4,road5,road6,road7,road8 };
	//sortEdges(road, 8);
	
	//10.��³˹�����㷨
	//int sum = 0;
	//Kruskal(*M, sum, road);
	//printInt(sum);

	//11.path[]���飬������˫�״洢��ʽ���Ӹ��ڵ㵽Ҷ�ӽڵ��·�������
	//int path[] = { -1,0,1,0,5,2,4 };
	//printfPath(path, 6);

	//12.�Ͻ�˹�����㷨����ĳһ���㵽���ඥ������·��
	//����0�����·��
	int dist[MAXSIZE];  
	//���·������һ�����㣨�����ڵ㣩�������Եõ��Ӹ��ڵ㵽�ö����·��
	int path[MAXSIZE];
	Dijkstra(*(initDijkstra()), 0, dist, path);
	printArray(7, dist);
	printf("\n");
	printArray(7, path);
}