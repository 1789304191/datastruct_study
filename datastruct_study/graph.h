#ifndef _GRAPH_H_

#define _GRAPH_H_

#define  MAXSIZE 30

//边结构体
typedef struct AcrNode {
	//该边所指向的节点位置
	int adjvex; 

	//指向下一条边的指针
	struct AcrNode * nextArc;

	//该边的相关信息 如权值
	int info;

}AcrNode;

//顶点结构体
typedef struct VNode
{
	//顶点信息
	char data;

	//指向第一条边
	AcrNode * firstAcr;

}VNode;

//图的邻接表类型
typedef struct AGraph {
	
	//邻接表
	VNode adjList[MAXSIZE];

	//顶点数和边数
	int n, e;

};


#endif
