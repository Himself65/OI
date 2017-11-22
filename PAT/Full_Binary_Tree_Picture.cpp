#include <iostream>
#include <stack>
using namespace std;

int width[20];
struct Node{
    int x;
    int y;
    Node* r;
    Node* l;
    
    Node(int x, int y){
        this->x = x;
        this->y = y;
        this->r = NULL;
        this->l = NULL;
    }
};

inline void init(){
    width[0] = 0;
    width[1] = 0;
    width[2] = 1;
    width[3] = 2;
    width[4] = 5;
    for (int i = 5; i < 20; i++)
    {
        width[i] = width[i-1]*2 + 1;
    }
}

inline void insert(int h, Node * root){
    if(h == 1) return;
    root->r = new Node(root->x + width[h] + 1, root->y + width[h] + 1);
    root->l = new Node(root->x - width[h] - 1, root->y + width[h] + 1);
    insert(h-1, root->r);
    insert(h-1, root->l);
}

inline int check(Node *p, int x1, int y1, int x2, int y2)
{
    int count = 0;
    stack<Node *> stack;
    while (p || !stack.empty()) {
        if(p != NULL) {
            stack.push(p);
            p = p->l;
        } else {
            p = stack.top();
            stack.pop();
            int x = (*p).x;
            int y = (*p).y;
            if (y <= y2 && y >= y1 && x <= x2 && x >= x1)
                count++;
            p = p->r;
        }
    }
    return count;
}

int main(){
    init();
    Node* root = new Node(0, 0);
    int h; int n;
    cin>>h>>n;
    insert(h, root);

    for(int i = 0; i<n; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = check(root, y1, x1, y2, x2);
        cout<<sum<<endl;
    }
    // system("pause");
    return 0;
}
