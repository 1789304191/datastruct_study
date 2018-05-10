#include <iostream>
#include "Matrix.h"

int main() {
	float a[4][4] = { 0,0,0,1,0,0,3,2,1,0,0,0,0,2,0,0 };
	float b[16][3];
	createTrimat(a, 4, 4, b);
	print(b);
}