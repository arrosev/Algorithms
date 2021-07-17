#include <stdio.h>
#include <math.h>
#include "leetcode.h"
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "searchtree.h"
#include "avltree.h"
#include "utility.h"
#include "sephash.h"

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

//    SearchTree T = NULL;
//    T = InsertTree(6, T);
//    T = InsertTree(2, T);
//    T = InsertTree(8, T);
//    T = InsertTree(1, T);
//    T = InsertTree(4, T);
//    T = InsertTree(3, T);
//    T = InsertTree(5, T);
//
//    printf("Min: %d\n", RetrieveTree(FindMinTree(T)));
//    printf("Max: %d\n", RetrieveTree(FindMaxTree(T)));
//
//    T = DeleteTree(8, T);
//    printf("Min: %d\n", RetrieveTree(FindMinTree(T)));
//    printf("Max: %d\n", RetrieveTree(FindMaxTree(T)));
//    T = MakeEmptyTree(T);
//    printf("Max: %d\n", RetrieveTree(FindMaxTree(T)));

//    AvlTree T = NULL;
//    T = InsertAvlTree(6, T);
//    T = InsertAvlTree(2, T);
//    T = InsertAvlTree(8, T);
//    T = InsertAvlTree(1, T);
//    T = InsertAvlTree(4, T);
//    T = InsertAvlTree(3, T);
//    T = InsertAvlTree(5, T);
//    T = InsertAvlTree(7, T);
//
//    printf("Min: %d\n", RetrieveAvlTree(FindMinAvlTree(T)));
//    printf("Max: %d\n", RetrieveAvlTree(FindMaxAvlTree(T)));
//    printf("Height: %d\n", AvlTreeHeight(T));
//    printf("T root Element: %d\n", RetrieveAvlTree(T));


//    printf("下一个素数: %d", NextPrime(7));

    SepHashTable T = InitializeSepHashTable(10);

    InsertInSepHashTable("Hello", T);
    InsertInSepHashTable("A", T);
    InsertInSepHashTable("Rose", T);

    PrintSepHashTable(T);

    printf("%s\n", RetrieveSepHashTable(FindInSepHashTable("A", T)));
    printf("%s\n", RetrieveSepHashTable(FindInSepHashTable("Worlds", T)));

    T = DestroySepHashTable(T);

    printf("%s\n", RetrieveSepHashTable(FindInSepHashTable("A", T)));


    return 0;
}
