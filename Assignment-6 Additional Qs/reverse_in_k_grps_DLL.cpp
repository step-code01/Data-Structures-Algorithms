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
    void insertstart(int d){
        node* newNode = new node(d);
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        count++;
    }
    void insertbefore(int d, int poselem){
        node* walker = head;
        while (walker->data != poselem){
            walker = walker->next;
        }
        node* newNode = new node(d);
        newNode->prev = walker->prev;
        newNode->next = walker;
        walker->prev->next = newNode;
        walker->prev = newNode;
        count++;
    }

    void deletion(int poselem){
        node* walker = head;
        while (walker->data != poselem){
            walker = walker->next;
        }
        /*from end*/
        if (poselem == marker->data){
            walker->prev->next = nullptr;
            marker = walker->prev;
            delete walker;
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
        count--; //v.imp forgot
    }
    void display(){
        node* walk = head;
        while (walk != nullptr){
            cout << walk->data;
            if (walk->next != nullptr) cout << "<->";
            walk = walk->next;
        }
        cout << endl;
    }
    node* reverseK(node* start, int k){
        node* curr=start;
        node* temp=nullptr;
        int c=0;
        while (curr!=nullptr && c<k){
            temp=curr->prev;
            curr->prev=curr->next;
            curr->next=temp;
            curr=curr->prev;
            c++;
        }
        if (temp!=nullptr) start=temp->prev;
        return start;
    }
    void reverse_in_k(int k){
    if (head == nullptr || k <= 1) return; 

    node* curr = head;
    node* head2 = nullptr;   
    node* oldtail = nullptr;

    while (curr != nullptr){
        node* grphead = curr;     
        node* temp = curr;
        int c = 0;

        while (c<k-1 && temp->next != nullptr){
            temp = temp->next;
            c++;
        }

        node* nextGroupHead = temp->next;
        if (nextGroupHead != nullptr) nextGroupHead->prev = nullptr;
        temp->next = nullptr;

        node* newGroupHead = reverseK(grphead, k); 

        if (head2 == nullptr) head2 = newGroupHead;  

        if (oldtail != nullptr){
            oldtail->next = newGroupHead;
            newGroupHead->prev = oldtail;
        }

        oldtail = grphead;        
        curr = nextGroupHead;       
    }
    head = head2;
}

};

void input(dll &d1){
    int n;
    cout << "Enter number of elements to insert (excluding first): ";
    cin >> n;

    for (int i = 0; i < n; i++){
        int d;
        cout << "Enter data: ";
        cin >> d;
        d1.insert(d);
    }
    cout << "DLL: ";
    d1.display();

    int k;
    cout << "Enter group size k to reverse: ";
    cin >> k;

    d1.reverse_in_k(k);
    cout << "Reversed in groups of " << k << ": ";
    d1.display();
}

int main(){
    cout << "Enter first elem of DLL: ";
    int x; 
    cin >> x;

    dll d1(x);
    input(d1);
    return 0;
}
