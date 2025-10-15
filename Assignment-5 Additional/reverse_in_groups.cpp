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
    void reverse_in_groups(int k){
        node* curr = head;
        node* newHead = nullptr;
        node* prevTail = nullptr;

        while (curr != nullptr){
            node* box_start = curr;
            node* box_end = curr;
            int count = 1;

            while (count < k && box_end->next != nullptr){
                box_end = box_end->next;
                count++;
            }
            
            if (count < k) break;
            node* nextgrp = box_end->next;

            node* prev = nextgrp;
            node* walk = nullptr;
            node* node_curr = box_start;
            
            while (node_curr != nextgrp){
                walk = node_curr->next;
                node_curr->next = prev;
                prev = node_curr;
                node_curr = walk;
            }

            if (prevTail != nullptr)
                prevTail->next = box_end;
            else
                newHead = box_end;

            prevTail = box_start;
            curr = nextgrp;
        }
        head = newHead;
    }
};  

int main(){
    int k;
    cout << "Enter value of k to reverse in groups: ";
    cin >> k;

    sll l1(10);
    l1.insert(20);
    l1.insert(30);
    l1.insert(40);
    l1.insert(50);

    l1.display();
    l1.reverse_in_groups(k);
    l1.display();
    return 0;
}
/*    void reverse_in_groups(int k, sll l1){
        int count = 0; 
        node* box_start = head;
        node* box_end = head;
        
        while (count != k){
            box_end = box_end->next;
            count++;
        }

        reverse_ll(box_start,box_end);
    }
        */