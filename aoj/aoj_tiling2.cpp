#include <cstdlib>
#include <cstdio>
#include <vector>

#define DIVIDER (1000000007)

int find_num_tiling(int remained, std::vector<int> &cache)
{
    if (remained == 0)
    {
        return 1;
    }

    int cache_size = cache.size();
    int &ret = cache[cache_size - remained];

    if (ret == -1)
    {
        ret = 0;
        for (int i = 1; i <= 2; i++)
        {
            if (remained >= i)
            {
                ret = (ret + find_num_tiling(remained - i, cache)) % DIVIDER;
            }
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

        std::vector<int> cache;
        for (int i = 0; i < n; i++)
        {
            cache.emplace_back(-1);
        }

        int ret = find_num_tiling(n, cache);
        printf("%d\n", ret);
    }
}