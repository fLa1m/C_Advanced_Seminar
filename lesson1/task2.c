#include <stdio.h>
#include <stdint.h>
int main(int argc, char const *argv[])
{
    unsigned int k;
    uint32_t n, res;
    scanf("%u %u", &n, &k);
    res = n << (32 - k);
    res >>= (32 - k);
    printf("%u", res);
    return 0;
}
