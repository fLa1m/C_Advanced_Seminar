#include <stdio.h>
#include <stdint.h>
uint32_t worker(uint32_t, unsigned int);
int main(int argc, char const *argv[])
{
    unsigned int k;
    uint32_t n, res;
    scanf("%u %u", &n, &k);
    res = worker(n, k);
    printf ("%u\n", res);
    return 0;
}

uint32_t worker (uint32_t n, unsigned int k)
{
    return n & (~(uint32_t)0 >> (32-k));
}