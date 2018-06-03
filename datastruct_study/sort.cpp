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


//ѡ������
void selectSort(int R[], int n) {
	
	int i, j, k;
	
	int temp;

	for (i = 0; i < n; ++i) {
		
		k = i;

		//��������������ѡ��С�ؼ���
		for (j = i + 1; j < n; ++j) {
			
			if (R[k] > R[j]) {
				
				k = j;
			}
		}

		//��С�ؼ������������е�һ���ؼ��ֽ���
		temp = R[i];
		R[i] = R[k];
		R[k] = temp;
	
	}

	printArray(8, R);
}


/*
�ú��������ǽ����е���Ϊ�󶥶ѡ�lowΪ��һ����Ҷ�ӽڵ�Ķ���
highΪ����Ԫ����������ÿһ����Ҷ�ӽڵ�ѭ������������Ի�ô󶥶�
��һ����Ҷ�ӽڵ�Ϊn/2-1 ��������Ϊ�������2i+1,������Ϊ2i+2
*/
void sift(int R[], int i, int high) {

	//��ȡ����ǰԪ��i
	int temp = R[i];

	//��i�������ӽ�㿪ʼ��Ҳ����2i+1����ʼ
	for (int k = i * 2 + 1; k<high; k = k * 2 + 1) {

		//������ӽ��С�����ӽ�㣬kָ�����ӽ��
		if (k + 1<high && R[k]<R[k + 1]) {
			k++;
		}

		//����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ㣨���ý��н�����
		if (R[k] >temp) {
			R[i] = R[k];
			i = k;
		}
		else {
			break;
		}
	}
	//��tempֵ�ŵ����յ�λ��
	R[i] = temp;

}

//��������
void heapSort(int R[], int n) {
	
	int i;
	int temp;

	//�����󶥶�
	for (i = n / 2 - 1; i >= 0; i--) {
		
		//ѭ����Ҷ�ӽڵ�
		sift(R, i, n);
	}

	for (i = n-1; i > 0; i--) {
		
		//���ɸ��ڵ�Ĺؼ��֣������������λ��
		temp = R[0];
		R[0] = R[i];

		//R[n]Ϊ��������Ԫ��
		R[i] = temp;

		//�ڼ�����һ���ؼ��ֵ����������н��е���
		//��Ϊֵ���ڵ㲻���ϴ󶥶ѵĹ�������ֻ��Ҫ�Ը��ڵ���е���
		sift(R, 0, i);
	}

}