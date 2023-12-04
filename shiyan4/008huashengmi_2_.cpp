#include <iostream>
#include <stdio.h>

int n;
int peanut[1001];

void take() {
    // �������ǰ10��λ�ø�����ż������Ϊ1��0
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0)
            peanut[i] = 1; // jerry��ȡ������Ϊ1
        else
            peanut[i] = 0; // tom��ȡ������Ϊ0
    }

    // �ӵ�11��λ�ÿ�ʼ������ǰ������λ�õ�״̬��i-1��i-5��i-10����ȷ����ǰλ�õ�״̬
    for (int i = 11; i <= 1000; i++) {
        if (peanut[i - 1] == 1 && peanut[i - 5] == 1 && peanut[i - 10] == 1)
            peanut[i] = 0; // Tom��ȡ������Ϊ0
        else
            peanut[i] = 1; // Jerry��ȡ������Ϊ1
    }
}

int main() {
    take(); // �������peanut

    while (scanf("%d", &n) && n) {
        std::cout << peanut[n] << std::endl; // �������peanut�ж�Ӧλ�õ�ֵ
    }

    return 0;
}