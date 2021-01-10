#include <cstdlib>
#include <cstdio>
#include <vector>

#define DIVIDER (1000000007)
#define TEST_VAR (0)

int find_num_tiling(int remained, std::vector<int> &cache)
{
    if (remained <= 1)
    {
        return 1;
    }

    int &ret = cache[remained];

    if (ret == -1)
    {
        int ret_1 = 0, ret_2 = 0;
        if (remained >= 1)
        {
            ret_1 = find_num_tiling(remained - 1, cache);
        }
        if (remained >= 2)
        {
            ret_2 = find_num_tiling(remained - 2, cache);
        }

        ret = (ret_1 + ret_2) % DIVIDER;
    }

    return ret;
}

int find_num_async_tiling(int remained, std::vector<int> &cache)
{
    if (remained % 2 == 1)
    {
        return (find_num_tiling(remained, cache) - find_num_tiling(remained / 2, cache) + DIVIDER) % DIVIDER;
    }

    int ret = find_num_tiling(remained, cache);
    ret = (ret - find_num_tiling(remained / 2, cache) + DIVIDER) % DIVIDER;
    ret = (ret - find_num_tiling(remained / 2 - 1, cache) + DIVIDER) % DIVIDER;
    return ret;
}

int main()
{
    int C;
    scanf("%d", &C);

    for (int tc; tc < C; tc++)
    {
        int n;
        scanf("%d", &n);

        std::vector<int> cache;
        for (int i = 0; i < n + 1; i++)
        {
            cache.emplace_back(-1);
        }

        int ret = find_num_async_tiling(n, cache);
        printf("%d\n", ret);
    }
}