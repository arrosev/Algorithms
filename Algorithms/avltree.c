//
// Created by 陈鑫亮 on 2021/7/10.
//

#include "avltree.h"
#include <stddef.h>
#include <stdlib.h>
#include "error.h"
#include "utility.h"

struct AvlNode {
    AvlTreeElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

AvlTree MakeEmptyAvlTree(AvlTree T) {
    if(T->Left != NULL) {
        MakeEmptyAvlTree(T->Left);
    }

    if(T->Right != NULL) {
        MakeEmptyAvlTree(T->Right);
    }

    free(T);
    T = NULL;
    return T;
}

AvlTreePosition FindAvlTree(AvlTreeElementType X, AvlTree T) {
    if(T == NULL) {
        return NULL;
    }
    if(X < T->Element) {
        return FindAvlTree(X, T->Left);
    } else if(X > T->Element) {
        return FindAvlTree(X, T->Right);
    } else {
        return T;
    }
}

AvlTreePosition FindMinAvlTree(AvlTree T) {
    if(T == NULL) {
        return NULL;
    } else if(T->Left == NULL) {
        return T;
    } else {
        return FindMinAvlTree(T->Left);
    }
}

AvlTreePosition FindMaxAvlTree(AvlTree T) {
    if(T != NULL) {
        while (T->Right != NULL) {
            T = T->Right;
        }
    }
    return T;
}

int AvlTreeHeight(AvlTreePosition P) {
    if(P == NULL) {
        return -1;
    } else {
        return P->Height;
    }
}

static AvlTreePosition SingleRotateWithLeft(AvlTreePosition K2) {
    AvlTreePosition K1;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max(AvlTreeHeight(K2->Left), AvlTreeHeight(K2->Right)) + 1;
    K1->Height = Max(AvlTreeHeight(K1->Left), K2->Height) + 1;

    return K1;
}

static AvlTreePosition SingleRotateWithRight(AvlTreePosition K1) {
    AvlTreePosition K2;

    K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;

    K1->Height = Max(AvlTreeHeight(K1->Left), AvlTreeHeight(K1->Right)) + 1;
    K2->Height = Max(K1->Height, AvlTreeHeight(K2->Right)) + 1;

    return K2;
}

static AvlTreePosition DoubleRotateWithLeft(AvlTreePosition K3) {
    K3->Left = SingleRotateWithRight(K3->Left);

    return SingleRotateWithLeft(K3);
}

static AvlTreePosition DoubleRotateWithRight(AvlTreePosition K1) {
    K1->Right = SingleRotateWithLeft(K1->Right);

    return SingleRotateWithRight(K1);
}

AvlTree InsertAvlTree(AvlTreeElementType X, AvlTree T) {
    if(T == NULL) {
        T = malloc(sizeof(struct AvlNode));
        if(T == NULL) {
            FatalError("Out of space!!!");
        } else {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
    } else if(X < T->Element) {
        T->Left = InsertAvlTree(X, T->Left);
        if(AvlTreeHeight(T->Left) - AvlTreeHeight(T->Right) == 2) {
            if(X < T->Left->Element) {
                T = SingleRotateWithLeft(T);
            } else {
                T = DoubleRotateWithLeft(T);
            }
        }
    } else if(X > T->Element) {
        T->Right = InsertAvlTree(X, T->Right);
        if(AvlTreeHeight(T->Right) - AvlTreeHeight(T->Left) == 2) {
            if(X > T->Right->Element) {
                T = SingleRotateWithRight(T);
            } else {
                T = DoubleRotateWithRight(T);
            }
        }
    } else {

    }

    T->Height = Max(AvlTreeHeight(T->Left), AvlTreeHeight(T->Right)) + 1;
    return T;
}

//删除看的不是很懂，先放着吧。
AvlTree DeleteAvlTree(AvlTreeElementType X, AvlTree T) {
    AvlTreePosition TmpCell;
    if(T == NULL) {
        FatalError("Element not found");
    } else if(X < T->Element) {
        T->Left = DeleteAvlTree(X, T->Left);
        if (AvlTreeHeight(T->Right) - AvlTreeHeight(T->Left) == 2) {
            //T节点失去平衡
            if (AvlTreeHeight(T->Right->Left) > AvlTreeHeight(T->Right->Right)) {
                DoubleRotateWithRight(T);//RL情形
            } else {
                SingleRotateWithRight(T);//RR情形
            }
        }
    } else if(X > T->Element) {
        T->Right = DeleteAvlTree(X, T->Right);
        if (AvlTreeHeight(T->Left) - AvlTreeHeight(T->Right) == 2) {
            //T节点失去平衡
            if (AvlTreeHeight(T->Left->Right) > AvlTreeHeight(T->Left->Left)) {
                DoubleRotateWithLeft(T);//LR情形
            }
            else {
                SingleRotateWithLeft(T);//LL情形
            }
        }
    } else if(T->Left && T->Right) {
        TmpCell = FindMinAvlTree(T->Right);
        T->Element = TmpCell->Element;
        T->Right = DeleteAvlTree(T->Element, T->Right);
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

    T->Height = Max(AvlTreeHeight(T->Left), AvlTreeHeight(T->Right)) + 1;
    return T;
}

AvlTreeElementType RetrieveAvlTree(AvlTreePosition P) {
    if (P != NULL) {
        return P->Element;
    }
    return 0;
}