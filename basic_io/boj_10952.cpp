#include <stdio.h>
#include <string>

int main()
{
    int A, B;

    while (scanf("%d %d", &A, &B) != -1)
    {
        if (A != 0 && B != 0)
        {
            printf("%d\n", A + B);
        }
    }

    return 0;
}