#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int isinterger(double x)
{
    return x - (int)x == 0;
}

int main()
{
    char s[105];
    scanf("%s", s);
    int len = strlen(s);
    int sc = 0, sh = 0, so = 0;
    for (int i = 0; i < len; i++)
        if (s[i] >= '1' && s[i] <= '9')
        {
            int vis = i - 1, c = 0, v = 0;
            for (; s[i] >= '1' && s[i] <= '9'; i++)
                c++;
            for (int j = vis + 1; j < vis + 1 + c; j++)
                v = v * 10 + s[j] - '0';
            if (s[vis] == 'C')
            {
                sc += v;
                s[vis] = ' ';
            }
            if (s[vis] == 'H')
            {
                sh += v;
                s[vis] = ' ';
            }
            if (s[vis] == 'O')
            {
                so += v;
                s[vis] = ' ';
            }
        }
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'C')
            sc++;
        if (s[i] == 'H')
            sh++;
        if (s[i] == 'O')
            so++;
    }
    double numco2 = sc, numh2o = sh / 2.0, numo2 = sc + sh / 4.0 - so / 2.0;

    while ((!(isinterger(numco2))) || (!(isinterger(numh2o))) || (!(isinterger(numo2))))
    {
        numco2 *= 2;
        numh2o *= 2;
        numo2 *= 2;
    }
    printf("%d %d", (int)numco2, (int)numh2o);
}