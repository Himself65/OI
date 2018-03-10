#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int sigma_size = 26; // 有26个字母
const int maxn = (int)1e+6;
struct Trie
{
    int count;
    int son[sigma_size];
    bool exist;
    Trie()
    {
        count = 0;
        exist = false;
        memset(son, 0, sizeof(son));
    }
} trie[maxn];
inline int idx(char c) { return c - 'a'; }
int num;
inline void insert(char *s)
{
    int v, len = strlen(s);
    int u = 0;
    for (int i = 0; i < len; i++)
    {
        v = idx(s[i]);
        if (!trie[u].son[v])        // 如果存在
            trie[u].son[v] = ++num; // 计数++
        u = trie[u].son[v];         // 寻找下一个儿子
    }
    trie[u].exist = true; // 标记存在
}
#define EXIST 3
#define REPEAT 2
#define NOTYET 1
inline int find(char *s)
{
    int v, len = strlen(s);
    int u = 0;
    for (int i = 0; i < len; i++)
    {
        v = idx(s[i]);
        if (!trie[u].son[v])
            return EXIST;
        u = trie[u].son[v];
    }
    if (!trie[u].exist)
        return EXIST;
    if (!trie[u].count)
    {
        trie[u].count++;
        return NOTYET;
    }
    return REPEAT;
}
int n, m;
char name[100];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", name);
        insert(name);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%s", name);
        int p = find(name);
        if (p == NOTYET)
            puts("OK");
        else if (p == REPEAT)
            puts("REPEAT");
        else if (p == EXIST)
            puts("WRONG");
    }
    return 0;
}
