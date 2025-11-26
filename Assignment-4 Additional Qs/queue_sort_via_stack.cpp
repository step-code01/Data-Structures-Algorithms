#include <iostream>
using namespace std;

class Stack{
    int s[1000];
    int t;
public:
    Stack(){t=-1;}
    void push(int v){s[++t]=v;}
    int pop(){return s[t--];}
    int top(){return s[t];}
    bool empty(){return t==-1;}
};

class Queue{
    int q[1000];
    int f,r;
public:
    Queue(){f=0;r=0;}
    void push(int v){q[r++]=v;}
    int pop(){return q[f++];}
    bool empty(){return f==r;}
    int front(){return q[f];}
};

int main(){
    int n;
    cin>>n;
    Queue in,out;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        in.push(x);
    }
    Stack st;
    int expected=1;
    while(!in.empty()){
        int v=in.front();
        in.pop();
        if(v==expected){
            out.push(v);
            expected++;
            while(!st.empty() && st.top()==expected){
                out.push(st.pop());
                expected++;
            }
        } else {
            st.push(v);
        }
    }
    cout<<(expected==n+1 ? "Yes" : "No");
}
