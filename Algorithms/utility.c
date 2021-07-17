//
// Created by 陈鑫亮 on 2021/7/11.
//

#include "utility.h"
#include <stdbool.h>

int NextPrime (int N) {
    bool isPrime = false;
    while (!isPrime) {
        isPrime = true;
        N = N + 1;
        for (int i = 2; i*i <= N; i++) {
            if (N % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    return N;
}
