#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* timeConversion(char* s)
{
    int tmp;
    char buffer[3];
    static char pBuffer[9];

    strncpy(pBuffer, s, 8);
    strncpy(buffer, s, 2);
    tmp = 0;
    if (!strncmp(&s[8], "PM", 2)) {
        if (strncmp(s, "12", 2))
            tmp = 12;
    } else {
        if (!strncmp(s, "12", 2))
            tmp = 12;
    }
    tmp += atoi(buffer);
    tmp %= 24;
    sprintf(pBuffer, "%02d%s", tmp, &pBuffer[2]);
    return pBuffer;
}

int main()
{

    char* str = "12:00:01AM";
    char* ret;

    ret = timeConversion(str);
    puts(ret);
}