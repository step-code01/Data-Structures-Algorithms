#include <iostream>
using namespace std;
/*array approach, size increase decrease with vectors can*/
class queue{
    int *q;
    int top=-1;
    public:
    int isEmpty(){
        if (top==-1) {cout << "Queue is empty, underflow\n"; return 3;}
        else {return -3;}
    }
    int isFull(int elem){
        if (top == elem-1) {cout << "Queue is full, overflow\n"; return 3;}
        else {return -3;}
    }
    void enqueue(int *&q,int elem,int m){
        if (isFull(elem) == 3) {cout << "Can't add further elements\n"; return;}
        top++;
        q[top] = m;
        return;
    }
    void dequeue(int *&q,int elem){
        if (isEmpty()==3) {cout << "Can't remove elements\n"; return;}
        int i,j;
        for (i=0,j=i+1;j<elem;i++,j++) q[i] = q[j];
        top--; //forgot v.imp
        return;
    }
    void display(int *&q,int elem){
        int i;
        cout << "Queue: ";
        for (i=0;i<elem;i++) cout << q[i]; //<=top for present elements - non-zero if want to show vahi can if q[i]!=0 krke
        cout << endl;
        return;
    }
    void peek(int *&q, int elem){ //see top element
        cout << "Peek: " << q[0]; 
        cout << endl;
    }
};
int input(){
    cout << "Enter element: ";
    int m;
    cin >> m;
    return m;
}
int main(){
    int elem;
    cout << "Enter the no of elem in the queue: ";
    cin >> elem;

    int *q = new int[elem]; //ideally memory management to queue itself, not to another caller

    queue Q;
    
    cout << endl;
    cout << "\tWelcome to Queue menu:\n";
    cout << "What would you like to do today?\n";
    
    int choice;
    while (1){
        cout << "\t1.enqueue\n\t2.dequeue\n\t3.isEmpty\n\t4.isFull\n\t5.display\n\t6.peek\n\t7.exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                Q.enqueue(q,elem,input());
                break;
            case 2:
                Q.dequeue(q,elem);
                break;
            case 3:
                if (Q.isEmpty() == -3) cout << "Queue is not Empty \n";      
                break;
            case 4:
                if (Q.isFull(elem) == -3) cout << "Queue is not Full \n"; 
                break;
            case 5:
                Q.display(q,elem);
                break;
            case 6:
                Q.peek(q,elem);
                break;
            case 7:
                cout << "Exiting.. \n";
                exit (1);
        }    
    }
    delete[] q;
    return 0;
}