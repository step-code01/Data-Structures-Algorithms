#include <iostream>
using namespace std;

class node{
    int data;
    node* prev;
    node* next;
    public:
    node(){ //default 
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
    node(int d, node* p = nullptr, node* n = nullptr){
        data = d;
        prev = p;
        next = n;
    }
    friend class dll;
};
class dll{
    node* head;
    node* marker;
    int count;
    public:
    dll(){
        int d;
        cout << "Enter data of node: ";
        cin >> d;
        head = new node(d);
        marker = head;
        count = 0;
    }
    void insert(int d){
        node* walker = head;
        while (walker->next != nullptr){
            walker = walker->next;
        }

        node* newNode = new node(d);
        newNode->prev = walker; 
        walker->next = newNode;

        marker = newNode;
    }
    void display(){
        node* walker = head;
        while (walker != nullptr){  
            cout << walker->data;
            walker = walker->next;
            if (walker != nullptr) cout << "->";
        }
        cout << endl;
    }
    void insertstart(int d){
        node* walker = head;
        node* newNode = new node(d);

        head->prev = newNode;
        newNode->prev = nullptr;
        newNode->next = head;
        head = newNode;
    }
    void insertbefore(int d,int poselem){
        node* walker = head;
        while (walker->data != poselem){
            walker = walker->next;
        }

        node* newNode = new node(d);
        newNode->prev = walker->prev;
        newNode->next = walker;
        walker->prev->next = newNode;
        walker->prev = newNode;
    }
    void deletion(int poselem){ //all 3 act in one that's why
        node* walker = head;
        while (walker->data != poselem){
            walker = walker->next;
        }
        /*from end*/
        if (poselem == marker->data){
            walker->prev->next = nullptr;
            delete walker; //walker jiss node pe hai vo dynamically allocated hai usko uda do
        }
        /*from start*/
        else if (poselem == head->data){
            head = head->next;
            head->prev = nullptr;
            delete walker;
        }
        /*in between*/
        else{
            walker->prev->next = walker->next;
            walker->next->prev = walker->prev;
            delete walker;
        }
    }
    void search(int poselem){
        count = 0; //reset for each run v.imp i forgot
        node* searcher = head;
        while (searcher->data != poselem){
            searcher = searcher->next;
            count++;
        }
        cout << "Element is " << count+1 << " position from the head (head = 1) \n";
    }

};
/*pointer free krna v.imp
class me input lena is it good or bad practice*/
int main(){
    dll l1;
    l1.insert(4);
    l1.display();
    l1.insertstart(3);
    l1.display();
    l1.insertbefore(6,5);
    l1.display();
    l1.deletion(6);
    l1.display();
    l1.search(5);
    l1.display();
}