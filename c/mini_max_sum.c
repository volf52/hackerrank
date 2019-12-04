#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    long int min = LONG_MAX;
    long int max = LONG_MIN;
    long int sum;
    int arr[] = {769082435, 210437958, 673982045, 375809214, 380564127};
    int arr_count = 5;

    int i, j;
    for (i = 0; i < arr_count; i++)
    {
        sum = 0;
        for (j = 0; j < arr_count; j++)
            if (i != j)
                sum += arr[j];
        if (sum > max)
            max = sum;
        if (sum < min)
            min = sum;
    }
    printf("%ld %ld", min, max);

    return 0;
}