#include <iostream>
using namespace std;
#define MAXLEN 100

struct Stack {
    int element[MAXLEN];
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

int peek(Stack S) {
    if (isEmpty(S)) {
        cout << "stack is empty!" << endl;
        return -1;
    } else {
        return S.element[S.top];
    }
}

Stack push(Stack S, int x) {
    if (isFull(S)) {
        cout << "stack overflow!" << endl;
    } else {
        S.top++;
        S.element[S.top] = x;
    }
    return S;
}

Stack pop(Stack S) {
    if (isEmpty(S)) {
        cout << "stack underflow!" << endl;
    } else {
        cout << "popped ele: " << S.element[S.top] << endl;
        S.top--;
    }
    return S;
}

void display(Stack S) {
    if (isEmpty(S)) {
        cout << "stack empty" << endl;
    } else {
        cout << "stack elements: ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.element[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Stack S = init();
    int choice, val;
    
    do {
        cout << "\nStack Menu\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "enter val to push: ";
                cin >> val;
                S = push(S, val);
                break;
            case 2:
                S = pop(S);
                break;
            case 3:
                if (isEmpty(S)) cout << "stack empty." << endl;
                else cout << "stack not Empty." << endl;
                break;
            case 4:
                if (isFull(S)) cout << "stack full." << endl;
                else cout << "stack not full." << endl;
                break;
            case 5:
                display(S);
                break;
            case 6:
                val = peek(S);
                if (val != -1) cout << "top element: " << val << endl;
                break;
            case 7:
                cout << "exiting..." << endl;
                break;
            default:
                cout << "invalid choice" << endl;
        }
    } while(choice != 7);
    
    return 0;
}
