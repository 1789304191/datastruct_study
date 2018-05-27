#ifndef _GRAPH_H_

#define _GRAPH_H_

#define  MAXSIZE 30

//*******�ڽӱ�*******************************//

//�߽ṹ��
typedef struct AcrNode {
	//�ñ���ָ��Ľڵ�λ��
	int adjvex; 

	//ָ����һ���ߵ�ָ��
	struct AcrNode * nextArc;

	//�ñߵ������Ϣ ��Ȩֵ
	int info;

}AcrNode;

//����ṹ��
typedef struct VNode
{
	//������Ϣ
	char data;

	//ָ���һ����
	AcrNode * firstAcr;

}VNode;

//ͼ���ڽӱ�����
typedef struct AGraph {
	
	//�ڽӱ�
	VNode adjList[MAXSIZE];

	//�������ͱ���
	int n, e;

}AGraph;

//*******�ڽӾ���*******************************//
//��������
typedef struct VertexType {
	//������
	int no;
	//����������Ϣ
	char info;
}VertexType;

//ͼ�Ķ���
typedef struct MGragh{

	//edges[i][j]=1��ʾ����i�Ͷ���j�ڽӣ�=0��ʾ���ڽ� �������Ȩֵ��Ȩֵ�滻1
	int edges[MAXSIZE][MAXSIZE];

	//�������ͱ���
	int n, e;

	//��Žڵ���Ϣ
	VertexType vex[MAXSIZE];

}MGragh;

typedef struct Road{

	//a��bΪһ������������������
	int a, b;

	//�ߵ�Ȩֵ
	int w;

}Road;

//ͼ����������������� v������� �㷨����ȡһ���ڵ���ʣ�Ȼ����������������
//�ٽӶ��㣬�ݹ��������δ�����ʹ��Ķ��㣨��ͨͼ��
void DFS(AGraph * G, int v);

//ͼ�Ĺ������������������ͨͼ��
void BFS(AGraph * G, int v, int visit[MAXSIZE]);

//���ڷ���ͨͼ�����������������
void dfs(AGraph *g);

//���ڷ���ͨͼ�Ĺ��������������
void bfs(AGraph *g);

//����ͨͼ�о�������Ķ���v����Զ��һ������
//���ض���Ϊ��Զ��һ���������� vΪ�����Ķ�������
int BFS(AGraph * G, int v);

//vΪ������������ vnΪ�ڵ�����enΪ����
void getNodeAndEdgeByDFS(AGraph * G, int v, int &vn, int &en);

//�ж�һ������ͼ�Ƿ���һ����������ͼ��һ�����������ǣ�1.��ͨ��2.����Ϊ����-1
int GisTree(AGraph * G);

//�ж϶���i�Ͷ���j֮���Ƿ���·��
int DFSTrave(AGraph * G, int i, int j);

//ͼ��С����������������ķ�㷨
void Prim(MGragh g, int v0, int &sum);

//ͼ����С��������������³˹�����㷨 roadΪ�� sumΪȨֵ gΪ�ڽӾ���
void Kruskal(MGragh g, int &sum, Road * road[]);

//�������˫�ױ�ʾ���в��Ҹ��ڵ�ĺ���
int getRoot(int a);

//��³˹�����㷨�����õ��ı߸���Ȩֵ���� roadΪ�ߣ�eΪ�ߵ�����
void sortEdges(Road * road[], int E);

//˫�׽ڵ�洢�ṹ���������
void printfPath(int path[], int a);

#endif
