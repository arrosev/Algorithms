#include <stdio.h>
#include <math.h>
#include "leetcode.h"
#include "list.h"

int main() {

    List L = MakeEmpty(NULL);
    Insert(100, L, L);
    printf("%d", Retrieve(First(L)));

    return 0;
}
