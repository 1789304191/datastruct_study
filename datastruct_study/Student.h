
#ifndef _STUDENT_H_

#define _STUDENT_H_



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

#endif
