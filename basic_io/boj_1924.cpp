#include <stdio.h>
#include <string>

int main()
{
    std::string day_string[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int days_per_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month, day, days_elapsed;

    scanf("%d %d", &month, &day);

    days_elapsed = day;
    for (int i = 0; i < month; i++)
    {
        days_elapsed += days_per_month[i];
    }

    printf("%s", day_string[(days_elapsed - 1) % 7].c_str());

    return 0;
}