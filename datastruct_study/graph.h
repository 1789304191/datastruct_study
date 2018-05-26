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

}AGraph;

//图的深度优先搜索遍历 v是起点编号 算法，任取一个节点访问，然后检查这个顶点的所有
//临接顶点，递归访问其中未被访问过的顶点（连通图）
void DFS(AGraph * G, int v);

//图的广度优先搜索遍历（连通图）
void BFS(AGraph * G, int v, int visit[MAXSIZE]);

//对于非连通图的深度优先搜索遍历
void dfs(AGraph *g);

//对于非连通图的广度优先搜索遍历
void bfs(AGraph *g);

//求连通图中距离给定的顶点v的最远的一个顶点
//返回对象为最远的一个顶点的序号 v为给定的顶点的序号
int BFS(AGraph * G, int v);

//v为随机遍历的序号 vn为节点数，en为边数
void getNodeAndEdgeByDFS(AGraph * G, int v, int &vn, int &en);

//判断一个无向图是否是一个树，无向图是一棵树的条件是：1.连通。2.边数为顶点-1
int GisTree(AGraph * G);

//判断顶点i和顶点j之间是否有路径
int DFSTrave(AGraph * G, int i, int j);

#endif
