#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    uint32_t n;
    int res = 0;
    uint32_t temp;
    scanf("%u", &n);
    while (n != 0)
    {
        if (n & 1)
        {
            res++;
        }
        n >>= 1;
    }
    
    printf("%d", res);

    return 0;
}
