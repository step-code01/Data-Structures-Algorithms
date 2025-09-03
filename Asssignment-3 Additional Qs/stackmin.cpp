#include <iostream>
#include <stack>
using namespace std;

int getMin(stack<int> st,int size){
    stack<int> min;
    int i;
    for (i=0;i<size;i++){
        if (i==0) min.push(st.top()); //pahla ele as min assume
        if (st.top() < min.top()){
            min.pop();
            min.push(st.top());
        }
        st.pop();
    }
    cout << "Min value: " << min.top();
    return 0;
}
int main(){
    stack<int> st;
    
    int size,elem;
    cout << "Enter no of elements you want to enter: ";
    cin >> size;
    cout << "Enter elements in stack:" ; 
    int i;
    for (i=0;i<size;i++){
        cin >> elem;
        st.push(elem);
    }
    getMin(st,size);
    return 0;
}
