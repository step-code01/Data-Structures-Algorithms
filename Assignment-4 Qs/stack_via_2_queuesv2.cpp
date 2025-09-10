#include <iostream>
using namespace std;

class Queue{
    int *arr;
    int top;
    int end;
    int size;
    int num;
    public:
    Queue(){
        cout << "Enter the no of elements in the queue: ";
        cin >> size;
        arr = new int[size];
        top = -1;
        end = -1; //index cuz
        cout << "Enter a number that you aren't going to put in queue: ";
        cin >> num;
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
        arr[top] = num; //printing me isko replace as gap, or take a number that user won't use, -2 baaki sab number daal toh skte hi ho isliye doing 
        return;
    }
    void display(){
        int i;
        for (i=0;i<=end;i++){ //v.imp don't display full, only till elements filled
            if (arr[i] != num) cout << arr[i] << " ";
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
    int peek(){ //first elem ,v.imp rem to keep it int
        //cout << arr[top];
        return arr[top];
    }
    friend void stack_implement(Queue Q, Queue Q2); 
};
void stack_implement(Queue Q, Queue Q2){ //yeh vulnerable nhi bana dega? iske thru pvt fields alter krdu toh
    int i=3;
    int c;
    int l;
    bool flipper = false;
    do{
        cout << "Enter the 1st element: ";
        cin >> c;
        Q.enqueue(c);
        cout << "Enter the 2nd element: ";
        cin >> c;
        Q2.enqueue(c);

        l = Q.peek();
        Q2.enqueue(l);
        Q.dequeue();
        flipper = true; //flipper true means Q is empty, flipper false means Q2 is empty
    }
    while(Q.isFull() || Q2.isFull()){
        cout << "Enter the " << i << "th element: ";
        if (flipper==true){ //means Q is empty//empty queue me copy elements
            while (Q.isEmpty()){
                l = Q2.peek();
                Q.enqueue(l);
                Q2.dequeue();
                flipper = false;
            }}
        else { //means Q2 is empty 
            while(Q2.isEmpty()){
                l = Q.peek();
                Q2.enqueue(l);
                Q.dequeue();
                flipper = true;
            }
        }
    }
}
int main(){
    Queue Q;
    Queue Q2;

    stack_implement(Q,Q2);
}

//arr[top] = ' '; //v.imp ascii store 
//int_min bhi num hai voh bhi technically koi daal hi skta hai
//phir empty dikhau kaise? - only way- ask the user which number he isn't going to input, v.imp

/*4 5 0 0 
# 5 0 0 
# 5 6 0 
Object Destroyed

actual 0 and compiler 0 me diff ke lyie only display till end - denoting last element kb tk hai
and space left in queue report at each step*/

/*    for (i=0;i<Q.size;i++){ //both queues size toh same hi
        cout << "Enter the " << i << "th element: ";
        if ()
    }
    do while better lgra*/