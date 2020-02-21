//
// Created by jia on 2020/2/12.
//
#include <cstdio>

/**
 * 递归基本原理
 * 1 每一级函数调用都有自己的变量，也就是说，第1级的n和第2级的n不同，所以程序创建了4个单独的变量，
 * 每个变量名都是n，但是他们的值各不相同
 */

void up_and_down(int);

int main() {
    up_and_down(1);
    return 0;
}

void up_and_down(int n) {
    printf("Level %d: n location %p\n", n, &n);
    if (n < 4) {
        up_and_down(n + 1);
    }
    printf("LEVEL %d: n location %p\n", n, &n);
}

