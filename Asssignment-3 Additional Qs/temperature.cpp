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
    cin >> n;
    int arr[n];
    int ans[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        ans[i] = 0;
    }

    Stack st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i] > arr[st.top()])
            ans[st.pop()] = i - st.top() - 1;
        st.push(i);
    }

    for(int i=0;i<n;i++)
        cout << ans[i] << " ";
}
