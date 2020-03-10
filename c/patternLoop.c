#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 1000

void fillArr(int arr[LENGTH][LENGTH], int start, int len, int toPrint)
{
    int i, tmp;

    if (start > len)
        return;

    tmp = len - 1;
    for (i = start; i < len; i++) {
        arr[start][i] = toPrint;
        arr[i][start] = toPrint;
        arr[tmp][i] = toPrint;
        arr[i][tmp] = toPrint;
    }

    fillArr(arr, start + 1, len - 1, toPrint - 1);
}

int main()
{

    int i, j, n, len;
    int arr[LENGTH][LENGTH];
    n = 898;
    // Complete the code to print the pattern.
    len = 2 * n - 1;

    fillArr(arr, 0, len, n);

    for (i = 0; i < len; i++) {
        for (j = 0; j < (len - 1); j++)
            printf("%d ", arr[i][j]);
        printf("%d\n", arr[i][len - 1]);
    }

    return 0;
}