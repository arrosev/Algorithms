//
// Created by 666 on 2021/7/4.
//

#ifndef ALGORITHMS_STACK_H
#define ALGORITHMS_STACK_H
#include <stdbool.h>

struct NodeStack;
typedef struct NodeStack *PtrToNodeStack;
typedef PtrToNodeStack Stack;
typedef int ElementTypeStack;

extern bool IsEmptyStack(Stack S);
extern Stack CreateStack(void);
extern void DisposeStack(Stack S);
extern void MakeEmptyStack(Stack S);
extern void PushStack(ElementTypeStack X, Stack S);
extern ElementTypeStack TopStack(Stack S);
extern void PopStack(Stack S);

#endif //ALGORITHMS_STACK_H
