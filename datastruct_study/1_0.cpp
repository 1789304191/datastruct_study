#include <iostream>
using namespace std;

//int main() {
//	void f(int &x);
//	void f1(int *&x);
//	int a = 0;
//	int * b = &a;
//	f1(b);
//	printf("%d",a);
//}

//普通变量的引用型可以改变实参的值
void f(int &x) {
	x++;
}

//如果传入的变量是指针行变量，且在函数体内要对传入的值进行改变
//需要以下写法(指针的引用型)
void f1(int *&x) {
	*x = 2;
}

