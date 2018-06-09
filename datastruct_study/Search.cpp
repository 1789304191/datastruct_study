#include <iostream>
#include "search.h"

//˳����ҷ�
int search(int a[], int n, int k) {
	
	int i;

	for (i = 1; i <= n; i++) {
	
		if (a[i] == k) {
			
			return i;
		}
	}

	return 0;

}


//�۰���ҷ�
int Bsearch(int R[], int low, int high, int k) {

	int mid;

	//���ӱ��ȴ��ڵ���1�ǽ���ѭ��
	while (low <= high) {
	
		//ȡ��ǰ����м�λ��
		mid = (low + high) / 2;
	
		//�ҵ��󷵻�Ԫ�ص�λ��
		if (R[mid] == k) {
			return mid;
		}
		else if(R[mid]>k)
		{
			//˵����Ҫ��R[low.....,mid-1]�в���
			high = mid - 1;
		}
		else {
			//˵����Ҫ��R[mid+1,....high]�в���
			low = mid + 1;
		}

	}

	return 0;
}