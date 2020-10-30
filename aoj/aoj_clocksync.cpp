#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

#define NUM_CLOCKS (16)
#define NUM_SWITCHES (10)
#define MAX_LINKED_CLOCKS (5)
#define MAX_CLICKS_PER_SWITCH (4)

const int switch_map[NUM_SWITCHES][MAX_LINKED_CLOCKS] = {
    {0, 1, 2, -1, -1},
    {3, 7, 9, 11, -1},
    {4, 10, 14, 15, -1},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15, -1},
    {3, 14, 15, -1, -1},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}};

bool is_twelve_aligned(int *clocks)
{
    bool twelve_aligned = true;
    for (int i = 0; i < NUM_CLOCKS; i++)
    {
        if (clocks[i] != 12)
        {
            twelve_aligned = false;
            break;
        }
    }

    return twelve_aligned;
}

void click_swtich(int *clocks, int switch_num, bool push)
{

    // push
    if (push == true)
    {
        for (int i = 0; i < MAX_LINKED_CLOCKS; i++)
        {
            if (switch_map[switch_num][i] != -1)
            {
                clocks[switch_map[switch_num][i]] = (clocks[switch_map[switch_num][i]] % 12) + 3;
            }
            else
            {
                break;
            }
        }
    }
    // pop
    // else
    // {
    //     for (int i = 0; i < MAX_LINKED_CLOCKS; i++)
    //     {
    //         if (switch_map[switch_num][i] != -1)
    //         {
    //             int tmp = clocks[switch_map[switch_num][i]] - 3;
    //             clocks[switch_map[switch_num][i]] = (tmp != 0) ? tmp : 12;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    // }
}

int search_min_switches(int *clocks, int curr_switch, int curr_num_clicks, int curr_min_clicks)
{
    if (curr_num_clicks >= curr_min_clicks)
    {
        return curr_min_clicks;
    }

    if (is_twelve_aligned(clocks) == true)
    {
        curr_min_clicks = std::min(curr_min_clicks, curr_num_clicks);
        return curr_min_clicks;
    }

    if (curr_switch >= NUM_SWITCHES)
    {
        return curr_min_clicks;
    }

    int ret = curr_min_clicks;

    for (int i = 0; i < MAX_CLICKS_PER_SWITCH; i++)
    {
        ret = search_min_switches(clocks, curr_switch + 1, curr_num_clicks, curr_min_clicks);
        curr_min_clicks = std::min(curr_min_clicks, ret);
        click_swtich(clocks, curr_switch, true);
        curr_num_clicks++;
    }

    return curr_min_clicks;
}

int main()
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++)
    {
        int clocks[NUM_CLOCKS] = {0};
        for (int i = 0; i < NUM_CLOCKS; i++)
        {
            scanf("%d", &clocks[i]);
        }

        int curr_min_clicks = std::numeric_limits<int>::max();
        int ret = search_min_switches(clocks, 0, 0, curr_min_clicks);

        if (ret == std::numeric_limits<int>::max())
        {
            ret = -1;
        }

        printf("%d\n", ret);
    }
}