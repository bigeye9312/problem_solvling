#include <stdio.h>
#include <string>

#define MAX_N 101

int main()
{
    char input_str[MAX_N];

    while (scanf(" %[^\n]", input_str) != -1)
    {
        printf("%s\n", input_str);
    }

    return 0;
}