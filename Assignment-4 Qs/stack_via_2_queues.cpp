#include <iostream>
#include <limits.h>
using namespace std;

class Queue{
    int *arr;
    int top;
    int end;
    int size;
    public:
    Queue(){
        cout << "Enter the no of elements in the queue: ";
        cin >> size;
        arr = new int[size];
        top = -1;
        end = -1; //index cuz
    }
    ~Queue(){
        delete[] arr;
        cout << "Object Destroyed\n";
    }
    void enqueue(int c){
        end++;
        arr[end] = c;
        return;
    }
    void dequeue(){
        top++;
        arr[top] = INT_MIN; //printing me isko replace as gap, or take a number that user won't use, -2 baaki sab number daal toh skte hi ho isliye doing 
        return;
    }
    void display(){
        int i;
        for (i=0;i<size;i++){
            if (arr[i] != INT_MIN) cout << arr[i] << " ";
            else cout << "# ";
        }
        cout << endl;
    }
    bool isEmpty(){
        if (top==end && end == -1) {cout << "queue is empty"; return true;} //return 1 bhi chalega na?
        else return false; 
    }
    bool isFull(){
        if (top==end && end == -1) {cout << "queue is full"; return true;} //return 1 bhi chalega na?
        else return false; 
    }
    void peek(){ //first elem
        cout << arr[top];
        return;
    }
};

int main(){
    Queue Q;

    Q.enqueue(4);
    Q.enqueue(5);
    Q.display();
    Q.isEmpty();
    Q.isFull();
    Q.dequeue();
    Q.display();
    Q.enqueue(6);
    Q.display();
}

//arr[top] = ' '; //v.imp ascii store 
//int_min bhi num hai voh bhi technically koi daal hi skta hai
//phir empty dikhau kaise? - only way- ask the user which number he isn't going to input, v.imp