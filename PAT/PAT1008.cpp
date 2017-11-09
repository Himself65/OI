/*
    一个数组A中存有N（N>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（M>=0）个位置，即将A中的数据由（A0 A1……AN-1）变换为（AN-M …… AN-1 A0 A1……AN-M-1）（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

    输入格式：每个输入包含一个测试用例，第1行输入N ( 1<=N<=100)、M（M>=0）；第2行输入N个整数，之间用空格分隔。

    输出格式：在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

    输入样例：
    6 2
    1 2 3 4 5 6
    输出样例：
    5 6 1 2 3 4
*/
#include<iostream>
#define maxn (100)
using namespace std;
int shit[maxn];
int n, m;
 
inline void reverse(int left, int right)
{
    while(left < right)
    {
        int temp = shit[left];
        shit[left] = shit[right];
        shit[right] = temp;

        left++;
        right--;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
       cin >> shit[i];
    }
    
    while(m > n)
        m -= n;
    m = n - m;
    
    reverse(0, m - 1);
    reverse(m, n - 1);
    reverse(0, n - 1);

    for (int i = 0; i < n;i++)
    {
        cout << shit[i];
        if(i != n-1)
            cout<<" ";
    }
//    system("pause");
    return 0;
}