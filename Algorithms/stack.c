//
// Created by 666 on 2021/7/4.
//

#include "stack.h"
#include <stddef.h>
#include <stdlib.h>
#include "error.h"

struct NodeStack {
    ElementTypeStack Element;
    PtrToNodeStack Next;
};

bool IsEmptyStack(Stack S) {
    return S->Next == NULL;
}

Stack CreateStack(void) {
    Stack S;

    S = malloc(sizeof(struct NodeStack));
    if(S == NULL) {
        FatalError("Out of space");
    }
    S->Next = NULL;
    MakeEmptyStack(S);
    return S;
}

void DisposeStack(Stack S) {
    if(S != NULL) {
        while (!IsEmptyStack(S)) {
            PopStack(S);
        }
        free(S);
    }
}

void MakeEmptyStack(Stack S) {
    if(S == NULL) {
        FatalError("Must use CreateStack first");
    } else {
        while (!IsEmptyStack(S)) {
            PopStack(S);
        }
    }
}

void PushStack(ElementTypeStack X, Stack S) {
    PtrToNodeStack TmpCell;

    TmpCell = malloc(sizeof(struct NodeStack));
    if(TmpCell == NULL) {
        FatalError("Out of space");
    } else {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementTypeStack TopStack(Stack S) {
    if(!IsEmptyStack(S)) {
        return S->Next->Element;
    }
    FatalError("Empty stack");
    return 0;
}

void PopStack(Stack S) {
    PtrToNodeStack FirstCell;

    if(IsEmptyStack(S)) {
        FatalError("Empty stack");
    } else {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}

