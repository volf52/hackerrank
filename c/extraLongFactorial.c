#include <stdio.h>

void extraLongFactorial(int n);

int main()
{

    extraLongFactorial(25);

    return 0;
}

int mul(int x, int res[], int resSize)
{
    int i, prod, carry;

    carry = 0;
    // One by one multiply n with individual digits of res[]
    for (i = 0; i < resSize; i++) {
        prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry = prod / 10;
    }

    // Put carry in res and increase result size
    while (carry) {
        res[resSize] = carry % 10;
        carry = carry / 10;
        resSize++;
    }
    return resSize;
}

void extraLongFactorial(int n)
{
    int res[500];
    int x, resSize;

    // Initialize result
    res[0] = 1;
    resSize = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (x = 2; x <= n; x++)
        resSize = mul(x, res, resSize);

    for (int i = resSize - 1; i >= 0; i--)
        printf("%d", res[i]);
    printf("\n");
}