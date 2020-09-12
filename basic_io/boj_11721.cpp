#include <stdio.h>
#include <string>

#define MAX_N 101

int main()
{
    char input_str[MAX_N];
    int idx = 0;

    scanf("%s", &input_str);

    while (true)
    {
        if (input_str[idx] != '\0')
        {
            printf("%c", input_str[idx++]);
            if (idx % 10 == 0)
            {
                printf("\n");
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}