#include <stdio.h>
#include <stdint.h>

uint32_t worker(uint32_t);

int main(int argc, char const *argv[])
{
    uint32_t n, res;
    scanf("%u", &n);
    res = worker(n);
    printf("%u\n", res);
    return 0;
}

uint32_t worker(uint32_t n)
{
    uint32_t res = 0;
    while (n)
    {
        res += n & 1;
        n >>= 1;
    }
    return res;
}
