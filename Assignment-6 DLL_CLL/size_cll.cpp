#include <iostream>
using namespace std;

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
        
        //default next one zero set cuz of way i defined class
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
    void deletion(int poselem){ //all 3 act in one that's why
        node* walker = head;
        while (walker->next->data != poselem){
            walker = walker->next;
        }
        /*from end*/
        if (poselem == marker->data){
            walker->next = head;
            delete marker; 
            marker = walker;
        }
        /*from start*/
        else if (poselem == head->data){
            walker = head;
            head = head->next;
            marker->next = head;
            delete walker;
        }
        /*in between*/
        else{
            node* after = walker->next;
            walker->next = after->next;
            delete after;
        }
    }
    void search(int poselem){
        count = 0; //need to reset it for each run, v.imp
        node* searcher = head;
        while (searcher->data != poselem){
            searcher = searcher->next;
            count++;
        }
        cout << "Element is " << count+1 << " position from the head (head = 1) \n";
    }
    void size_cll(){ 
        int ctr = 0;
        node* walker = head->next;
        ctr++;
        while (walker != head){ //or line 109 ki jagah yahan head->next but phir 2 aage krna pdta 
            walker = walker->next;
            ctr++;
        }  
        cout << "No of elements of CLL (size): " << ctr;
    }
};
int main(){
    cll l1;
    l1.insert(4);
    l1.insert(3);
    l1.display();
    l1.size_cll();
}
/*tortoise hare (not circular but end of list tk vo, is best for this, else normal can
in cll what if we didn't know start point then dikkat
start can be any type qs*/