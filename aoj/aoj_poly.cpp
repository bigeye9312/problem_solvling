#include <cstdlib>
#include <cstdio>
#include <vector>

#define DIVIDER (10 * 1000 * 1000)

int find_num_poly(int remained, int first, std::vector<std::vector<int>> &cache)
{
    if (remained == first)
    {
        return 1;
    }

    int &ret = cache[remained][first];

    if (ret == -1)
    {
        ret = 0;
        for (int second = 1; second <= remained - first; second++)
        {
            int add = second + first - 1;
            add *= find_num_poly(remained - first, second, cache);
            ret += add;
            ret %= DIVIDER;
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

        std::vector<std::vector<int>> cache;
        for (int i = 0; i < n + 1; i++)
        {
            std::vector<int> cache_tmp;
            for (int j = 0; j < n + 1; j++)
            {
                cache_tmp.emplace_back(-1);
            }
            cache.emplace_back(cache_tmp);
        }

        int ret = 0;
        for (int i = 1; i <= n; i++)
        {
            ret += find_num_poly(n, i, cache);
            ret %= DIVIDER;
        }
        printf("%d\n", ret);
    }
}