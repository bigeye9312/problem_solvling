#include <cstdlib>
#include <cstdio>
#include <list>

void find_survivors(int N, int K, std::list<int> &survivors)
{
    std::list<int>::iterator kill = survivors.begin();
    while (N > 2)
    {
        kill = survivors.erase(kill);
        if (kill == survivors.end())
        {
            kill = survivors.begin();
        }
        N--;

        for (int i = 0; i < (K - 1) % N; i++)
        {
            kill++;
            if (kill == survivors.end())
            {
                kill = survivors.begin();
            }
        }
    }

    printf("%d %d\n", survivors.front(), survivors.back());
    return;
}

int main()
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++)
    {
        int N, K;
        scanf("%d %d", &N, &K);

        std::list<int> survivors;
        for (int i = 1; i <= N; i++)
        {
            survivors.emplace_back(i);
        }

        find_survivors(N, K, survivors);
    }
}