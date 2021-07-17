//
// Created by 陈鑫亮 on 2021/7/15.
//

#include "sephash.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "error.h"
#include "utility.h"

#define MinTableSize (1)
typedef unsigned int Index;

struct SepHashListNode {
    SepHashTableElementType Element;
    SepHashPosition Next;
};

typedef SepHashPosition List;

struct SepHashTbl {
    int TableSize;
    List *TheLists;
};

static Index Hash(const char *Key, int TableSize) {
    unsigned int HashVal = 0;

    while (*Key != '\0') {
        HashVal = (HashVal << 5) + *Key++;
    }

    return HashVal % TableSize;
}

SepHashTable InitializeSepHashTable(int TableSize) {
    SepHashTable H;

    if(TableSize < MinTableSize) {
        FatalError("Table size too small");
        return NULL;
    }

    H = malloc(sizeof(struct SepHashTbl));
    if(H == NULL) {
        FatalError("Out of space!!!");
    } else {
        H->TableSize = NextPrime(TableSize);
        H->TheLists = malloc(sizeof(List) * H->TableSize);
        if(H->TheLists == NULL) {
            FatalError("Out of space!!!");
        } else {
            for(int i = 0; i < H->TableSize; i++) {
                H->TheLists[i] = malloc(sizeof(struct SepHashListNode));
                if(H->TheLists[i] == NULL) {
                    FatalError("Out of space");
                } else {
                    H->TheLists[i]->Element = NULL;
                    H->TheLists[i]->Next = NULL;
                }
            }
        }
    }

    return H;
}

//H是拷贝自T的完全不同的指针，但和T指向相同的地址，free(H)和H = NULL只是将H和T指向的内存释放，并不会将T置NULL，T仍然指向那块内存
SepHashTable DestroySepHashTable(SepHashTable H) {
    if(H == NULL) {

    } else {
        for (int i = 0; i < H->TableSize; i++) {
            SepHashPosition P, Tmp;
            P = H->TheLists[i]->Next;
            H->TheLists[i]->Next = NULL;
            while (P != NULL) {
                Tmp = P->Next;
                free(P);
                P = Tmp;
            }
            free(H->TheLists[i]);
            H->TheLists[i] = NULL;
        }
        free(H->TheLists);
        H->TheLists = NULL;
        free(H);
        H = NULL;
    }
    return NULL;
}

SepHashPosition FindInSepHashTable(SepHashTableElementType Key, SepHashTable H) {
    if(H == NULL) {
        return NULL;
    }

    SepHashPosition P;
    List L;

    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;
    while (P != NULL && strcmp(P->Element, Key) != 0) {
        P = P->Next;
    }
    return P;
}

//H是拷贝自T的完全不同的指针，但和T指向相同的地址，因此插入不受影响
void InsertInSepHashTable(SepHashTableElementType Key, SepHashTable H) {
    SepHashPosition Pos, NewCell;
    List L;

    Pos = FindInSepHashTable(Key, H);
    if(Pos == NULL) {
        NewCell = malloc(sizeof(struct SepHashListNode));
        if(NewCell == NULL) {
            FatalError("Out of space!!!");
        } else {
            L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = Key;
            L->Next = NewCell;
        }
    }
}

SepHashTableElementType RetrieveSepHashTable(SepHashPosition P) {
    if (P != NULL) {
        return P->Element;
    }
    return NULL;
}

void PrintSepHashTable(SepHashTable H) {
    if(H == NULL) {

    } else {
        for (int i = 0; i < H->TableSize; i++) {
            SepHashPosition P;
            P = H->TheLists[i]->Next;
            while (P != NULL) {
                printf("Key:%d, Value:%s\n", i, P->Element);
                P = P->Next;
            }
        }
    }
}