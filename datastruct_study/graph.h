#ifndef _GRAPH_H_

#define _GRAPH_H_

#define  MAXSIZE 30

//*******邻接表*******************************//

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

	//此句新增部分，count用来统计顶点的入度
	int count;

}VNode;

//图的邻接表类型
typedef struct AGraph {
	
	//邻接表
	VNode adjList[MAXSIZE];

	//顶点数和边数
	int n, e;

}AGraph;

//*******邻接矩阵*******************************//
//顶点类型
typedef struct VertexType {
	//顶点编号
	int no;
	//顶点其他信息
	char info;
}VertexType;

//图的定义
typedef struct MGragh{

	//edges[i][j]=1表示顶点i和顶点j邻接，=0表示不邻接 如果含有权值则将权值替换1
	int edges[MAXSIZE][MAXSIZE];

	//顶点数和边数
	int n, e;

	//存放节点信息
	VertexType vex[MAXSIZE];

}MGragh;

typedef struct Road{

	//a和b为一条边所连的两个顶点
	int a, b;

	//边的权值
	int w;

}Road;

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

//图最小代价生成树，普里姆算法
void Prim(MGragh g, int v0, int &sum);

//图的最小代价生成树，克鲁斯卡尔算法 road为边 sum为权值 g为邻接矩阵
void Kruskal(MGragh g, int &sum, Road * road[]);

//在数组的双亲表示法中查找根节点的函数
int getRoot(int a);

//克鲁斯卡尔算法中所用到的边根据权值排序法 road为边，e为边的条数
void sortEdges(Road * road[], int E);

//双亲节点存储结构的逆向输出 a为某一个叶子节点
void printfPath(int path[], int a);

//迪杰斯特拉算法 求某一个顶点到其余顶点的最短路径
void Dijkstra(MGragh g, int v,int dist[],int path[]);

//弗洛伊德算法，求图中任意两个顶点之间的最短路径
void Floyd(MGragh g, int path[][MAXSIZE]);

//输出通过弗洛伊德算法得出的两点之间的最短路径
void printPath(int u, int v, int path[][MAXSIZE]);

//拓扑排序核心算法
int TopSort(AGraph *G);

//判断邻接表方式存储的有向图是否存在由顶点vi到顶点vj的路径（使用广度优先遍历方法）
int BFS(AGraph *G, int vi, int vj);

//在有向图G中，如果r到G中的每个节点都有路径可达，则称节点r为G的根节点。
//可以通过深度优先遍历的方法，以r为起点进行深度优先遍历，若函数结束
//所有顶点都被访问，则r为根，如果要打印出所有根节点，可以对图中的每个顶点都调用一次dfs
void DFSForRoot(AGraph *G, int v);

//打印根节点
void print(AGraph *G);

//图的邻接表转换为邻接矩阵
MGragh * AGraphToMgraph(AGraph *G);

//自定义栈完成图的深度优先遍历
void DFS1(AGraph *g, int v);

#endif
