#include <iostream>
#include "graph.h"
#include "print.h"

int main() {

	//邻接表的创建
	AGraph *G = (AGraph *) malloc(sizeof(AGraph));

	//边数
	G->e = 10;

	//顶点数
	G->n = 5;

	//图的各个顶点值
	G->adjList[0].data = 'A';
	G->adjList[1].data = 'B';
	G->adjList[2].data = 'C';
	G->adjList[3].data = 'D';
	G->adjList[4].data = 'E';

	//图的边
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
	
	//边所指向的节点的位置
	//顶点A的边
	a1->adjvex = 1;
	a2->adjvex = 2;
	a3->adjvex = 3;
	a1->nextArc = a2;
	a2->nextArc = a3;
	a3->nextArc = NULL;

	//顶点B的边
	b1->adjvex = 0;
	b1->nextArc = NULL;

	//顶点C的边
	c1->adjvex = 0;
	c2->adjvex = 3;
	c1->nextArc = c2;
	c2->nextArc = NULL;

	//顶点D的边
	d1->adjvex = 0;
	d2->adjvex = 2;
	d3->adjvex = 4;
	d1->nextArc = d2;
	d2->nextArc = d3;
	d3->nextArc = NULL;

	//顶点E的边
	e1->adjvex = 3;
	e1->nextArc = NULL;

	//将第一条边赋值给各个顶点
	G->adjList[0].firstAcr = a1;
	G->adjList[1].firstAcr = b1;
	G->adjList[2].firstAcr = c1;
	G->adjList[3].firstAcr = d1;
	G->adjList[4].firstAcr = e1;

	//1.深度优先遍历图
	//DFS(G, 0);

	//2.广度优先遍历图
	//int visit[MAXSIZE] = { 0,0,0,0,0,0,0 };
	//int v1[MAXSIZE]; 数组不初始默认不会为0
	//printInt(v1[1]);
	//BFS(G, 0, visit);

	//3.求连通图离某一个顶点最远路径的顶点序号
	//printInt(BFS(G, 4));

	//4.求边数和顶点数
	//int n=0, e=0;
	//getNodeAndEdgeByDFS(G, 0, n, e);
	//printInt(n); printInt(e);

	//5.判读无向图是否是树
	//printInt(GisTree(G));

	//6.判断顶点i和j之间是否有路径
	//printInt(DFSTrave(G, 0, 4));

	//7.无向图的邻接矩阵的创建
	MGragh * M = (MGragh *)malloc(sizeof(MGragh));
	//顶点类型
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
	//顶点信息
	M->vex[0] = * vex0;
	M->vex[1] = * vex1;
	M->vex[2] = * vex2;
	M->vex[3] = * vex3;
	M->vex[4] = * vex4;
	//边信息 假设顶点与顶点之前没有边则权值为100
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
	
	//5个顶点 8个边
	M->n = 5;
	M->e = 8;

	//8.最小生成树代价，普里姆算法
	int sum = 0;
	Prim(*M, 0, sum);
	printInt(sum);
}