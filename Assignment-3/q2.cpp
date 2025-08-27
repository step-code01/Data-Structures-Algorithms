/*reusing code from q1*/
#include <iostream>
using namespace std;
#define MAXLEN 100

struct Stack {
    char element[MAXLEN];
    int top;
};

Stack init() {
    Stack S;
    S.top = -1;
    return S;
}

bool isEmpty(Stack S) {
    return (S.top == -1);
}

bool isFull(Stack S) {
    return (S.top == MAXLEN - 1);
}

Stack push(Stack S, char x) {
    if (isFull(S)) {
        cout << "Stack Overflow!" << endl;
    } else {
        S.top++;
        S.element[S.top] = x;
    }
    return S;
}

char pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    } else {
        char ch = S.element[S.top];
        S.top--;
        return ch;
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;  
    
    Stack S = init();
    
    for (int i = 0; i < str.length(); i++) {
        S = push(S, str[i]);
    }
    
    string rev = ""; 
    while (!isEmpty(S)) {
        char ch = pop(S);
        rev = rev + ch;
    }
    
    cout << "reversed string: " << rev << endl;
    return 0;
}
