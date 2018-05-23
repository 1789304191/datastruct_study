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

};


#endif
