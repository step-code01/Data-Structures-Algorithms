#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q; 

public:
    void push(int x) {
        q.push(x); 
        int n = q.size();
        int i;
        for (i= 0;i<n-1;i++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    void pop() {
        if (!q.empty()) {
            q.pop();
        } else {
            cout << "Stack is empty\n";
        }
    }

    int top() {
        if (!q.empty())
            return q.front();
        cout << "Stack is empty\n";
        return -1;
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top: " << s.top() << endl;
    s.pop();
    s.push(4);
    cout << "Top: " << s.top() << endl;

    return 0;
}
