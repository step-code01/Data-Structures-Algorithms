#include <iostream>
using namespace std;
class node{
    int data;
    node* next;
    public:
    node(){
        data = 0;
        next = 0;
    }
    node(int d, node* n = 0){
        data = d;
        next = n;
    }
    friend class sll;
};
class sll{
    node* head;
    node* marker;
    public:
    sll(int l){
        head = new node(l);
        marker = head;
    }
    void insert(int l){
        node* nextNode = new node(l);
        marker->next = nextNode;
        marker = marker->next;
    }
    void insertstart(int l){
        node* newhead = new node(l);
        newhead->next = head;
        head = newhead;
    }
    void insertafter(int l, int poselem){
        node* walker = head;
        while (walker->data != poselem){
            walker = walker->next;
        }
        node* newNode = new node(l);
        newNode->next = walker->next;
        walker->next = newNode;
    }
    void insertbefore(int l, int poselem){ 
        node* walker = head;
        while (walker->next->data != poselem){ 
            walker = walker->next;
        }
        node* newNode = new node(l);
        newNode->next = walker->next;
        walker->next = newNode;
    }
    void display(){
        cout << "Linked list:" << endl;
        node* walker = head;
        while (walker != 0){
            cout << walker->data; 
            if (walker->next != 0) cout << "-> "; 
            walker = walker->next;
        }
        cout << endl;
    }
    void deletion(){ 
        node *walker = head;
        while (walker->next->next != 0){
            walker = walker->next;
        }
        walker->next = 0;
        delete marker;
        while (walker!= 0){
            walker = walker->next;
        }
        marker = walker;
    }
    void deletionstart(){
        node* temp = head;
        head = head->next;
        delete temp;
    }
    void deletionelem(int l){
        node* del = head; 
        while(del->next->data != l){
            del = del->next;
        }
        node* temp = del;
        del=del->next; 
        delete del;
    }  
    void rotate_sll(int k, sll l){
        node* walker;
        
        while (k--){
        walker = head;
        marker->next = head;
        head = head->next;
        walker->next = nullptr;
        marker = marker->next;
        }
        cout << "Updated head:" << head->data <<endl;
    }
};

int main(){
    int k;
    cout << "Enter no of steps to left-rotate sll by: ";
    cin >> k;

    sll l1(10);
    l1.insert(20);
    l1.insert(30);
    l1.insert(40);
    l1.insert(50);

    l1.display();
    l1.rotate_sll(k,l1);
    l1.display();
    return 0;
}
