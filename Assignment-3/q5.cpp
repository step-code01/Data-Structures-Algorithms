#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char ch) {
    return (ch >= '0' && ch <= '9');
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    stack<int> st;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (isOperand(ch)) st.push(ch - '0');
        else {
            // operator case - pop two operands
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            int res = 0;

            if (ch == '+') res = op1 + op2;
            else if (ch == '-') res = op1 - op2;
            else if (ch == '*') res = op1 * op2;
            else if (ch == '/') res = op1 / op2;

            st.push(res);
        }
    }

    cout << "result: " << st.top() << endl;
    return 0;
}
