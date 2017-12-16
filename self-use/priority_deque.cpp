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

    int size(){
        return q.size();
    }

    int top() {
        return m.front();
    }
};

int main() {
    Maxqueue q;
    return 0;
}