#include <iostream>
#define MAX_SIZE 5

using namespace std;

class Queue {
public:
    int front, rear;
    int arr[MAX_SIZE];
    Queue() { 
        front = 0;
        rear = 0; 
    }
    bool isFull() {
        if ((rear+1)%MAX_SIZE==front) {
            return true;
        }
        return false;
    }
    bool isEmpty() {
        if (front==rear) return true;
        return false;
    }
    void enqueue(int val) {
        if (isFull()) {
            cout << "overflow" << endl;
            return;
        }
        rear = (rear+1) % MAX_SIZE;
        arr[rear] = val;
        cout << val << " enqueued" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "underflow" << endl;
            return;
        }
        front = (front+1) % MAX_SIZE;
        cout << "ele dequeued" << endl;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1; 
        }
        return arr[(front+1)%MAX_SIZE];
    }
    void display() {
        if (isEmpty()) {
            cout << "\nqueue is empty" << endl;
            return;
        }
        cout << "\nqueue elements: ";
        int i=front;
        do {
            i=(i+1)%MAX_SIZE;
            cout << arr[i] << " ";
        } while (i != rear);
        cout << endl;
    }
};
int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---" << endl;
        cout << "1. Enqueue (Add)" << endl;
        cout << "2. Dequeue (Remove)" << endl;
        cout << "3. Display" << endl;
        cout << "4. Peek (Front Element)" << endl; //imp
        cout << "5. Is Empty?" << endl;
        cout << "6. Is Full?" << endl;
        cout << "0. Exit" << endl;
        cout << "---------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                value = q.peek();
                if (value != -1) cout << "\nFront element is: " << value << endl;
                break;
            case 5:
                if (q.isEmpty()) cout << "\nResult: Queue is empty." << endl;
                else cout << "\nResult: Queue is not empty." << endl;
                break;
            case 6:
                if (q.isFull()) cout << "\nResult: Queue is full." << endl;
                else cout << "\nResult: Queue is not full." << endl;
                break;
            case 0:
                cout << "\nExiting program." << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

