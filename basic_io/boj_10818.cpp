#include <stdio.h>
#include <string>
#include <algorithm>

int main()
{
    int N;
    int min_val = std::numeric_limits<int>::max();
    int max_val = std::numeric_limits<int>::min();

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int tmp_num;
        scanf(" %d", &tmp_num);
        min_val = std::min(min_val, tmp_num);
        max_val = std::max(max_val, tmp_num);
    }

    printf("%d %d", min_val, max_val);

    return 0;
}