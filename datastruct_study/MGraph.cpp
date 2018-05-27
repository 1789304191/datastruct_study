#include <iostream>
#include "MGraph.h"


//初始化一个邻接矩阵
MGragh * initDijkstra() {

	MGragh * dijkstra = (MGragh *)malloc(sizeof(MGragh));
	//顶点类型 7个顶点
	VertexType * Dvex0 = (VertexType *)malloc(sizeof(VertexType));
	VertexType * Dvex1 = (VertexType *)malloc(sizeof(VertexType));
	VertexType * Dvex2 = (VertexType *)malloc(sizeof(VertexType));
	VertexType * Dvex3 = (VertexType *)malloc(sizeof(VertexType));
	VertexType * Dvex4 = (VertexType *)malloc(sizeof(VertexType));
	VertexType * Dvex5 = (VertexType *)malloc(sizeof(VertexType));
	VertexType * Dvex6 = (VertexType *)malloc(sizeof(VertexType));
	VertexType * Dvex7 = (VertexType *)malloc(sizeof(VertexType));

	Dvex0->no = 0;
	Dvex1->no = 1;
	Dvex2->no = 2;
	Dvex3->no = 3;
	Dvex4->no = 4;
	Dvex5->no = 5;
	Dvex6->no = 6;

	//顶点信息
	dijkstra->vex[0] = *Dvex0;
	dijkstra->vex[1] = *Dvex1;
	dijkstra->vex[2] = *Dvex2;
	dijkstra->vex[3] = *Dvex3;
	dijkstra->vex[4] = *Dvex4;
	dijkstra->vex[5] = *Dvex5;
	dijkstra->vex[6] = *Dvex6;

	//边信息 假设顶点与顶点之前没有边则权值为100
	dijkstra->edges[0][0] = 100;
	dijkstra->edges[0][1] = 4;
	dijkstra->edges[0][2] = 6;
	dijkstra->edges[0][3] = 6;
	dijkstra->edges[0][4] = 100;
	dijkstra->edges[0][5] = 100;
	dijkstra->edges[0][6] = 100;

	dijkstra->edges[1][0] = 100;
	dijkstra->edges[1][1] = 100;
	dijkstra->edges[1][2] = 1;
	dijkstra->edges[1][3] = 100;
	dijkstra->edges[1][4] = 7;
	dijkstra->edges[1][5] = 100;
	dijkstra->edges[1][6] = 100;

	dijkstra->edges[2][0] = 100;
	dijkstra->edges[2][1] = 100;
	dijkstra->edges[2][2] = 100;
	dijkstra->edges[2][3] = 100;
	dijkstra->edges[2][4] = 6;
	dijkstra->edges[2][5] = 4;
	dijkstra->edges[2][6] = 100;

	dijkstra->edges[3][0] = 100;
	dijkstra->edges[3][1] = 100;
	dijkstra->edges[3][2] = 2;
	dijkstra->edges[3][3] = 100;
	dijkstra->edges[3][4] = 100;
	dijkstra->edges[3][5] = 5;
	dijkstra->edges[3][6] = 100;

	dijkstra->edges[4][0] = 100;
	dijkstra->edges[4][1] = 100;
	dijkstra->edges[4][2] = 100;
	dijkstra->edges[4][3] = 100;
	dijkstra->edges[4][4] = 100;
	dijkstra->edges[4][5] = 100;
	dijkstra->edges[4][6] = 6;

	dijkstra->edges[5][0] = 100;
	dijkstra->edges[5][1] = 100;
	dijkstra->edges[5][2] = 100;
	dijkstra->edges[5][3] = 100;
	dijkstra->edges[5][4] = 1;
	dijkstra->edges[5][5] = 100;
	dijkstra->edges[5][6] = 8;

	dijkstra->edges[6][0] = 100;
	dijkstra->edges[6][1] = 100;
	dijkstra->edges[6][2] = 100;
	dijkstra->edges[6][3] = 100;
	dijkstra->edges[6][4] = 100;
	dijkstra->edges[6][5] = 100;
	dijkstra->edges[6][6] = 6;

	//5个顶点 8个边
	dijkstra->n = 7;
	dijkstra->e = 12;

	return dijkstra;
}


//初始化弗洛伊德算法所使用的矩阵
MGragh * initFloyd() {
	
	MGragh * Floyd = (MGragh *)malloc(sizeof(MGragh));
	//顶点类型 4个顶点
	VertexType * Dvex0 = (VertexType *)malloc(sizeof(VertexType));
	VertexType * Dvex1 = (VertexType *)malloc(sizeof(VertexType));
	VertexType * Dvex2 = (VertexType *)malloc(sizeof(VertexType));
	VertexType * Dvex3 = (VertexType *)malloc(sizeof(VertexType));

	Dvex0->no = 0;
	Dvex1->no = 1;
	Dvex2->no = 2;
	Dvex3->no = 3;

	//顶点信息
	Floyd->vex[0] = *Dvex0;
	Floyd->vex[1] = *Dvex1;
	Floyd->vex[2] = *Dvex2;
	Floyd->vex[3] = *Dvex3;

	//边信息 假设顶点与顶点之前没有边则权值为100
	Floyd->edges[0][0] = 100;
	Floyd->edges[0][1] = 5;
	Floyd->edges[0][2] = 100;
	Floyd->edges[0][3] = 7;
	

	Floyd->edges[1][0] = 100;
	Floyd->edges[1][1] = 100;
	Floyd->edges[1][2] = 4;
	Floyd->edges[1][3] = 2;
	

	Floyd->edges[2][0] = 3;
	Floyd->edges[2][1] = 3;
	Floyd->edges[2][2] = 100;
	Floyd->edges[2][3] = 2;
	

	Floyd->edges[3][0] = 100;
	Floyd->edges[3][1] = 100;
	Floyd->edges[3][2] = 1;
	Floyd->edges[3][3] = 100;

	//5个顶点 8个边
	Floyd->n = 4;
	Floyd->e = 8;

	return Floyd;
}