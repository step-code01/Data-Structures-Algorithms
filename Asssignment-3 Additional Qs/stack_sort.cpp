#include <iostream>
using namespace std;

class Stack {
    int s[10000];
    int t;
public:
    Stack(){ t = -1; }
    void push(int v){ s[++t] = v; }
    int pop(){ return s[t--]; }
    int top(){ return s[t]; }
    bool empty(){ return t == -1; }
};

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];

    Stack st;
    int B[n];
    int bi = 0;
    int ai = 0;
    int last = -1;

    while(ai < n || !st.empty()){
        if(ai < n) {
            st.push(A[ai]);
            ai++;
        } else {
            int v = st.pop();
            B[bi++] = v;
        }
    }

    bool ok = true;
    for(int i=0;i<last+1;i++){
        if(i==0) last = B[0];
        else {
            if(B[i] < last) { ok = false; break; }
            last = B[i];
        }
    }

    cout<<(ok ? "YES" : "NO");
}
