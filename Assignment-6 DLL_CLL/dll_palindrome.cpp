#include <iostream>
using namespace std;
class dll;
class node{
    char data;
    node* prev;
    node* next;
    public:
    node(){ //default 
        //data = NULL; //character me nulldata, dikkat toh nhi na koi? keep 0 only, null char ascii = 0 
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
    node(char d, node* p = nullptr, node* n = nullptr){
        data = d;
        prev = p;
        next = n;
    }
    friend class dll;
    friend void palindrome_checker(dll l);
};
class dll{
    node* head;
    node* marker;
    int count;
    public:
    dll(){
        char d;
        cout << "Enter data of node: ";
        cin >> d;
        head = new node(d);
        marker = head;
        count = 0;
    }
    void insert(char d){
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
    void insertstart(char d){
        node* walker = head;
        node* newNode = new node(d);

        head->prev = newNode;
        newNode->prev = nullptr;
        newNode->next = head;
        head = newNode;
    }
    void insertbefore(char d,char poselem){
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
    void deletion(char poselem){ 
        node* walker = head;
        while (walker->data != poselem){
            walker = walker->next;
        }
        /*from end*/
        if (poselem == marker->data){
            walker->prev->next = nullptr;
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
    }
    void search(char poselem){
        node* searcher = head;
        while (searcher->data != poselem){
            searcher = searcher->next;
            count++;
        }
        cout << "Element is " << count+1 << " position from the head (head = 1) \n";
    }
    void size(){
        int ctr = 0; //else it would keep increasing everytime it runs, don't use count
        node* walker = head;
        while (walker != nullptr){
            walker = walker->next;
            ctr++;
        }
        cout << "No of elements of DLL (size): " << ctr;
    }
    friend void palindrome_checker(dll l);
};
void palindrome_checker(dll l){ //we just need to use it, nothing to alter so by value ok
    node* start = l.head;
    node* end = l.marker;

    while (start!=nullptr){ //start<=end krna hai (<= me odd, even no of letters dono aa jayenge) poora jaane du after midway, ez but waste of iterations
        if(start->data != end->data){
            cout << "False" <<endl;
            return;
        }
        start = start->next;
        end = end->prev;
    }
    cout << "True";
    cout <<endl;
    return;
}
int main(){
    dll l1;
    int n;
    cout << "enter (no of letters in word-1): \n";
    cin >> n;
    cout << "enter letters: \n";
    while (n--){ // eg 5 - 5,4,3,2,1 - 5 iter mil rha yes
        char d; cin >> d;
        l1.insert(d);
    }
    palindrome_checker(l1);
    return 0;
}
/*ascii check caps and small ek saath na daalde koi*/

/*another way if in sll to check palindrome, 
cummulative freq from back and front would be different if not palindrome?
each step sum check? in a sll if want to check without actually
reversing the sll?*/