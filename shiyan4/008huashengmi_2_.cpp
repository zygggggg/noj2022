#include <iostream>
#include <stdio.h>

int n;
int peanut[1001];

void take() {
    // 将数组的前10个位置根据奇偶性设置为1或0
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0)
            peanut[i] = 1; // jerry先取，设置为1
        else
            peanut[i] = 0; // tom先取，设置为0
    }

    // 从第11个位置开始，根据前面三个位置的状态（i-1，i-5，i-10）来确定当前位置的状态
    for (int i = 11; i <= 1000; i++) {
        if (peanut[i - 1] == 1 && peanut[i - 5] == 1 && peanut[i - 10] == 1)
            peanut[i] = 0; // Tom先取，设置为0
        else
            peanut[i] = 1; // Jerry先取，设置为1
    }
}

int main() {
    take(); // 填充数组peanut

    while (scanf("%d", &n) && n) {
        std::cout << peanut[n] << std::endl; // 输出数组peanut中对应位置的值
    }

    return 0;
}