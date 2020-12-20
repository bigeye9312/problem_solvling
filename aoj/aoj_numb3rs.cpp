// #include <cstdlib>
// #include <cstdio>
// #include <vector>

// int main()
// {
//     int C;
//     scanf("%d", &C);

//     for (int tc = 0; tc < C; tc++)
//     {
//         int n, d, p;
//         scanf("%d %d %d", n, d, p);

//         std::vector<std::vector<int>> map, cache;
//         for (int i = 0; i < n + 1; i++)
//         {
//             std::vector<int> map_tmp, cache_tmp;
//             for (int j = 0; j < n + 1; j++)
//             {
//                 int tmp;
//                 scanf("%d", &tmp);
//                 map_tmp.emplace_back(tmp);
//                 cache_tmp.emplace_back(-1);
//             }
//             map.emplace_back(map_tmp);
//             cache.emplace_back(cache_tmp);
//         }

//         int t;
//         scanf("%d", &t);

//         for (int i = 0; i < t; i++)
//         {
//             int q;
//             scanf("%d", &q);

//             double ret = 0;
//             printf("%.8f ", ret);
//         }
//         printf("\n");
//     }
// }