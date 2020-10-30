#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

// int find_max_sum_1(const std::vector<std::vector<int>> &triangle, std::vector<std::vector<int>> &cache_triangle, int row, int col, int curr_sum)
// {
//     // range check
//     int triangle_size = triangle.size();
//     if (row < 0 || col < 0 || row >= triangle_size || col > row)
//     {
//         return std::numeric_limits<int>::min();
//     }

//     curr_sum += triangle[row][col];
//     if (row == triangle_size - 1)
//     {
//         return curr_sum;
//     }

//     // cache check
//     if (cache_triangle[row][col] >= curr_sum)
//     {
//         return std::numeric_limits<int>::min();
//     }
//     else
//     {
//         cache_triangle[row][col] = curr_sum;
//     }

//     // get max sum
//     int ret = std::max(find_max_sum_1(triangle, cache_triangle, row + 1, col, curr_sum), find_max_sum_1(triangle, cache_triangle, row + 1, col + 1, curr_sum));
//     return ret;
// }

int find_max_sum_2(const std::vector<std::vector<int>> &triangle, std::vector<std::vector<int>> &cache_triangle, int row, int col)
{
    int triangle_size = triangle.size();
    if (row < 0 || col < 0 || row >= triangle_size || col > row)
    {
        return std::numeric_limits<int>::min();
    }
    if (row == triangle_size - 1)
    {
        return triangle[row][col];
    }

    int &ret = cache_triangle[row][col];
    if (ret != -1)
    {
        return ret;
    }

    ret = std::max(find_max_sum_2(triangle, cache_triangle, row + 1, col), find_max_sum_2(triangle, cache_triangle, row + 1, col + 1)) + triangle[row][col];
    return ret;
}

int main()
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++)
    {
        int N;
        scanf("%d", &N);

        std::vector<std::vector<int>> triangle;
        std::vector<std::vector<int>> cache_triangle;
        for (int i = 0; i < N; i++)
        {
            int tmp_int;
            std::vector<int> tmp_vec;
            std::vector<int> tmp_vec_for_cache;
            for (int j = 0; j < i + 1; j++)
            {
                scanf("%d", &tmp_int);
                tmp_vec.emplace_back(tmp_int);
                tmp_vec_for_cache.emplace_back(-1);
            }
            triangle.emplace_back(tmp_vec);
            cache_triangle.emplace_back(tmp_vec_for_cache);
        }

        // int ret = find_max_sum_1(triangle, cache_triangle, 0, 0, 0);
        int ret = find_max_sum_2(triangle, cache_triangle, 0, 0);
        printf("%d\n", ret);
    }
}