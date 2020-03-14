//
// Created by jia on 2020/2/12.
//
#include <cstdio>
#include<ctime>

void RecurPrintN(int N) {
    if (N > 1) {
        RecurPrintN(N - 1);
    }
    printf("%d\n", N);
}

void LoopPrintN(int N) {
    if (N > 1) {
        LoopPrintN(N - 1);
    }
    printf("%d\n", N);
}

int main() {
    clock_t start, stop;
    double duration;
//    start = clock();
//    RecurPrintN(1000);
//    stop = clock();
//    duration = (double(stop - start)) / CLK_TCK;
//    printf("%lf\n", duration);
    printf("%d\n", CLK_TCK);
}




