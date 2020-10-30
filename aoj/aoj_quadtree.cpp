#include <stdlib.h>
#include <stdio.h>
#include <string>

#define MAX_LENGTH (1000)

std::string convert_tree(char *compressed, int *s_idx)
{
    char head = compressed[(*s_idx)++];
    if (head == 'b' || head == 'w')
    {
        return std::string(1, head);
    }

    std::string upper_left = convert_tree(compressed, s_idx);
    std::string upper_right = convert_tree(compressed, s_idx);
    std::string lower_left = convert_tree(compressed, s_idx);
    std::string lower_right = convert_tree(compressed, s_idx);

    return std::string("x") + lower_left + lower_right + upper_left + upper_right;
}

int main()
{
    int C;
    scanf("%d\n", &C);
    for (int tc = 0; tc < C; tc++)
    {
        char compressed[MAX_LENGTH];
        int s_idx = 0;
        std::string converted;
        scanf("%s\n", compressed);
        converted = convert_tree(compressed, &s_idx);
        printf("%s\n", converted.c_str());
    }
}