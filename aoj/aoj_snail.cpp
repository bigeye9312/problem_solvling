#include <cstdlib>
#include <cstdio>
#include <vector>

double climb(int max_days, int max_climbed, std::vector<std::vector<double>> &cache, int days, int climbed)
{
    if (days == max_days)
    {
        return (climbed >= max_climbed) ? 1 : 0;
    }

    double &ret = cache[days][climbed];
    if (ret == -1)
    {
        ret = 0.25 * climb(max_days, max_climbed, cache, days + 1, climbed + 1) + 0.75 * climb(max_days, max_climbed, cache, days + 1, climbed + 2);
    }

    return ret;
}

int main()
{
    int C;
    scanf("%d", &C);

    for (int tc = 0; tc < C; tc++)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        std::vector<std::vector<double>> cache;
        for (int i = 0; i < n; i++)
        {
            std::vector<double> cache_tmp;
            for (int j = 0; j < 2 * n + 1; j++)
            {
                cache_tmp.emplace_back(-1);
            }
            cache.emplace_back(cache_tmp);
        }

        double ret = climb(m, n, cache, 0, 0);
        printf("%.10f\n", ret);
    }
}