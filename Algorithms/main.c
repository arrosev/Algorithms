#include <stdio.h>
#include <math.h>
#include "leetcode.h"
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "searchtree.h"

int main() {

//    Stack S = CreateStack();
//    PushStack(10, S);
//    PushStack(11, S);
//    printf("Top: %d\n", TopStack(S));
//    DisposeStack(S);
//    printf("Top: %d\n", TopStack(S));

//    Queue Q = CreateQueue(10);
//    printf("Front: %d\n", Front(Q));
//    Enqueue(1, Q);
//    Enqueue(2, Q);
//    Enqueue(3, Q);
//    Enqueue(4, Q);
//    Enqueue(5, Q);
//    Enqueue(6, Q);
//    Enqueue(7, Q);
//    Enqueue(8, Q);
//    Enqueue(9, Q);
//    Enqueue(10, Q);
//    printf("Front: %d\n", Front(Q));
//    Dequeue(Q);//弹出1
//    printf("Front: %d\n", Front(Q));//队列首位为2
//    printf("Front: %d\n", FrontAndDequeue(Q));//打印队列首位2并弹出2
//    printf("Front: %d\n", FrontAndDequeue(Q));
//    printf("Front: %d\n", FrontAndDequeue(Q));

    SearchTree T = NULL;
    //T = MakeEmptyTree(T);
    T = InsertTree(6, T);
    T = InsertTree(2, T);
    T = InsertTree(8, T);
    T = InsertTree(1, T);
    T = InsertTree(4, T);
    T = InsertTree(3, T);
    T = InsertTree(5, T);

    printf("Min: %d\n", RetrieveTree(FindMinTree(T)));
    printf("Max: %d\n", RetrieveTree(FindMaxTree(T)));

    T = DeleteTree(8, T);
    printf("Min: %d\n", RetrieveTree(FindMinTree(T)));
    printf("Max: %d\n", RetrieveTree(FindMaxTree(T)));

    return 0;
}
