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
        
        marker->next = newNode;
        newNode->next = head;
        marker = marker->next;
    }
    void displayhead(){
        node* walker = head;
        for (int i=0;i<2;i++){
            cout << walker->data;
            if (marker != head) cout << "->";
            walker = walker->next;
        }
        if (marker != head){
            while (walker != head->next){  
                cout << walker->data;
                walker = walker->next;
                if (walker != head->next) cout << "->";
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
};
int main(){
    cll l1;
    l1.insert(100);
    l1.insert(40);
    l1.insert(80);
    l1.insert(60);
    l1.displayhead();
}