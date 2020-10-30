#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAP_LENGTH (5)
#define DIR_LENGTH (8)
#define MAX_N (10)

char map[MAP_LENGTH][MAP_LENGTH];
int cache_map[MAP_LENGTH][MAP_LENGTH][MAX_N];

int drow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dcol[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool find_string(int row, int col, char *target_string, int idx)
{
    if (target_string[idx] != map[row][col])
    {
        return false;
    }

    if (idx == strlen(target_string) - 1)
    {
        return true;
    }

    // memoization (0:false, 1:true)
    if (cache_map[row][col][idx] != -1)
    {
        // printf("[%c][%c] cache_map[%d][%d][%d] : %d\n", target_string[idx], map[row][col], row, col, idx, cache_map[row][col][idx]);
        return (bool)cache_map[row][col][idx];
    }

    bool is_found = false;
    for (int i = 0; i < DIR_LENGTH; i++)
    {
        int dst_row = row + drow[i];
        int dst_col = col + dcol[i];

        if (dst_row >= MAP_LENGTH || dst_col >= MAP_LENGTH || dst_row < 0 || dst_col < 0)
        {
            continue;
        }

        is_found = find_string(dst_row, dst_col, target_string, idx + 1);
        if (is_found == true)
        {
            cache_map[dst_row][dst_col][idx + 1] = 1;
            break;
        }
    }

    if (is_found == true)
    {
        cache_map[row][col][idx] = 1;
    }
    else
    {
        cache_map[row][col][idx] = 0;
    }

    return is_found;
}

int main()
{
    int C, N;

    scanf(" %d", &C);

    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < MAP_LENGTH; j++)
        {
            for (int k = 0; k < MAP_LENGTH; k++)
            {
                scanf(" %c", &map[j][k]);
            }
        }

        scanf(" %d", &N);

        for (int j = 0; j < N; j++)
        {
            bool is_found = false;
            char target_string[MAX_N + 1];

            memset(cache_map, -1, sizeof(cache_map));
            scanf("%s", target_string);

            for (int k = 0; k < MAP_LENGTH; k++)
            {
                for (int l = 0; l < MAP_LENGTH; l++)
                {
                    is_found = find_string(k, l, target_string, 0);
                    if (is_found == true)
                    {
                        break;
                    }
                }

                if (is_found == true)
                {
                    break;
                }
            }

            if (is_found == true)
            {
                printf("%s YES\n", target_string);
            }
            else
            {
                printf("%s NO\n", target_string);
            }
        }
    }
}