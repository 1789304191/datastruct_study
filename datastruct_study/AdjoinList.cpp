#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大顶点数,应由用户定义 */

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

typedef struct EdgeNode /* 边表结点  */
{
	int adjvex;    /* 邻接点域,存储该顶点对应的下标 */
	EdgeType info;		/* 用于存储权值,对于非网图可以不需要 */
	struct EdgeNode *next; /* 链域,指向下一个邻接点 */
}EdgeNode;

typedef struct VertexNode /* 顶点表结点 */
{
	VertexType data; /* 顶点域,存储顶点信息 */
	EdgeNode *firstedge;/* 边表头指针 */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numNodes, numEdges; /* 图中当前顶点数和边数 */
}GraphAdjList;

void CreatGraph(GraphAdjList *g)
{
	int i, j, k;
	EdgeNode *e;
	scanf("%d%d", &g->numNodes, &g->numEdges);//获取顶点数和边数
	char c;
	//gettchar();
	for (i = 0; i<g->numNodes; i++)
	{
		while ((c = getchar()) == '\n' || c == ' ');//排除空格和换行符
		g->adjList[i].data = c;            //获取顶点值，
		g->adjList[i].firstedge = NULL;    //将边表置为空
	}
	for (k = 0; k<g->numEdges; k++)
	{
		scanf("%d%d", &i, &j);               //输入i,j 在图中有i-->j
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = g->adjList[i].firstedge;   //头插法建立边表
		g->adjList[i].firstedge = e;
		/*如果为无向图，则加入以下代码
		e=(EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = g->adjList[j].firstedge;
		g->adjList[j].firstedge= e;*/
	}
}

int main()
{
	GraphAdjList G;
	CreatGraph(&G);

	return 0;
}

