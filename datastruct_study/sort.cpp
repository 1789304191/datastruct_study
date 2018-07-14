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
		//K+1��ʾ����������Ҫ�ж��������Ƿ񳬳����鷶Χ
		if (k + 1<high && R[k]<R[k + 1]) {
			k++;
		}

		//����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ㣨���ý��н�����
		if (R[k] >temp) {
			//��ֵ�����ڵ�
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

	//�����󶥶� n/2-1Ϊ��һ����Ҷ�ӽڵ�
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


//������������ȡֵΪ���Ĺؼ��ַ�������ȡ�Ǹ�ֵ�Ĺؼ���֮ǰ(�����ڿ�������)
void ReSort(int R[], int n) {

	int i = 0, j = n - 1;

	int temp;

	//��i��jָ�벻�غ�ʱ
	while (i < j) {
		
		while (i < j&&R[i] < 0) {

			//��R[i]<0ʱ��iǰ��һλ ����ɨ��
			i++;
		}

		//��ʱR[i]>=0
		temp = R[i];

		while (i < j&&R[j] >= 0) {
		
			//�����������������ɨ��
			j--;
		}

		//��ǰR[i]��ֵΪ��������ǰR[j]<0 ����֮�󣬴�i����һλ��ʼ�ж�
		//��j��ǰһλ���жϣ���i=jʱ����
		R[i++] = R[j]; 

		R[j--] = temp;
	
	}

}

//�����㷨page262
void countSort(int a[], int b[],int al,int bl) {
	
	for (int i = 0; i < al; i++) {
		
		int count = 0;

		for (int j = 0; j < al; j++) {
			
			if(a[i] > a[j] && a[i] != a[j]){
				
				count++;
			}
		
		}

		//�����aС����count�����ʹ���b��countλ��
		b[count] = a[i];
	}

}

//ð������
void bubbleSort(int a[], int al) {
	
	//����û�˴���
	for (int i = al-1; i >=0; i--) {

		for (int j = 0; j < i; j++) {

			if (a[j] > a[j + 1]) {
				
				int temp = a[j + 1];
				a[j+1] = a[j];
				a[j] = temp;
			}
			
		}
	
	}

}

//˫��ð���㷨
void bubbleSortTwoSide(int a[], int al) {
	//����ÿ�˴���
	for (int i = al - 1; i >= 0; i--) {
		
		

		//����
		for (int j = 0; j < i; j++) {

			if (a[j] > a[j + 1]) {

				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}

		}
		
		//����
		for (int j = i; j >=1; j--) {

			if (a[j] < a[j-1]) {

				int temp = a[j - 1];
				a[j-1] = a[j];
				a[j] = temp;
			}

		}

		if (i == al / 2) {

			break;
		}
			
	}

		

}

//�����ֱ�Ӳ��뷨
void linkDirectInsert(int array[], int n, OrderLink * &orderLink) {
	
	

	for (int i = 0; i < n; i++) {

		OrderLink * p = orderLink->next;
	
		//ͷ�ڵ�����
		if (p == NULL) {
		
			OrderLink * q = (OrderLink *)malloc(sizeof(OrderLink));

			q->num = array[i];

			orderLink->next = q;

			q->next = NULL;

			continue;
		}

		//������һ���ڵ�
		OrderLink * temp = orderLink;

		while (p!= NULL) {
			
			//�м����
			if (array[i]<p->num) {
				
				OrderLink * q = (OrderLink *)malloc(sizeof(OrderLink));

					q->num = array[i];

					q->next = p;

					temp->next = q;

					break;

			}

			
			//����������뵽���
			if (p->next == NULL) {

				OrderLink * q = (OrderLink *)malloc(sizeof(OrderLink));

				q->num = array[i];

				p->next = q;

				q->next = NULL;

				break;

			}

			temp = p;

			p = p->next;
		}

		

	}


}



