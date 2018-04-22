#include <iostream>
#include "Student.h"

int main() {
	int a[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,6,7,8,9,10};
	//前m个元素有序
	int m = 15;
	//后n个元素有序
	int n = 5;
	merge_sequence(a, 15, 5);
	print_array(a, 20);
}


