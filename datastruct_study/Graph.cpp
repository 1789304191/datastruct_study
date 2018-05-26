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