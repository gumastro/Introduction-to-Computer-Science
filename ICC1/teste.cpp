#include <cstdio>

	int bitXor(int x, int y) 
{
    int a = x & y;
    int b = ~x & ~y;
    int z = ~a & ~b;
    printf("%d", z);
    return z;
}    

