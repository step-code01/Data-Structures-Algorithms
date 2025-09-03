#include <iostream>
using namespace std;
/*array approach, size increase decrease with vectors can*/
class Queue{
    int *q;
    int capacity;
    int top; //give value in constructor, allocate memory in constructor - better way
    public:
    Queue(int cap){ //better way than before
        capacity = cap;
        q = new int[capacity];
        top=-1;
    }
    ~Queue(){
        delete[] q;
    }
    int isEmpty(){
        if (top==-1) {cout << "Queue is empty, underflow\n"; return 3;}
        else {return -3;}
    }
    int isFull(){
        if (top == capacity-1) {cout << "Queue is full, overflow\n"; return 3;}
        else {return -3;}
    }
    void enqueue(int m){
        if (isFull() == 3) {cout << "Can't add further elements\n"; return;}
        top++;
        q[top] = m;
        return;
    }
    void dequeue(){
        if (isEmpty()==3) {cout << "Can't remove elements\n"; return;}
        int i,j;
        for (i=0,j=i+1;j<capacity;i++,j++) q[i] = q[j];
        top--;
        return;
    }
    void display(){
        int i;
        cout << "Queue: ";
        for (i=0;i<capacity;i++) cout << q[i] << " "; //<=top for present elements - non-zero if want to show vahi can if q[i]!=0 krke
        cout << endl;
        return;
    }
    int peek(){ //see top element
        return q[0];
    }
};
int input(){
    cout << "Enter element: ";
    int m;
    cin >> m;
    return m;
}
void interleave(Queue &Q, Queue &Q1, Queue &Q2,int cap){
    int i;
    bool flip=true; //default true - corr to Q1
    /*just put back in order*/
    for (i=0;i<cap/2;i++){
        int l = Q.peek();
        Q1.enqueue(l);
        Q.dequeue();
    } 
    for (i=0;i<cap/2;i++){
        int l = Q.peek();
        Q2.enqueue(l);
        Q.dequeue(); 
    }
    Q1.display();
    Q2.display();

    for (i=0;i<cap;i++){ //since Q.capacity baaki are private no
        int l; 
        if (flip==true){
            l=Q1.peek();
            Q.enqueue(l);
            Q1.dequeue();
            flip=false; 
        }
        else if (flip==false){
            l=Q2.peek();
            Q.enqueue(l);
            Q2.dequeue();
            flip=true;
        }
    }
    cout << "Interleaved ";
    Q.display();
}
int main(){
    int cap;
    cout << "Enter the no of elem in the master queue: ";
    cin >> cap;

    Queue Q(cap); //master queue
    cout << "Enter the elements in master queue:" ;
    int l;
    int i;
    for (i=0;i<cap;i++){
        cin >> l;
        Q.enqueue(l);
    }

    Queue Q1(cap/2),Q2(cap/2); //subqueues, assuming even ele so that proper halves aaye

    interleave(Q,Q1,Q2,cap);
    return 0;
}

/*last one - memory management queue should have for itself, because when u implement multiple queues
then can't do it in main !*/