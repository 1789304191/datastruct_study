#include <iostream>
#include "graph.h"
#include "print.h"

int main() {

	//图的创建
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
}