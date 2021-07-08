//
// Created by 陈鑫亮 on 2021/7/8.
//

#ifndef ALGORITHMS_SEARCHTREE_H
#define ALGORITHMS_SEARCHTREE_H

struct TreeNode;
typedef struct TreeNode *TreePosition;
typedef struct TreeNode *SearchTree;
typedef int TreeElementType;

SearchTree MakeEmptyTree(SearchTree T);
TreePosition FindTree(TreeElementType X, SearchTree T);
TreePosition FindMinTree(SearchTree T);
TreePosition FindMaxTree(SearchTree T);
SearchTree InsertTree(TreeElementType X, SearchTree T);
SearchTree DeleteTree(TreeElementType X, SearchTree T);
TreeElementType RetrieveTree(TreePosition P);

#endif //ALGORITHMS_SEARCHTREE_H
