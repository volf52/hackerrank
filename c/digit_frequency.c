#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char s[1024];
    int i, tmp;
    int frequency[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    scanf("%[^\n]%*c", &s);

    i = 0;
    printf("%s", s);
    while (s[i] != '\0') {
        if (isdigit(s[i])) {
            tmp = s[i] - '0';
            frequency[tmp]++;
        }
        i++;
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", frequency[i]);
    }
    printf("\n");
    return 0;
}