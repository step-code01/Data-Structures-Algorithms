#include <iostream>
using namespace std;
class node{
    int data;
    node *next;
    public:
    node(){
        data=0;
        next=0;
    }
    node(int elem, node* next = 0){
        data = elem;
        this->next = next;
    }
    void get(){
        cout << "Data in node: " << data << endl;
        cout << "Address of next element: " << next << endl;
    }
    friend class Sll;   
};
class Sll{
    node* head;
    node* walker; 
    public:
    Sll(int l){
        node* n = new node(l);
        head = n;
        walker = head;
    }   
    void insert(int newdata){
        node* newNode = new node(newdata);
        walker->next = newNode; 
        walker = newNode;
    }
    void dispshort(){
        cout << "Linked List: \n";
        node *display = head;
        while (display != 0){ 
            cout << display->data << "-> ";
            display = display->next; 
        }
        cout <<endl;
    }
    void insert(int newdata, int elem){
        node *finder = head; 
        while (finder->data != elem){
            finder = finder->next;
        }
        node *newinsert = new node(newdata); 
        newinsert->next = finder->next; 
        finder->next = newinsert;
    }
    void insertStart(int newh){
        node *newhead = new node(newh);
        newhead->next = head;
        head = newhead;
    }
    void deletionStart(){
        node *newstart = head->next;
        delete head;
        head = newstart;
    }
    void deletionLast(){ 
        node *seclast = head; 
        while ((seclast->next)->next != 0){ 
            seclast = seclast->next;
        }
        node* nodeToDelete = seclast->next; 
        seclast->next = 0;   
        delete nodeToDelete; 
    } 

    void deleteNode(int valueToDelete){
        node* current = head;
        while (current->next->data != valueToDelete){
        current = current->next;
        }
        node* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        delete nodeToDelete;
    }
    void reverse(){
        if(head==nullptr || head->next==0){
            return;
        }
        node *previous=0;
        node *current=head;
        node *nextNode=0;
        walker=head;

        while(current!=0){
            nextNode=current->next;
            current->next=previous;
            previous=current;
            current=nextNode;
        }
        head=previous;
    }
};
int main(){
    Sll list(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    cout << "Input: ";
    list.dispshort();

    list.reverse();

    cout << "Output: ";
    list.dispshort();

    return 0;
}
