#include <iostream>
using namespace std;
class cll;
class node{
    int data;
    node* next;
    public:
    node(){ //default 
        data = 0;
        next = nullptr;
    }
    node(int d, node* n = nullptr){
        data = d;
        next = n;
    }
    friend class cll;
    friend void cll_checker(cll l1);
};
class cll{
    node* head;
    node* marker;
    int count;
    public:
    cll(){
        int d;
        cout << "Enter data of node: ";
        cin >> d;
        head = new node(d);
        marker = head;
        count = 0;
    }
    void insert(int d){
        node* newNode = new node(d);
        
        marker->next = newNode;
        newNode->next = head;
        marker = marker->next;
    }
    void display(){
        node* walker = head;
        cout << walker->data;
        if (marker != head) cout << "->";
        walker = walker->next;
        if (marker != head){
            while (walker != head){  
                cout << walker->data;
                walker = walker->next;
                if (walker != head) cout << "->";
        }}
        cout << endl;
        /*do while best for this*/
    }
    void insertstart(int d){
        node* walker = head;
        node* newNode = new node(d);

        marker->next = newNode;
        newNode->next = walker;
        head = newNode;
    }
    void insertafter(int d,int poselem){
        node* walker = head;
        while (walker->data != poselem){
            walker = walker->next;
        }
        node* after = walker;
        after = after->next;

        node* newNode = new node(d);
        newNode->next = after;
        walker->next = newNode;
    }
    int size_cll(){ 
        int ctr = 0;
        node* walker = head->next;
        ctr++;
        while (walker != head){ //or line 109 ki jagah yahan head->next but phir 2 aage krna pdta 
            walker = walker->next;
            ctr++;
        }  
        //cout << "No of elements of CLL (size): " << ctr;
        return ctr;
    }
    friend void cll_checker(cll l1);
};
void cll_checker(cll l1){
    node* slow = l1.head;//tortoise
    node* fast = l1.head;//hare

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            cout << "True\n"; //circular hai
            return;
        }
    }
    cout << "False\n";
}
/*max 1 circle me toh catch kar hi lega agar circular ll hai toh since speeds 1,2
guaranteed to catch up*/
int main(){
    cll l1;
    l1.insert(4);
    l1.insert(3);
    l1.insert(2);
    l1.display();
    cll_checker(l1);
}

/*void cll_checker(cll l1){ //this algo must tell cll or not - it doesn't know what input it'll get
    node* tortoise = l1.head;
    node* hare = l1.head;
    int count = l1.size_cll();
    int s_ctr = 0;

    while (s_ctr != count){
        tortoise = tortoise->next;
        hare = hare->next->next; 
        s_ctr++;

        if (tortoise == hare){
            cout << "\nTrue\n";
            return;
        }
    }
    cout << "\nFalse\n";
    return;
}
only if pure circular linked list
*/