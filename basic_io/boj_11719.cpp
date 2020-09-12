#include <stdio.h>
#include <string>

#define MAX_N 102

int main()
{
    char input_str[MAX_N];

    while (true)
    {
        int ret = scanf("%[^\n]", input_str);
        scanf("%*c");
        if (ret == -1)
        {
            break;
        }
        else if (ret == 0)
        {
            printf("\n");
        }
        else
        {
            printf("%s\n", input_str);
        }
    }

    return 0;
}