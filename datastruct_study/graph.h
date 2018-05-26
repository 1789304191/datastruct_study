#ifndef _GRAPH_H_

#define _GRAPH_H_

#define  MAXSIZE 30

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

#endif
