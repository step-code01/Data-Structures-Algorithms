#include <iostream>
using namespace std;

class Queue{
    int *arr;
    int front;
    int rear;
    int size;
public:
    Queue(){
        cout<<"Enter the size:";cin>>size;
        arr=new int[size];
        front=0;rear=-1;
    }
    ~Queue(){
        delete[] arr;
        cout<<"Object Destroyed\n";
    }
    void enqueue(int x){
        if(rear==size-1){cout<<"overflow\n";return;}
        rear++;
        arr[rear]=x;
    }
    void dequeue(){
        if(isEmpty()){cout<<"underflow\n";return;}
        front++;
    }
    int peek(){
        if(isEmpty()){cout<<"empty\n";return -1;}
        return arr[front];
    }
    bool isEmpty(){
        if(front>rear){ //when emptied, reset so we can reuse
            front=0;rear=-1;
            return true;
        }
        return false;
    }
    void reset(){
        front=0;rear=-1;
    }
    void swapQ(Queue &r){ 
        std::swap(arr,r.arr);
        std::swap(front,r.front);
        std::swap(rear,r.rear);
        std::swap(size,r.size);
    }
    void display(){
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void stack_implement(Queue &Q1,Queue &Q2){
    int n;cout<<"Enter no of ele?";
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cout<<"Enter element:";
        cin>>x;
        Q2.enqueue(x);
        while(!Q1.isEmpty()){
            Q2.enqueue(Q1.peek());
            Q1.dequeue();
        }
        Q1.swapQ(Q2);
        cout<<"Afterpush "<< x <<": "; 
        Q1.display();
    }
    cout<<"Popping order(LIFO): \n";
    while(!Q1.isEmpty()){
        cout<<Q1.peek()<<" ";
        Q1.dequeue();
    }
    cout<<endl;
}

int main(){
    Queue Q1,Q2;
    stack_implement(Q1,Q2);
}
