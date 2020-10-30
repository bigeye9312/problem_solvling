#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

#define MAX_LENGTH (101)

bool check_matching(const std::string &str_wildcard, const std::string &str_file)
{
    int pos = 0;
    while (pos < str_wildcard.size() && pos < str_file.size() && (str_wildcard[pos] == '?' || str_wildcard[pos] == str_file[pos]))
    {
        pos++;
    }

    if (pos == str_wildcard.size())
    {
        return (pos == str_file.size());
    }

    bool ret = false;
    if (str_wildcard[pos] == '*')
    {
        for (int skip = 0; pos + skip <= str_file.size(); skip++)
        {
            if (check_matching(str_wildcard.substr(pos + 1), str_file.substr(pos + skip)) == true)
            {
                ret = true;
                break;
            }
        }
    }

    return ret;
}

int main()
{
    int C;
    scanf("%d\n", &C);
    for (int tc = 0; tc < C; tc++)
    {
        char str_tmp[MAX_LENGTH];

        scanf("%s", str_tmp);
        std::string str_wildcard(str_tmp);

        int N;
        scanf("%d\n", &N);

        std::vector<std::string> vec_file;
        for (int i = 0; i < N; i++)
        {
            scanf("%s", str_tmp);
            std::string str_file(str_tmp);
            bool ret = check_matching(str_wildcard, str_file);
            if (ret == true)
            {
                vec_file.emplace_back(str_file);
            }
        }

        int result_length = vec_file.size();
        std::sort(vec_file.begin(), vec_file.end());
        for (int i = 0; i < result_length; i++)
        {
            printf("%s\n", vec_file[i].c_str());
        }
    }
}