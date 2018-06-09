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

//�����������Ļ����㷨
BTNode * BSTSearch(BTNode * bt, int key) {

	if (bt == NULL) {
	
		return NULL;
	}
	else {
	
		//���ڸ��ڵ��еĹؼ��֣����ҳɹ������عؼ������ڽ��ָ��
		if (bt->key == key) {
			
			return bt;
		}
		else if(key<bt->key)
		{
			//С�ڸ��ڵ��еĹؼ���ʱ�͵��������в���
			return BSTSearch(bt->lchild, key);
		}
		else {
			
			//���ڸ��ڵ��еĹؼ���ʱ�͵��������в���
			return BSTSearch(bt->rchild, key);
		}
	}


}