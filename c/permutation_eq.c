#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int* permutationEquation(int p_count, int* p, int* result_count)
{
    int i, tmp;
    int arr[p_count];
    int* res;
    res = (int*)malloc(p_count * sizeof(int));
    assert(res != NULL);
    *result_count = p_count;
    for (i = 0; i < p_count; i++) {
        arr[p[i] - 1] = i;
    }

    for (i = 0; i < p_count; i++) {
        res[i] = arr[arr[i]] + 1;
    }
    return res;
}

int main()
{
    int p[] = { 5, 2, 1, 3, 4 };
    int *res, t;

    res = permutationEquation(5, p, &t);
    return EXIT_SUCCESS;
}