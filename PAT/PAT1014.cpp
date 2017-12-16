#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string shit[4];
string date[] =
    {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
inline string find_date(char key) {
    string ans = "";
    switch (key) 
    {
        case 'A':
            ans = "10";
            break;
        case 'B':
            ans = "11";
            break;
        case 'C':
            ans = "12";
            break;
        case 'D':
            ans = "13";
            break;
        case 'E':
            ans = "14";
            break;
        case 'F':
            ans = "15";
            break;
        case 'G':
            ans = "16";
            break;
        case 'H':
            ans = "17";
            break;
        case 'I':
            ans = "18";
            break;
        case 'J':
            ans = "19";
            break;
        case 'K':
            ans = "20";
            break;
        case 'L':
            ans = "21";
            break;
        case 'M':
            ans = "22";
            break;
        case 'N':
            ans = "23";
            break;
    }
    return ans;
}
inline string split(string str,char key){
    int i = 0;
    string temp = "";
    while (str[i++] != key)
        ;
    i--;
    while(i++!=str.length())
        temp += str[i];
    return temp;
}
int main(){
    //读取输入
    for (int i = 0; i < 4; i++)
    {
        getline(cin, shit[i]);
    }
    //得到星期
    for (int i = 0; i <= 7; i++)
    {
        int temp1 = shit[0].find_first_of('A' + i, 0);
        int temp2 = shit[1].find_first_of('A' + i, 0);
        if (temp1 != -1 && temp2 != -1)
        {
            cout << date[i] + " ";
            shit[0] = split(shit[0], 'A' + i);
            shit[1] = split(shit[1], 'A' + i);
            break;
        }
    }
    //得到小时
    bool first = true;
    for (int i = 0; i <= 9; i++)
    {
        int temp1 = shit[0].find_first_of('0' + i, 0);
        int temp2 = shit[1].find_first_of('0' + i, 0);
        if (temp1 != -1 && temp2 != -1)
        {
            printf("%d", i);
            first = false;
            break;
        }
    }
    if(first)
    for (char i = 'A'; i <= 'N'; i++)
    {
        int temp1 = shit[0].find_first_of(i, 0);
        int temp2 = shit[1].find_first_of(i, 0);
        if (temp1 != -1 && temp2 != -1)
        {
            printf("%2d", i - 'A' + 10);
            break;
        }
    }
    cout << ":";
    //得到分钟
    //from 065 to 122
    for (int i = 65; i <= 122; i++)
    {
        int temp1 = shit[2].find_first_of(i, 1);
        int temp2 = shit[3].find_first_of(i, 1);
        if (temp1 == -1 || temp2 == -1)
            continue;
        else
        {
            printf("%02d", temp2);
            break;
        }
    }
    //system("pause");
    return 0;
}
