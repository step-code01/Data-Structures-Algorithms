#include <iostream>
using namespace std;

class Stack {
    int s[1000];
    int t;
public:
    Stack(){ t = -1; }
    void push(int v){ s[++t] = v; }
    int pop(){ return s[t--]; }
    int top(){ return s[t]; }
    bool empty(){ return t==-1; }
};

int main(){
    int n;
    cin>>n;
    int A[n],res[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
        res[i]=-1;
    }

    Stack st;
    for(int i=0;i<n;i++){
        while(!st.empty() && A[st.top()] >= A[i])
            st.pop();
        if(!st.empty())
            res[i]=A[st.top()];
        st.push(i);
    }

    for(int i=0;i<n;i++)
        cout<<res[i]<<" ";
}
