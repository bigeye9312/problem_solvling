#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

int find_max_rect_size(const std ::vector<int> &input_vec, int s_idx, int e_idx)
{
    if (s_idx == e_idx)
    {
        return input_vec[s_idx];
    }

    int mid = (s_idx + e_idx) / 2;
    int max_size = std::max(find_max_rect_size(input_vec, s_idx, mid), find_max_rect_size(input_vec, mid + 1, e_idx));
    int center_lower = mid, center_upper = mid + 1;
    int center_height = std::min(input_vec[center_lower], input_vec[center_upper]);
    max_size = std::max(max_size, 2 * center_height);

    while (s_idx < center_lower || e_idx > center_upper)
    {
        if (e_idx > center_upper && (s_idx == center_lower || input_vec[center_lower - 1] < input_vec[center_upper + 1]))
        {
            center_upper++;
            center_height = std::min(center_height, input_vec[center_upper]);
        }
        else
        {
            center_lower--;
            center_height = std::min(center_height, input_vec[center_lower]);
        }

        max_size = std::max(max_size, (center_upper - center_lower + 1) * center_height);
    }

    return max_size;
}

int main()
{
    int C;
    scanf("%d", &C);

    for (int tc = 0; tc < C; tc++)
    {
        int N, height;
        std::vector<int> input_vec;
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &height);
            input_vec.emplace_back(height);
        }
        int ret = find_max_rect_size(input_vec, 0, input_vec.size() - 1);
        printf("%d\n", ret);
    }
}