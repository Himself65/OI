#include <algorithm>
#include <cstdio>
#include <iostream>
std::pair<int, int> a[1005];
int main()
{
    int n;
    double sum = 0.0f;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i].first;
        a[i].second = i + 1;
    }

    std::sort(a, a + n);

    for (int i = 0; i < n; ++i)
    {
        sum += a[i].first * (n - i - 1);
        std::cout << a[i].second << ' ';
    }

    printf("\n%.2f", sum / n);

    return 0;
}