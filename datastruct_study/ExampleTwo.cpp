#include <iostream>
#include "Student.h"

int main() {
	Student * p = createWithHead();
	//不能改变p的指，但是可以改变p的指向的值
	insertionSortByAscWithHead(p);
	print_(p);
	return 0;
}