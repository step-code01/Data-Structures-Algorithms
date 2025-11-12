#include <iostream>
using namespace std;

class dll;
class node{
    public:
    int data;
    node* prev;
    node* next;

    node(){ 
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
    public:
    node* head;
    node* marker;
    int count;

    dll(int h){
        head = new node(h);
        marker = head;
        count = 1;
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
        count++;
    }

    void display(){
        node* walk = head;
        while (walk != nullptr){
            cout << walk->data;
            if (walk->next != nullptr) cout << "->";
            walk = walk->next;
        }
        cout << endl;
    }

    void display_reverse(){
        node* walk = marker;
        while (walk != nullptr){
            cout << walk->data;
            if (walk->prev != nullptr) cout << "->";
            walk = walk->prev;
        }
        cout << endl;
    }
};

void ptr_correct(dll &d1){
    node* slow = d1.head;
    node* fast = d1.head;

    // Step 1: Detect if there’s a loop using slow & fast pointers
    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) break; // loop found
    }

    // If no loop found, just return
    if (fast == nullptr || fast->next == nullptr)
        return;

    // Step 2: Find the start of the loop
    slow = d1.head;
    while (slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    // Step 3: Break the loop
    fast->next = nullptr;

    // Step 4: Fix prev pointers and marker
    node* walker = d1.head;
    node* prev = nullptr;
    while (walker != nullptr){
        walker->prev = prev;
        prev = walker;
        walker = walker->next;
    }
    d1.marker = prev; // last node
}

int main(){
    dll d1(1);
    d1.insert(2);
    d1.insert(3);

    // Corrupt the list: make 3->next point to 1 (head)
    node* walk = d1.head;
    walk->next->next = walk;

    cout << "Incorrect DLL (forward): ";
    d1.display();

    cout << "Incorrect DLL (reverse): ";
    d1.display_reverse();

    ptr_correct(d1); // fix the list

    cout << "\nCorrect DLL (forward): ";
    d1.display();

    cout << "Correct DLL (reverse): ";
    d1.display_reverse();

    return 0;
}
