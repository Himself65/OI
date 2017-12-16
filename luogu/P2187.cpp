#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<map>
#define LOCAL
using namespace std;
int n, m;
string str;
int ans = 0;
map<char, char> mp;
inline bool can(char a,char b) {
    if (mp.find(a) == mp.end() || mp.find(b) == mp.end())
        return true;
    return false;
}

inline void solve(char a, char b) {
    for (int i = 0; i < str.length(); i++) {
        int j = i + 1;
        if ((str[i] == a && str[j] == b) || (str[i] == b && str[j] == a))
        {
            ans++;
        //    str.erase(i);
        //   printf("%s\n", str.c_str());
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("debug\\P1287.in", "r", stdin);
    freopen("debug\\P1287.out", "w", stdout);
#endif
    scanf("%d", &n);
    cin >> str;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char t1;
        cin >> t1;
        char t2;
        cin >> t2;
        if (can(t1, t2))
        {
            solve(t1, t2);
            mp[t1] = t2;
        }
    }
    printf("%d", ans);
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
//    system("pause");
    return 0;
}

// printf("%d", &x);