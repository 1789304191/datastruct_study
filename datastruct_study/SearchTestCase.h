#ifndef _SearchTestCase_H_

#define _SearchTestCase_H_


#include <iostream>
#include "search.h"

//初始化一个二叉排序树
BTNode * initBTNode();

//初始化一个带lsize值域的平衡二叉树
LBTNode * initLBTNode();

//初始化一个带统计相同关键字值节点个数的count
BTNodeWithCount * initBTNodeWithCount();
#endif