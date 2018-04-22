#include <iostream>
#include "Student.h"

int main() {
	struct Student * p = createWithHead();
	print_(p);
	return 0;
}