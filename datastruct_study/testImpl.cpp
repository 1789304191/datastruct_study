#include <iostream>
#include "childsiblings.h"

///* �ҳ�Ҷ�ӽڵ� */
//int countLeaves(TNode * root) {
//
//	if (root == NULL) {
//		return 0;
//	}
//	//��ʱ˵����Ҷ�ӽڵ�
//	if (root->firstchild == NULL) {
//		return 1 + countLeaves(root->nextsibling);
//	}
//	else {
//		return countLeaves(root->firstchild) + countLeaves(root->nextsibling);
//	}
//}
