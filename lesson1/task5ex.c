#include <stdio.h>
#include <stdint.h>

struct pack_array
{
    uint32_t array;
    uint32_t count0 : 8;
    uint32_t count1 : 8;
};

void array2struct(int origin[], struct pack_array *res)
{
    for (int i = 0; i < 32; i++)
    {
        res -> count1 += origin[i];
        res -> array |= origin[i];
        i < 31 ? res -> array <<= 1 : 1;
    }
    res -> count0 = 32 - res -> count1;
}

int main(int argc, char const *argv[])
{
    int arr[32] = {0};
    struct pack_array res;
    res.count1 = 0;
    for (int i = 0; i < 32; i++)
    {
        scanf("%d", arr+i);
    }
    array2struct(arr, &res);
    printf("array: 0x%x\ncount0: %d\ncount1: %d\n", res.array, res.count0, res.count1);
    return 0;
}

