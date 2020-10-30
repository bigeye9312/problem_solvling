#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

int find_max_length(const std::vector<int> &input_int, std::vector<int> &cache_int, int s_idx)
{
    int input_int_length = input_int.size();
    int ret = 1;

    if (cache_int[s_idx] == -1)
    {
        for (int i = s_idx; i < input_int_length; i++)
        {
            if (input_int[s_idx] < input_int[i])
            {
                ret = std::max(ret, 1 + find_max_length(input_int, cache_int, i));
            }
        }
        cache_int[s_idx] = ret;
    }

    return cache_int[s_idx];
}

int main()
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++)
    {
        int N;
        scanf("%d", &N);

        std::vector<int> input_int;
        std::vector<int> cache_int;
        for (int i = 0; i < N; i++)
        {
            int tmp_int;
            scanf("%d", &tmp_int);
            input_int.emplace_back(tmp_int);
            cache_int.emplace_back(-1);
        }

        int ret = 1;
        for (int i = 0; i < N; i++)
        {
            ret = std::max(ret, find_max_length(input_int, cache_int, i));
        }
        printf("%d\n", ret);
    }
}