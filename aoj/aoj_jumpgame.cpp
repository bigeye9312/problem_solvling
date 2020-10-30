#include <cstdlib>
#include <cstdio>
#include <vector>

bool is_possible_to_reach(const std::vector<std::vector<int>> &map, std::vector<std::vector<int>> &cache_map, int row, int col)
{
    int map_length = map.size();
    if (row == map_length - 1 && col == map_length - 1)
    {
        return true;
    }

    // memoization (0:false, 1:true)
    if (cache_map[row][col] != -1)
    {
        return (bool)cache_map[row][col];
    }

    bool ret = false;
    int cnt = map[row][col];

    int drow[2] = {0, cnt};
    int dcol[2] = {cnt, 0};

    for (int i = 0; i < 2; i++)
    {
        int dst_row = row + drow[i];
        int dst_col = col + dcol[i];

        if (dst_row < 0 || dst_col < 0 || dst_row >= map_length || dst_col >= map_length)
        {
            continue;
        }

        cache_map[dst_row][dst_col] = is_possible_to_reach(map, cache_map, dst_row, dst_col);
        if (cache_map[dst_row][dst_col] == true)
        {
            // printf("[%d] (%d %d) -> (%d %d)\n", map[row][col], row, col, dst_row, dst_col);
            ret = true;
            break;
        }
    }

    return ret;
}

int main()
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++)
    {
        int n;
        scanf("%d", &n);
        std::vector<std::vector<int>> map;
        std::vector<std::vector<int>> cache_map;
        for (int i = 0; i < n; i++)
        {
            std::vector<int> tmp_map;
            std::vector<int> tmp_cache_map;
            for (int j = 0; j < n; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                tmp_map.emplace_back(tmp);
                tmp_cache_map.emplace_back(-1);
            }
            map.emplace_back(tmp_map);
            cache_map.emplace_back(tmp_cache_map);
        }
        bool ret = is_possible_to_reach(map, cache_map, 0, 0);
        printf("%s\n", (ret == true) ? "YES" : "NO");
    }
}