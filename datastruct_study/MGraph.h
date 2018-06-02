#ifndef _MGRAPH_H_

#define _MGRAPH_H_


#include <iostream>
#include "graph.h"

//初始化一个邻接矩阵
MGragh * initDijkstra();

//初始化弗洛伊德算法所使用的矩阵
MGragh * initFloyd();

//初始化拓扑排序所需的邻接表
AGraph * initTopSort();

#endif
