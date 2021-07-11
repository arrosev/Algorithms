//
// Created by 陈鑫亮 on 2021/7/10.
//

#ifndef ALGORITHMS_AVLTREE_H
#define ALGORITHMS_AVLTREE_H

struct AvlNode;
typedef struct AvlNode *AvlTreePosition;
typedef struct AvlNode *AvlTree;
typedef int AvlTreeElementType;

AvlTree MakeEmptyAvlTree(AvlTree T);
AvlTreePosition FindAvlTree(AvlTreeElementType X, AvlTree T);
AvlTreePosition FindMinAvlTree(AvlTree T);
AvlTreePosition FindMaxAvlTree(AvlTree T);
int AvlTreeHeight(AvlTreePosition P);
AvlTree InsertAvlTree(AvlTreeElementType X, AvlTree T);
AvlTree DeleteAvlTree(AvlTreeElementType X, AvlTree T);
AvlTreeElementType RetrieveAvlTree(AvlTreePosition P);

#endif //ALGORITHMS_AVLTREE_H
