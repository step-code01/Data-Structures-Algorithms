#include <iostream>
#include <stack>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

bool isBalanced(string expr) {
    stack<char> st; //using stack directly now, not implementing from scratch
    for (int i = 0; i < expr.length(); i++){
        char ch = expr[i];
        
        if (ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']'){
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if (!isMatching(top, ch)) return false;
        }
    }
    return st.empty(); 
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr; 
    
    if (isBalanced(expr)) cout << "Balanced expression" << endl;
    else cout << "Not balanced" << endl;
        
    return 0;
}
