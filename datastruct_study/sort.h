#ifndef _SORT_H_

#define _SORT_H_

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


#endif
