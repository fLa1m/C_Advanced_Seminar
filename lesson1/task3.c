#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    uint32_t N;
    unsigned int K;
    scanf("%u %u", &N, &K);

    uint32_t mask = ~0;
    // mask <<= (32 - K);
    uint32_t max = 0;

    for (int i = 0; i <= (32 - K); i++)
    {
        uint32_t v = (N & (mask >> (32 - K)) << i) >> i;
        if (v > max)    
        {
            max = v;
        }
        // mask >>= i;
    }
    
    printf("%u", max);
    return 0;
}
