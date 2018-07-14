#ifndef _SORT_H_

#define _SORT_H_

typedef struct OrderLink {

	int num;

	OrderLink * next;

}OrderLink;

//�������� ԭ��ÿ�˽�һ��������Ĺؼ��ְ�����ֵ�Ĵ�С���뵽
//�Ѿ��źõĲ����������е��ʵ�λ����
void insetSort(int R[], int n);

//��������
void quickSort(int R[], int low, int high);

//ѡ������
void selectSort(int R[], int n);


/*
�ú��������ǽ����е���Ϊ�󶥶ѡ�lowΪ��һ����Ҷ�ӽڵ�Ķ���
highΪ����Ԫ����������ÿһ����Ҷ�ӽڵ�ѭ������������Ի�ô󶥶�
��һ����Ҷ�ӽڵ�Ϊn/2-1 ��������Ϊ�������2i+1,������Ϊ2i+2
*/
void sift(int R[], int low, int high);

//��������
void heapSort(int R[], int n);

//������������ȡֵΪ���Ĺؼ��ַ�������ȡ�Ǹ�ֵ�Ĺؼ���֮ǰ(�����ڿ�������)
void ReSort(int R[], int n);

//�����㷨page262
void countSort(int a[], int b[],int al,int bl);

//ð������
void bubbleSort(int a[], int al);

//˫��ð���㷨
void bubbleSortTwoSide(int a[], int al);

//�����ֱ�Ӳ��뷨
void linkDirectInsert(int array[],int n, OrderLink *&orderLink);

#endif
