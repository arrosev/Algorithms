//
// Created by 陈鑫亮 on 2021/6/17.
//

#include "leetcode.h"
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int ans=0;
    while(x!=0)
    {
        int p=x%10;
        x/=10;
        if(ans>INT_MAX/10||ans<INT_MIN/10)
            return 0;
        ans=ans*10+p;
    }
    return ans;
}
