// #include <cstdlib>
// #include <cstdio>
// #include <vector>
// #include <algorithm>

// int find_optimal_quantization(const std::vector<int> &input_num, std::vector<std::vector<int>> &cache, int remained)
// {
//     if (input_num.size() == 0)
//     {
//         return 0;
//     }

//     if (remained == 0)
//     {
//         return std::numeric_limits<int>::max();
//     }
// }

// int main()
// {
//     int C;
//     scanf("%d", &C);

//     for (int tc = 0; tc < C; tc++)
//     {
//         int N, S;
//         scanf("%d %d", &N, &S);

//         std::vector<int> input_num;
//         std::vector<std::vector<int>> cache;
//         for (int i = 0; i < N; i++)
//         {
//             int tmp;
//             scanf("%d", &tmp);
//             input_num.emplace_back(tmp);
//         }

//         std::sort(input_num.begin(), input_num.end());
//         int ret = find_optimal_quantization(input_num, cache, input_num.size());
//         printf("%d\n", ret);
//     }
// }