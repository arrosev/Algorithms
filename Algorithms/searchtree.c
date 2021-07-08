//
// Created by 陈鑫亮 on 2021/7/8.
//

#include "searchtree.h"
#include <stddef.h>
#include <stdlib.h>
#include "error.h"

struct TreeNode {
    TreeElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmptyTree(SearchTree T) {
    if(T != NULL) {
        MakeEmptyTree(T->Left);
        MakeEmptyTree(T->Right);
        free(T);
    }
    return NULL;
}

TreePosition FindTree(TreeElementType X, SearchTree T) {
    if(T == NULL) {
        return NULL;
    }
    if(X < T->Element) {
        return FindTree(X, T->Left);
    } else if(X > T->Element) {
        return FindTree(X, T->Right);
    } else {
        return T;
    }
}

TreePosition FindMinTree(SearchTree T) {
    if(T == NULL) {
        return NULL;
    } else if(T->Left == NULL) {
        return T;
    } else {
        return FindMinTree(T->Left);
    }
}

TreePosition FindMaxTree(SearchTree T) {
    if(T != NULL) {
        while (T->Right != NULL) {
            T = T->Right;
        }
    }
    return T;
}

SearchTree InsertTree(TreeElementType X, SearchTree T) {
    if(T == NULL) {
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL) {
            FatalError("Out of space!!!");
        } else {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    } else if(X < T->Element) {
        T->Left = InsertTree(X, T->Left);
    } else if(X > T->Element) {
        T->Right = InsertTree(X, T->Right);
    } else {

    }
    return T;
}

SearchTree DeleteTree(TreeElementType X, SearchTree T) {
    TreePosition TmpCell;
    if(T == NULL) {
        FatalError("Element not found");
    } else if(X < T->Element) {
        T->Left = DeleteTree(X, T->Left);
    } else if(X > T->Element) {
        T->Right = DeleteTree(X, T->Right);
    } else if(T->Left && T->Right) {
        TmpCell = FindMinTree(T->Right);
        T->Element = TmpCell->Element;
        T->Right = DeleteTree(T->Element, T->Right);
    } else {
        TmpCell = T;
        if(T->Left == NULL) {
            T = T->Right;
        } else if(T->Right == NULL) {
            T = T->Left;
        } else {

        }
        free(TmpCell);
    }
    return T;
}

TreeElementType RetrieveTree(TreePosition P) {
    return P->Element;
}