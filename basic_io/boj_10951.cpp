#include <stdio.h>
#include <string>

int main()
{
    int A, B;

    while (scanf("%d %d", &A, &B) != -1)
    {
        printf("%d\n", A + B);
    }

    return 0;
}