//
// Created by 陈鑫亮 on 2021/6/28.
//

#include "list.h"
#include <stddef.h>
#include <stdlib.h>
#include "error.h"

struct Node {
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L) {
    if (L != NULL) {
        DeleteList(L);
    }
    L = (List)malloc(sizeof(struct Node));
    if (L == NULL) {
        FatalError("Out of space!!!");
    }
    L->Next = NULL;
    return L;
}

bool IsEmpty(List L) {
    return L->Next == NULL;
}

bool IsLast(Position P, List L) {
    return P->Next == NULL;
}

Position Find(ElementType X, List L) {
    Position P;

    P = L->Next;
    while (P != NULL && P->Element != X) {
        P = P->Next;
    }
    return P;
}

Position FindPrevious(ElementType X, List L) {
    Position P;

    P = L;
    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P;
}

void Delete(ElementType X, List L) {
    Position P, TmpCell;

    P = FindPrevious(X, L);
    if(!IsLast(P, L)) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

void Insert(ElementType X, List L, Position P) {
    Position TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL) {
        FatalError("Out of space!!!");
    } else {
        TmpCell->Element = X;
        TmpCell->Next = P->Next;
        P->Next = TmpCell;
    }
}

void DeleteList(List L) {
    Position P, Tmp;

    P = L->Next;
    L->Next = NULL;
    while (P != NULL) {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

Position Header(List L) {
    return L;
}

Position First(List L) {
    return L->Next;
}

Position Advance(Position P) {
    return P->Next;
}

ElementType Retrieve(Position P) {
    return P->Element;
}


