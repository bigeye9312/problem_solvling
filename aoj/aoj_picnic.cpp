#include <stdlib.h>
#include <stdio.h>

#define MAX_N (10)

int find_num_combinations(bool (*friendship)[MAX_N], int num_students, bool *paired)
{
    int first_free = -1;
    for (int i = 0; i < num_students; i++)
    {
        if (paired[i] == false)
        {
            first_free = i;
            break;
        }
    }

    if (first_free == -1)
    {
        return 1;
    }

    int ret = 0;

    for (int i = first_free + 1; i < num_students; i++)
    {
        if (paired[i] == false && friendship[first_free][i])
        {
            paired[first_free] = paired[i] = true;
            ret += find_num_combinations(friendship, num_students, paired);
            paired[first_free] = paired[i] = false;
        }
    }

    return ret;
}

int main()
{
    int C;
    scanf("%d", &C);

    for (int tc; tc < C; tc++)
    {
        int n, m;
        bool friendship[MAX_N][MAX_N] = {false};
        bool paired[MAX_N] = {false};

        scanf("%d %d", &n, &m);

        for (int i = 0; i < m; i++)
        {
            int f1, f2;
            scanf("%d %d", &f1, &f2);
            friendship[f1][f2] = true;
            friendship[f2][f1] = true;
        }

        int num_combinations = find_num_combinations(friendship, n, paired);
        printf("%d\n", num_combinations);
    }
}