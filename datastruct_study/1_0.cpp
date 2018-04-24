#include <iostream>
using namespace std;

//int main() {
//	void f(int &x);
//	void f1(int *&x);
//	void swap1(int *p1, int *p2);
//	int a = 0;
//	int b = 1;
//	int * a1 = &a;
//	int * b1 = &b;
//	swap(a1, b1);
//	printf("%d,%d",*a1,*b1);
//}

//普通变量的引用型可以改变实参的值
void f(int &x) {
	x++;
}

//如果传入的变量是指针行变量，且在函数体内要对传入的值进行改变
//需要以下写法(指针的引用型)
void f1(int *&x) {
	int c = 3;
	x = &c;
}

/*
	该方法无法改变p1和p2的实参,但是可以修改
*/
void swap1(int *p1, int *p2) {
	int *p;
	p = p1;
	p1 = p2;
	p2 = p;
	
}

/*
	该方法可以改变实参p1和p2
*/
void swap2(int *&p1, int *&p2) {
	int *p;
	p = p1;
	p1 = p2;
	p2 = p;

}

