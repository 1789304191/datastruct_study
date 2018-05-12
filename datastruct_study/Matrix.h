#ifndef _Matrix_H_

#define _Matrix_H_

#define MAXSIZE 4

//ʮ��������ͨ�ڵ�
typedef struct OLNode{ 

	//�����к���
	int row,col;
	//ָ���ҷ��Ľڵ��ָ��
	OLNode * right;
	//ָ���·��ڵ��ָ��
	OLNode * down;
	//ϡ������е�ֵ
	float val;

} OLNode ;

typedef struct CrossList {

	//mΪϡ������������nΪϡ������������kΪϡ��������ж��ٷ�0Ԫ��
	int m, n,k;

	//ָ������ͷ�ڵ������ָ��
	OLNode * rhead, * chead;

} CrossList ;

//������Ԫ�� aΪϡ����� bΪ��Ԫ�� mΪ�����������nΪ���������
void createTrimat(float a[][MAXSIZE], int m, int n, float b[][3]);

//3Ԫ��Ĵ�ӡ
void print(float b[][3]);

//ϡ������ʮ������洢�ṹ��aΪϡ�����mΪ������nΪ������kΪ��0�ڵ�ĸ��� MΪͷ�ڵ�
void ArrayToCrossList(float a[][MAXSIZE],int m,int n,int k, CrossList &M);

#endif