#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int d = 0, node* n = nullptr) {
        data = d;
        next = n;
    }
    friend class cll;
};
class cll {
public:
    node* head;
    node* marker;

    cll(){
        int d;
        cout << "Enter data of node: ";
        cin >> d;
        head = new node(d);
        head->next = head;
        marker = head;
    }
    void insert(int d) {
        node* newNode = new node(d);
        newNode->next = head;
        marker->next = newNode;
        marker = newNode;
    }
    void display(node* ptr=nullptr) {
        if (ptr==nullptr) ptr=head;
        node* walker = ptr;
        if (!walker) return; //v.imp new way of writing found v.imp
        do {
            cout << walker->data;
            walker = walker->next;
            if (walker != ptr) cout << "->";
        } while (walker != ptr);
        cout << endl;
    }
};

node* split_cll(node* head){
    if (head==nullptr || head->next==head)
        return nullptr;

    node* slow=head;
    node* fast=head;

    while (fast->next!=head && fast->next->next!=head) {
        slow=slow->next;
        fast=fast->next->next;
    }

    /*cll split*/
    if (fast->next->next == head) fast = fast->next;
    node* head2 = slow->next;  
    slow->next = head;         
    fast->next = head2;      

    return head2;
}

int main() {
    cll c1;
    c1.insert(4);
    c1.insert(9);
    // c1.insert(7);
    // c1.insert(3);
    // c1.insert(6);
    // c1.insert(2);

    cout << "Original CLL: ";
    c1.display();

    node* head2 = split_cll(c1.head);

    cout << "\nFirst half: ";
    c1.display(c1.head);

    cout << "Second half: ";
    c1.display(head2);

    return 0;
}