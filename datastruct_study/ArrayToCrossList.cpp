#include <iostream>
#include "Matrix.h"

int main() {
	float a[4][4] = { 0,0,0,1,0,0,3,2,1,0,0,0,0,2,0,0 };
	CrossList M;
	ArrayToCrossList(a,4,4,5,M);
}