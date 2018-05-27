#include <iostream>
#include "graph.h"
#include "print.h"

int visited[MAXSIZE];

//图的遍历 v是起点编号 算法，任取一个节点访问，然后检查这个顶点的所有
//临接顶点，递归访问其中未被访问过的顶点（连通图）
void DFS(AGraph * G, int v) {

	//边节点定义
	AcrNode *p;

	//将v节点置为已访问
	visited[v] = 1;
	
	//访问该节点的顶点
	printf("%c", G->adjList[v].data);

	//p指向顶点v的第一条边
	p = G->adjList[v].firstAcr;

	while (p != NULL) {
		
		//如果该条边的顶点的序号没有被访问过，则递归访问
		if (visited[p->adjvex] == 0) {

			DFS(G, p->adjvex);
			
		}
		//p指向下一条边的终点
		p = p->nextArc;
	}
}

//图的广度优先搜索遍历(连通图)
void BFS(AGraph * G, int v, int visit[MAXSIZE]) {
	
	AcrNode *p;
	
	//队列初始化 头指针，尾指针为0
	int que[MAXSIZE], front = 0, rear = 0;

	int j;

	//访问 并置为已访问
	printf("%c", G->adjList[v].data);

	visit[v] = 1;

	//当前顶点v进队
	rear = (rear + 1) % MAXSIZE;
	que[rear] = v;

	//队空的时候说明遍历已经完成
	while (front != rear) {
		
		//顶点出队
		front = (front + 1) % MAXSIZE;

		//把出队顶点赋值给j
		j = que[front];

		//p指向出队顶点j的第一条边
		p = G->adjList[j].firstAcr;

		//将p的所有邻接点中未被访问的顶点入队
		while (p!=NULL) {
			
			//当前节点未被访问，则进队
			if (visit[p->adjvex] == 0) {

				//先访问并标记为已访问
				printf("%c", G->adjList[p->adjvex].data);
				visit[p->adjvex] = 1;
				
				//该顶点进队
				rear = (rear + 1) % MAXSIZE;
				que[rear] = p->adjvex;

			}
			//p指向j的下一条边
			p = p->nextArc;
		}
	}
}

//对于非连通图的深度优先搜索遍历
void dfs(AGraph *g) {

	//用i表示每个顶点
	int i;

	//循环遍历
	for (i = 0; i < g->n; i++) {
		//如果该节点没有被访问过
		if (visited[i] == 0) {

			DFS(g,i);
		}
	}

}

//对于非连通图的广度优先搜索遍历
void bfs(AGraph *g) {
	
	//用i表示每个顶点
	int i;

	//循环遍历
	for (i = 0; i < g->n; i++) {
		//如果该节点没有被访问过
		if (visited[i] == 0) {

			BFS(g, i, visited);
		}
	}
}


//求连通图中距离给定的顶点v的最远的一个顶点
//返回对象为最远的一个顶点的序号 v为给定的顶点的序号
//根据广度遍历的原理，实际上是求最后一个出队的元素
int BFS(AGraph * G, int v) {
	
	AcrNode *p;

	//队列初始化 头指针，尾指针为0
	int que[MAXSIZE], front = 0, rear = 0;

	int j;

	//访问 并置为已访问
	printf("%c", G->adjList[v].data);

	visited[v] = 1;

	//当前顶点v进队
	rear = (rear + 1) % MAXSIZE;
	que[rear] = v;

	//队空的时候说明遍历已经完成
	while (front != rear) {

		//顶点出队
		front = (front + 1) % MAXSIZE;

		//把出队顶点赋值给j
		j = que[front];

		//p指向出队顶点j的第一条边
		p = G->adjList[j].firstAcr;

		//将p的所有邻接点中未被访问的顶点入队
		while (p != NULL) {

			//当前节点未被访问，则进队
			if (visited[p->adjvex] == 0) {

				//先访问并标记为已访问
				printf("%c", G->adjList[p->adjvex].data);
				visited[p->adjvex] = 1;

				//该顶点进队
				rear = (rear + 1) % MAXSIZE;
				que[rear] = p->adjvex;

			}
			//p指向j的下一条边
			p = p->nextArc;
		}
	}

	//最后一个出队的元素
	return j;
}


//判断一个无向图是否是一个树，无向图是一棵树的条件是：1.连通。2.边数为顶点-1
//v为随机遍历的序号 vn为节点数，en为边数（用深度优先算法）
void getNodeAndEdgeByDFS(AGraph * G, int v, int &vn, int &en) {
	
	AcrNode *p;

	//访问v顶点
	visited[v] = 1;
	
	//顶点数+1
	++vn;

	p = G->adjList[v].firstAcr;

	while (p != NULL) {
		
		//边数+1
		++en;
	
		//如果访问过了只增加边数
		if (visited[p->adjvex]==0) {

			getNodeAndEdgeByDFS(G, p->adjvex, vn, en);
		}

		p = p->nextArc;
	}
}

//判断一个无向图是否是一个树，无向图是一棵树的条件是：1.连通。2.边数为顶点-1
int GisTree(AGraph * G) {
	//顶点数和边数为0
	int vn = 0, en = 0;
	//计算顶点数和边数
	getNodeAndEdgeByDFS(G, 0, vn, en);
	//如果访问过的顶点数和图中的顶点数相等说明连通
	//并且边数等于顶点数-1 en/2是因为无向图边数实际统计了两次
	if (vn == G->n && (G->n - 1) == en / 2) {
		return 1;
	}
	else {
		return 0;
	}
}

//判断顶点i和顶点j之间是否有路径
int DFSTrave(AGraph * G, int i, int j) {
	
	//进行深度优先搜索遍历，如果j被访问了，说明有路径
	DFS(G, i);

	if (visited[j] == 0) {
		return 0;
	}
	else {
		return 1;
	}

}

//图最小代价生成树，普里姆算法 g为图，v0表示某一顶点 求sum为最小生成树代价
void Prim(MGragh g, int v0, int &sum) {
	
	//lowcost为存放当前生成树到剩余各顶点的最短边的权值
	//如3顶点032构成的树，其到顶点1的权值最小为3，所以lowcost[1]=3
	//vset[i]=1表示i顶点已经被并入到树中，=0表示没有
	int lowcost[MAXSIZE], vset[MAXSIZE], v;

	int i, j, k, min;

	v = v0;

	for (i = 0; i < g.n; i++) {
		
		//这一句是为了计算顶点v0生成树到各顶点的权值
		lowcost[i] = g.edges[v0][i];

		//节点还未并入树中
		vset[i] = 0;
	}

	//将v0并入树中
	vset[v0] = 1;

	//sum清零用来累计数的权值
	sum = 0;

	for (i = 0; i < g.n - 1; i++) {

		//MAXSIZE当做是一个比图中所有权值都大的常量
		min = MAXSIZE;

		//该循环用于选出候选边中的权值最小值
		for (j = 0; j < g.n; j++) {
			
			//选出当前生成树到其余顶点最短边中最短的一条 并且还未并入到树中
			if (vset[j] == 0 && lowcost[j] < min) {

				//赋值最小值
				min = lowcost[j];
				
				//k即为即将并入树中的顶点
				k = j;
			}
		}

		//将求出的最小值的顶点并入树中
		vset[k] = 1;
		v = k;

		//这里用sum记录了最小生成树的权值
		sum += min;

		//下面这个循环以刚并入的顶点v为媒介更新候选边
		for (j = 0; j < g.n; j++) {
			
			//寻找没有并入的顶点并且顶点j到新并入的顶点v的权值如果小于
			//原来到v0的权值，那么就把顶点j到v的权值更新为j到这棵树的权值
			if (vset[j] == 0 && g.edges[v][j] < lowcost[j]) {

				//更新权值
				lowcost[j] = g.edges[v][j];
			}
		}
	}

}

Road road[MAXSIZE];

//定义并查集数组
int v[MAXSIZE];

//在并查集中查找根节点的函数
int getRoot(int a) {

	//在查找过程中a会不断变化，直到a=v[a]时，才是根节点
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


//普里姆算法中所用到的边根据权值排序法 road为边，e为边的条数
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

//图的最小代价生成树，克鲁斯卡尔算法 road为边 sum为权值 g为邻接矩阵
void Kruskal(MGragh g, int &sum, Road * road[]) {
	
	int i;

	int N, E, a, b;

	//n为顶点数
	N = g.n;

	//e为边数
	E = g.e;

	sum = 0;

	for (i = 0; i < N; i++) {
		//数的双亲节点表示法 v[i]=i表示i顶点的双亲等于自己
		v[i] = i;
	}

	//边按权值大小排序
	sortEdges(road,E);

	//循环边数取权值最小的边，判断边的两顶点是否有共同的双亲节点
	//如果有那么就会形成回路，则跳过本次循环
	for (i = 0; i < E; i++) {

		printf("边：%d-->%d,w=%d\n", road[i]->a, road[i]->b, road[i]->w);
		
		//a顶点的双亲节点
		a = getRoot(road[i]->a);

		//b顶点的双亲节点
		b = getRoot(road[i]->b);

		printf("根节点：%d，%d,w=%d\n", a, b, road[i]->w);

		//如果不是同一个根节点则ab边并入之后a节点的双亲节点为b
		if (a != b) {

			//a节点的双亲为v[b]
			v[a] = b;

			//计算权值
			sum += road[i]->w;
		}
	}

}