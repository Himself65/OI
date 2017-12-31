#include<iostream>
using namespace std;
const int maxn = 1000 + 5;

struct MinHeap
{
    int heap[maxn];
    int size;

    MinHeap() : size(0){}

    inline void push(int x)
    {
        int i = size++;
        while (i > 0)
        {
            int p = father(i);
            if (heap[p] <= x)
                break;
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = x;
    }

    inline int pop()
    {
        int ret = heap[0]; // 返回顶部

        // 调整位置
        int x = heap[--size];

        int i = 0;
        while (left(i) < size)
        {
            int a = left(i);
            int b = right(i);
            if (b < size && heap[b] < heap[a])
                a = b;
            if (heap[a] >= x)
                break;
            heap[i] = heap[a];
            i = a;
        }
        heap[i] = x;

        return ret;
    }
    
    inline bool empty()
    {
        return size <= 0;
    }

    inline int father(int x)
    {
        return (x - 1) / 2;
    }

    inline int left(int x)
    {
        return x * 2 + 1;
    }

    inline int right(int x)
    {
        return x * 2 + 2;
    }
};

int main()
{
    MinHeap mh;
    mh.push(1);
    mh.push(100);
    mh.push(40);
    mh.push(20);
    while(!mh.empty())
    {
        cout<< mh.pop() << " " << mh.size << endl;
    }
    return 0;
}