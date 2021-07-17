//
// Created by 陈鑫亮 on 2021/7/15.
//

#ifndef ALGORITHMS_SEPHASH_H
#define ALGORITHMS_SEPHASH_H

struct SepHashListNode;
typedef struct SepHashListNode *SepHashPosition;
struct SepHashTbl;
typedef struct SepHashTbl *SepHashTable;
typedef char* SepHashTableElementType;

SepHashTable InitializeSepHashTable(int TableSize);
SepHashTable DestroySepHashTable(SepHashTable H);
SepHashPosition FindInSepHashTable(SepHashTableElementType Key, SepHashTable H);
void InsertInSepHashTable(SepHashTableElementType Key, SepHashTable H);
SepHashTableElementType RetrieveSepHashTable(SepHashPosition P);

void PrintSepHashTable(SepHashTable H);

#endif //ALGORITHMS_SEPHASH_H
