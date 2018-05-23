#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* ��󶥵���,Ӧ���û����� */

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
typedef char VertexType; /* ��������Ӧ���û����� */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */

typedef struct EdgeNode /* �߱���  */
{
	int adjvex;    /* �ڽӵ���,�洢�ö����Ӧ���±� */
	EdgeType info;		/* ���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ */
	struct EdgeNode *next; /* ����,ָ����һ���ڽӵ� */
}EdgeNode;

typedef struct VertexNode /* ������� */
{
	VertexType data; /* ������,�洢������Ϣ */
	EdgeNode *firstedge;/* �߱�ͷָ�� */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numNodes, numEdges; /* ͼ�е�ǰ�������ͱ��� */
}GraphAdjList;

void CreatGraph(GraphAdjList *g)
{
	int i, j, k;
	EdgeNode *e;
	scanf("%d%d", &g->numNodes, &g->numEdges);//��ȡ�������ͱ���
	char c;
	//gettchar();
	for (i = 0; i<g->numNodes; i++)
	{
		while ((c = getchar()) == '\n' || c == ' ');//�ų��ո�ͻ��з�
		g->adjList[i].data = c;            //��ȡ����ֵ��
		g->adjList[i].firstedge = NULL;    //���߱���Ϊ��
	}
	for (k = 0; k<g->numEdges; k++)
	{
		scanf("%d%d", &i, &j);               //����i,j ��ͼ����i-->j
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = g->adjList[i].firstedge;   //ͷ�巨�����߱�
		g->adjList[i].firstedge = e;
		/*���Ϊ����ͼ����������´���
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

