#include <iostream>
#include "childsiblings.h"

///* 找出叶子节点 */
//int countLeaves(TNode * root) {
//
//	if (root == NULL) {
//		return 0;
//	}
//	//此时说明是叶子节点
//	if (root->firstchild == NULL) {
//		return 1 + countLeaves(root->nextsibling);
//	}
//	else {
//		return countLeaves(root->firstchild) + countLeaves(root->nextsibling);
//	}
//}
