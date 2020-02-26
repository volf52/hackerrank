#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Complete the following function.

void calculate_the_maximum(int n, int k)
{
    // Write your code here.
    int i, j, max_and, max_or, max_xor, tmp;

    max_and = -1;
    max_or = -1;
    max_xor = -1;

    for (i = 1; i < n; i++) {
        j = i + 1;
        while (j <= n) {
            tmp = i & j;
            if ((tmp < k) && (tmp > max_and))
                max_and = tmp;
            tmp = i | j;
            if ((tmp < k) && (tmp > max_or))
                max_or = tmp;
            tmp = i ^ j;
            if ((tmp < k) && (tmp > max_xor))
                max_xor = tmp;
            j++;
        }
    }

    printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
}

int main()
{
    int n, k;

    // scanf("%d %d", &n, &k);
    n = 4;
    k = 3;
    calculate_the_maximum(n, k);

    return 0;
}
