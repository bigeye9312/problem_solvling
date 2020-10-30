#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

int find_max_length(const std::vector<int> &input_int_1, const std::vector<int> &input_int_2, std::vector<std::vector<int>> &cache_int, int idx_1, int idx_2)
{
    int input_int_size_1 = input_int_1.size();
    int input_int_size_2 = input_int_2.size();
    int &ret = cache_int[idx_1 + 1][idx_2 + 1];
    // int &ret = cache_int[idx_1][idx_2];

    if (ret == -1)
    {
        const long long NEGINF = std::numeric_limits<long long>::min();
        long long a = (idx_1 == -1) ? NEGINF : input_int_1[idx_1];
        long long b = (idx_2 == -1) ? NEGINF : input_int_2[idx_2];
        long long max_int = std::max(a, b);
        ret = 2;

        for (int i = idx_1 + 1; i < input_int_size_1; i++)
        {
            if (max_int < input_int_1[i])
            {
                ret = std::max(ret, find_max_length(input_int_1, input_int_2, cache_int, i, idx_2) + 1);
            }
        }

        for (int i = idx_2 + 1; i < input_int_size_2; i++)
        {
            if (max_int < input_int_2[i])
            {
                ret = std::max(ret, find_max_length(input_int_1, input_int_2, cache_int, idx_1, i) + 1);
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
        int n, m;
        scanf("%d %d", &n, &m);

        std::vector<int> input_int_1;
        for (int i = 0; i < n; i++)
        {
            int tmp_int;
            scanf("%d", &tmp_int);
            input_int_1.emplace_back(tmp_int);
        }

        std::vector<int> input_int_2;
        for (int i = 0; i < m; i++)
        {
            int tmp_int;
            scanf("%d", &tmp_int);
            input_int_2.emplace_back(tmp_int);
        }

        std::vector<std::vector<int>> cache_int;
        for (int i = 0; i < n + 1; i++)
        {
            std::vector<int> tmp_cache_int;
            for (int j = 0; j < m + 1; j++)
            {
                tmp_cache_int.emplace_back(-1);
            }
            cache_int.emplace_back(tmp_cache_int);
        }

        int max_length = std::numeric_limits<int>::min();
        for (int i = -1; i < n; i++)
        {
            for (int j = -1; j < m; j++)
            {
                max_length = std::max(max_length, find_max_length(input_int_1, input_int_2, cache_int, i, j));
            }
        }

        printf("%d\n", max_length - 2);
    }
}