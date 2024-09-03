#include "stm32f10x.h"

int value(int x)
{
    return x;
}

int c = 3;

int main(void)
{
    int a = 2;
    const int b = 0;
    // a = 2;
    // a += 2;
    // value(a);
    value(b);
    return 0;
}

