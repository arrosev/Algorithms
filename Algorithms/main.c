#include <stdio.h>
#include <math.h>
#include "leetcode.h"
#include "list.h"
#include "stack.h"

int main() {

    Stack S = CreateStack();
    PushStack(10, S);
    PushStack(11, S);
    printf("Top: %d\n", TopStack(S));
    DisposeStack(S);
    printf("Top: %d\n", TopStack(S));

    return 0;
}
