#include <iostream>
using namespace std;

class Stack {
    int s[1000];
    int t;
public:
    Stack(){t=-1;}
    void push(int v){s[++t]=v;}
    int pop(){return s[t--];}
    int top(){return s[t];}
    bool empty(){return t==-1;}
};

class Queue {
    int q[1000];
    int f,r;
public:
    Queue(){f=0;r=0;}
    void push(int v){q[r++]=v;}
    int pop(){return q[f++];}
    int front(){return q[f];}
    bool empty(){return f==r;}
    void rotate(){q[r++]=q[f++];}
};

int main(){
    int n;
    cin>>n;
    Queue students;
    Queue sandwiches;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        students.push(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sandwiches.push(x);
    }

    Stack st;
    for(int i=0;i<n;i++){
        st.push(sandwiches.front());
        sandwiches.pop();
    }

    int turns=0;
    while(!students.empty() && !st.empty() && turns<n){
        if(st.top()==students.front()){
            st.pop();
            students.pop();
            turns=0;
        } else {
            students.rotate();
            turns++;
        }
    }

    int unable=0;
    while(!students.empty()){
        unable++;
        students.pop();
    }
    cout<<unable;
}
