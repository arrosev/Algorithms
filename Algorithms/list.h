//
// Created by 陈鑫亮 on 2021/6/28.
//

#ifndef ALGORITHMS_LIST_H
#define ALGORITHMS_LIST_H
#include <stdbool.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

List MakeEmpty(List L);
bool IsEmpty(List L);
bool IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif //ALGORITHMS_LIST_H
