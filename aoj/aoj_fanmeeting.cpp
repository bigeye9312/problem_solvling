// fail
// #include <stdlib.h>
// #include <stdio.h>
// #include <math.h>
// #include <string>
// #include <vector>
// #include <algorithm>

// #define MAX_M (200001)

// void add_to(std::vector<int> &a, const std::vector<int> &b, int k)
// {
//     int a_size = a.size();
//     int b_size = b.size();
//     for (int i = 0; i < a_size && i < b_size; i++)
//     {
//         a[i] += b[i] * pow(10, k);
//     }
// }

// void sub_from(std::vector<int> &a, const std::vector<int> &b)
// {
//     int a_size = a.size();
//     int b_size = b.size();
//     for (int i = 0; i < a_size && i < b_size; i++)
//     {
//         a[i] -= b[i];
//     }
// }

// int a = 0;
// std::vector<int> find_hug_types(const std::vector<int> &members, const std::vector<int> &fans)
// {
//     int num_members = members.size(), num_fans = fans.size();
//     a++;

//     if (a > 100000)
//     {
//         printf("%d %d, %d %d\n", num_members, num_fans, members[0], fans[0]);
//     }

//     if (num_members < num_fans)
//     {
//         return find_hug_types(fans, members);
//     }
//     if (num_members == 0 || num_fans == 0)
//     {
//         return std::vector<int>();
//     }

//     int half = num_members / 2;
//     std::vector<int> a0(members.begin(), members.begin() + half);
//     std::vector<int> a1(members.begin() + half, members.end());
//     std::vector<int> b0(fans.begin(), fans.begin() + std::min<int>(num_fans, half));
//     std::vector<int> b1(fans.begin() + std::min<int>(num_fans, half), fans.end());

//     std::vector<int> z2 = find_hug_types(a1, b1);
//     // std::vector<int> z0 = find_hug_types(a0, b0);

//     // add_to(a0, a1, 0);
//     // add_to(b0, b1, 0);

//     // std::vector<int> z1 = find_hug_types(a0, b0);
//     // sub_from(z1, z0);
//     // sub_from(z1, z2);

//     std::vector<int> ret;
//     // add_to(ret, z0, 0);
//     // add_to(ret, z1, half);
//     // add_to(ret, z2, half + half);
//     return ret;
// }

// int count_all_hugs(const std::string &members, const std::string &fans)
// {
//     int num_members = members.size(), num_fans = fans.size();
//     std::vector<int> A(num_members), B(num_fans);
//     for (int i = 0; i < num_members; i++)
//     {
//         A[i] = (members[i] == 'M') ? 1 : 0;
//     }
//     for (int i = 0; i < num_fans; i++)
//     {
//         B[i] = (fans[i] == 'M') ? 1 : 0;
//     }
//     std::vector<int> C = find_hug_types(A, B);
//     int all_hugs = 0;
//     for (int i = num_members - 1; i < num_fans; i++)
//     {
//         if (C[i] == 0)
//         {
//             all_hugs++;
//         }
//     }
// }

// int main()
// {
//     int C;
//     scanf("%d\n", &C);
//     for (int tc = 0; tc < C; tc++)
//     {
//         char tmp_string[MAX_M];
//         scanf("%s", tmp_string);
//         std::string members(tmp_string);
//         scanf("%s", tmp_string);
//         std::string fans(tmp_string);

//         int ret = count_all_hugs(members, fans);
//         printf("%d\n", ret);
//     }
// }