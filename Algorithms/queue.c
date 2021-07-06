//
// Created by 陈鑫亮 on 2021/7/5.
//

#include "queue.h"
#include <stddef.h>
#include <stdlib.h>
#include "error.h"

#define MinQueueSize (5)

struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementTypeQueue *Array;
};

bool IsEmptyQueue(Queue Q) {
    return Q->Size == 0;
}

bool IsFullQueue(Queue Q) {
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements) {
    Queue Q;

    if(MaxElements < MinQueueSize) {
        FatalError("Queue size is too small");
    }

    Q = malloc(sizeof(struct QueueRecord));
    if(Q == NULL) {
        FatalError("Out of space");
        return NULL;
    }

    Q->Array = malloc(sizeof(ElementTypeQueue) * MaxElements);
    if(Q->Array == NULL) {
        FatalError("Out of space");
        return NULL;
    }
    Q->Capacity = MaxElements;
    MakeEmptyQueue(Q);

    return Q;
}

void DisposeQueue(Queue Q) {
    if(Q != NULL) {
        free(Q->Array);
        free(Q);
    }
}

void MakeEmptyQueue(Queue Q) {
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int Succ(int Value, Queue Q) {
    if(++Value == Q->Capacity) {
        Value = 0;
    }
    return Value;
}

void Enqueue(ElementTypeQueue X, Queue Q) {
    if(IsFullQueue(Q)) {
        FatalError("Full queue");
    } else {
        Q->Size ++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

ElementTypeQueue Front(Queue Q) {
    if(IsEmptyQueue(Q)) {
        FatalError("Empty queue");
        return 0;
    } else {
        return Q->Array[Q->Front];
    }
}

void Dequeue(Queue Q) {
    if(IsEmptyQueue(Q)) {
        FatalError("Empty queue");
    } else {
        Q->Size --;
        Q->Front = Succ(Q->Front, Q);
    }
}

ElementTypeQueue FrontAndDequeue(Queue Q) {
    if(IsEmptyQueue(Q)) {
        FatalError("Empty queue");
        return 0;
    } else {
        int front = Q->Array[Q->Front];
        Q->Size --;
        Q->Front = Succ(Q->Front, Q);
        return front;
    }
}
