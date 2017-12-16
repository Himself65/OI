#include<iostream>
#include<deque>
using namespace std;

struct Maxqueue {
    deque<int> q, m;
    void push(const int &x) {
        q.push_back(x);
        while (!m.empty() && m.back() < x) m.pop_back();
        m.push_back(x);
    }

    void pop() {
        int x = q.front();
        q.pop_front();
        if (x == m.front())
            m.pop_front();
    }

    int size() {
        return q.size();
    }

    bool empty() {
        return q.empty();
    }

    int top() {
        return m.front();
    }
};
int data[] = {1, 100, 20, 15, 24, 200, 10, 5, -1};
int main() {
    Maxqueue q;
    int length = 3;
    // 正确使用方法
    for (int i = 0; data[i] != -1; i++) {
        q.push(data[i]);
        if (i >= length)
            cout << q.top() << " ";
        if (q.size() >= length) {
            q.pop();
        }
    }
    return 0;
}