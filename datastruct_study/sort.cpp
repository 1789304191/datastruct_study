#include <iostream>
#include "sort.h"
#include "print.h"


//�������� ԭ��ÿ�˽�һ��������Ĺؼ��ְ�����ֵ�Ĵ�С���뵽
//�Ѿ��źõĲ����������е��ʵ�λ����
void insetSort(int R[], int n) {

	int i, j;

	int temp;

	for (i = 1; i < n; i++) {
		
		//��������Ĺؼ����ݴ���temp��
		temp = R[i];

		
		j = i - 1;

		//�������ѭ������˴Ӵ�����ؼ���֮ǰ�Ĺؼ��ֿ�ʼɨ��
		//������ڴ�����ؼ��֣������һλ
		while (j >= 0 && temp < R[j]) {
			
			R[j + 1] = R[j];

			--j;
		
		}

		//�ҵ�����λ�ã���temp���ݴ�Ĵ��������
		R[j + 1] = temp;
	
	}
	
	printArray(n,R);
}

//��������
void quickSort(int R[], int low,int high) {
	
	int temp;

	int i = low, j = high;

	if (low < high) {
		
		temp = R[low];

		//��i��j���ʱ˵����߱�iС���ұ߱�i��
		while (i < j) {
			
			//���������ҵ�һ��С��temp�Ĺؼ���
			while (j > i&&R[j] >= temp) {
			
				--j;
			}
			if (i < j) {
				
				//����temp���
				R[i] = R[j];
				++i;
			}
			
			//��������ɨ�裬�ҵ�һ������temp�Ĺؼ���
			while (i < j && R[i] < temp) {
				
				++i;
			}
			if (i < j) {
				
				R[j] = R[i];
				--j;
			}
		
		}
		//��temp��������λ��
		R[i] = temp;
		
		//�ݹ�Ķ�temp��ߵĹؼ��ֽ�������
		quickSort(R, low, i - 1);

		//�ݹ�Ķ�temp�ұߵĹؼ��ֽ�������
		quickSort(R, i+1, high);
	}

	
}