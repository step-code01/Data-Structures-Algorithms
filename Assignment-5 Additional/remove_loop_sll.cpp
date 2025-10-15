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
        while (walker != nullptr){
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
    void setaddr(int elem){
        node* walk = head;
        while (walk!=nullptr){
            if (walk->data == elem) break;
            walk = walk->next;
        }
        marker->next = walk;
    }
void remove_loop() {
    node* slow = head;
    node* fast = head;
    /*tortoise hare to detect cycle if there*/
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    /*if cycle not there*/
    if (fast == nullptr || fast->next == nullptr) {
        cout << "loop dne\n";
        return;
    }
    /*if cycle there*/
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    node* loopstart = slow;
    node* ptr = loopstart;
    while (ptr->next != loopstart) {
        ptr = ptr->next;
    }
    ptr->next = nullptr;
    cout << "Loop removed at node: " << loopstart->data << endl;
    }   
};
int main(){
    sll s1(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    //s1.setaddr(3);
    s1.setaddr(3);
    
    s1.remove_loop();
    s1.display();
}