//
// Created by 陈鑫亮 on 2021/7/5.
//

#ifndef ALGORITHMS_QUEUE_H
#define ALGORITHMS_QUEUE_H
#include <stdbool.h>

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementTypeQueue;

bool IsEmptyQueue(Queue Q);
bool IsFullQueue(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmptyQueue(Queue Q);
void Enqueue(ElementTypeQueue X, Queue Q);
ElementTypeQueue Front(Queue Q);
void Dequeue(Queue Q);
ElementTypeQueue FrontAndDequeue(Queue Q);

#endif //ALGORITHMS_QUEUE_H
