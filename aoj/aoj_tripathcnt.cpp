#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

int path(const std::vector<std::vector<int>> &triangle, std::vector<std::vector<int>> &cache_path, int row, int col)
{
    if (row == triangle.size() - 1)
    {
        return triangle[row][col];
    }

    int &ret = cache_path[row][col];
    if (ret == -1)
    {
        ret = std::max(path(triangle, cache_path, row + 1, col), path(triangle, cache_path, row + 1, col + 1)) + triangle[row][col];
    }

    return ret;
}

int find_num_max_path(const std::vector<std::vector<int>> &triangle, std::vector<std::vector<int>> &cache_path, std::vector<std::vector<int>> &cache_cnt, int row, int col)
{
    if (row == triangle.size() - 1)
    {
        return 1;
    }

    int &ret = cache_cnt[row][col];

    if (ret == -1)
    {
        ret = 0;
        int next_1 = path(triangle, cache_path, row + 1, col);
        int next_2 = path(triangle, cache_path, row + 1, col + 1);
        if (next_1 >= next_2)
        {
            ret += find_num_max_path(triangle, cache_path, cache_cnt, row + 1, col);
        }
        if (next_1 <= next_2)
        {
            ret += find_num_max_path(triangle, cache_path, cache_cnt, row + 1, col + 1);
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

        std::vector<std::vector<int>> triangle;
        std::vector<std::vector<int>> cache_path;
        std::vector<std::vector<int>> cache_cnt;
        for (int i = 1; i <= n; i++)
        {
            std::vector<int> tmp_triangle;
            std::vector<int> tmp_cache;
            for (int j = 0; j < i; j++)
            {
                int tmp_int;
                scanf("%d", &tmp_int);
                tmp_triangle.emplace_back(tmp_int);
                tmp_cache.emplace_back(-1);
            }
            triangle.emplace_back(tmp_triangle);
            cache_path.emplace_back(tmp_cache);
            cache_cnt.emplace_back(tmp_cache);
        }

        int num_max_path = find_num_max_path(triangle, cache_path, cache_cnt, 0, 0);
        printf("%d\n", num_max_path);
    }
}