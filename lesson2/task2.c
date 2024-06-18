#include <stdio.h>
#include <string.h>

typedef struct list_type
{
    void *address;
    size_t size;
    char comment[64];
    struct list_type *next;
} list_type;

size_t totalMemoryUsage(list_type *);

void print_elem(list_type *);

void print_all_elements(list_type *);

int main(int argc, char const *argv[])
{
    list_type test_v[3];
    test_v[0].size = 1000;
    test_v[1].size = 200;
    test_v[2].size = 100;
    test_v[0].next = test_v + 1;
    test_v[1].next = test_v + 2;
    test_v[2].next = NULL;
    test_v[0].address = &test_v[0];
    test_v[1].address = &test_v[1];
    test_v[2].address = &test_v[2];
    strcpy(test_v[0].comment, "main.c");
    strcpy(test_v[1].comment, "main.c");
    strcpy(test_v[2].comment, "main.c");
    printf("---- start data ----\n");
    print_all_elements (test_v);
    printf("---- start data ends ----\n\n");
    size_t t = totalMemoryUsage(test_v);
    printf("---- calculated data ----\n");
    printf("%lld\n", t);
    printf("---- calculated data ends ----");
    return 0;
}

void print_elem(list_type *elem)
{
    if (elem != NULL)
    {
        printf("\
        Real address:\t 0x%p\n\
        Int address:\t 0x%p\n\
        Size:\t\t %lld\n\
        Comment:\t %s\n\
        Next:\t\t 0x%p\n",
        elem, elem->address, elem->size, elem->comment, elem->next);
    }
    else
    {
        printf("(NULL)\n");
    }
}

void print_all_elements(list_type *elem)
{
    list_type *printElem = elem;
    while (printElem != NULL)
    {
        print_elem(printElem);
        printf("----\n");
        printElem = printElem->next;
    }
    
}

size_t totalMemoryUsage(list_type *list)
{
    if (list == NULL)
    {
        return 0;
    }

    size_t totalSize = 0;
    list_type *currentElement = list;

    while (currentElement != NULL)
    {
        totalSize += currentElement->size;
        currentElement = currentElement->next;
    }
    return totalSize;
}