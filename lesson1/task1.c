#include <stdint.h>
#include <stdio.h>

/*
N = 001011
K = 2
res = 110010
*/

int main(int argc, char const *argv[])
{
    uint32_t N;
    unsigned int K;
    scanf("%u %u", &N, &K);

    uint32_t res;
    uint32_t temp;

    //uint32_t mask = ~0;
    //printf("%u\n", mask);
    //mask >>= (32 - K); // 000011

    //temp = N | mask; // 000011
    temp = N << (32 - K); // 110000

    res = N >> K;
    res = res | temp;

    printf("%u", res);

    return 0;
}
