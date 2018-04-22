
#ifndef _STUDENT_H_

#define _STUDENT_H_

typedef struct DStudent DStudent;

typedef struct Student Student;


#define LENDS sizeof(struct DStudent)

#define LENS sizeof(struct Student)


//单链表结构体

struct Student {

	int num;

	float score;

	struct Student * next;

};

//双链表结构体

struct DStudent {

	int num;

	float score;

	//后继节点
	struct DStudent * next;
	//前驱节点
	struct DStudent * prior;
};

/*
数组的打印定义
*/
void print_array(int num[], int n);

/*
如果temp比上一个元素小，则移动一位，然后继续和下一个元素比较并且移动，直到大于
时就将此时的元素的下一个值赋值给temp
*/
void merge_sequence(int a[], int m, int n);

/*
	链表的创建
*/
struct Student * create();

/*
	链表的输出
*/
void print_(struct Student * p);

//链表插入排序（从小到大）
struct Student * insertionSortByAsc(struct Student * head);

//将两个链表用尾插法合并并按原来的顺序
void merge(struct Student * a, struct Student * b, struct Student *&c);

//创建带头节点的单链表
struct Student * createWithHead();

//带头节点链表插入排序（从小到大）
struct Student * insertionSortByAscWithHead(struct Student * head);

#endif
