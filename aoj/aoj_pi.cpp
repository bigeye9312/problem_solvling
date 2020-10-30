#include <cstdlib>
#include <cstdio>
#include <string>
#include <array>
#include <algorithm>

#define MAX_LENGTH (10001)

int get_curr_difficulty(const std::string &next_str)
{
    int str_size = next_str.size();
    int diffculty = 10;

    // check 1
    bool is_same = true;
    for (int i = 1; i < str_size; i++)
    {
        if (next_str[i] != next_str[i - 1])
        {
            is_same = false;
            break;
        }
    }

    // check 2-1
    bool is_increasing = true;
    for (int i = 1; i < str_size; i++)
    {
        if (next_str[i] != next_str[i - 1] + 1)
        {
            is_increasing = false;
            break;
        }
    }

    // check 2-2
    bool is_decreasing = true;
    for (int i = 1; i < str_size; i++)
    {
        if (next_str[i] != next_str[i - 1] - 1)
        {
            is_decreasing = false;
            break;
        }
    }

    // check 3
    bool is_toggling = true;
    for (int i = 2; i < str_size; i++)
    {
        if (next_str[i] != next_str[i - 2])
        {
            is_toggling = false;
            break;
        }
    }

    // check 4
    bool is_step_sequential = true;
    int itvl = next_str[1] - next_str[0];
    for (int i = 1; i < str_size; i++)
    {
        if (next_str[i] - next_str[i - 1] != itvl)
        {
            is_step_sequential = false;
            break;
        }
    }

    diffculty = is_step_sequential ? 5 : diffculty;
    diffculty = is_toggling ? 4 : diffculty;
    diffculty = is_decreasing ? 2 : diffculty;
    diffculty = is_increasing ? 2 : diffculty;
    diffculty = is_same ? 1 : diffculty;

    return diffculty;
}

int find_min_difficulty(const std::string &input_str, std::array<int, MAX_LENGTH> &cache, int idx)
{
    if (input_str.size() == 0)
    {
        return 0;
    }

    int &ret = cache[idx];

    if (ret == -1)
    {
        const int MAX_DIFFICULTY = 10;
        ret = std::numeric_limits<int>::max() - MAX_DIFFICULTY;
        for (int i = 3; i <= 5; i++)
        {
            if (input_str.size() >= i)
            {
                int curr_difficulty = get_curr_difficulty(input_str.substr(0, i));
                int ret_cand = find_min_difficulty(input_str.substr(i), cache, idx + i);
                ret = std::min(ret, ret_cand + curr_difficulty);
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
        char tmp_str[MAX_LENGTH];

        scanf("%s", tmp_str);
        std::string input_str(tmp_str);

        std::array<int, 10001> cache;
        cache.fill(-1);

        int min_difficulty = std::numeric_limits<int>::max();
        int ret = find_min_difficulty(input_str, cache, 0);
        printf("%d\n", ret);
    }
}