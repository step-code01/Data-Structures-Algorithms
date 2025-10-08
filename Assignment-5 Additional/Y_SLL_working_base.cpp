/*Find the intersection node of two singly linked lists that merge into a Y-shaped structure. The lists may vary in length 
and have distinct nodes at the beginning, but from the point of intersection onward, they share the same sequence of nodes. 
The task is to identify the first common node where the two lists converge. If the two linked lists have no intersection 
at all, return null.

my thinking aage se jaaoge toh bahut pnc chalegi kaun
kisse kya match individually aage se ja end tk 2 pointers,
don't care right now about comparison, but phir peeche se aage aao - first
point of difference in memory location and element is the intersection point
*/
#include <iostream>
using namespace std;
class sll;
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
    friend void find_intersection(sll y_sll,sll y_branch);
};
class sll{
    public:
    node* head;
    node* marker;
    int count;
    sll(int l){
        head = new node(l);
        marker = head;
        count = 0;
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
    void insertstart(int l, node* existing){        
        existing->next = head;
        head = existing;
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
    node* search(int l){
        node *searcher = head;
        while (searcher->data != l){
            searcher = searcher->next;
            count++;
        }
        //cout << "Addr: " << searcher;
        return searcher;
    }
    void y_maker(int elem,sll &y_branch){
        node* addr = search(elem);
        if (search(elem) == nullptr) cout << "Not found in list";
        else {
            y_branch.marker->next = addr;
        }
    }
    void reverse_ll(){
        node *left = head;
        node *right = head;
        node *curr = head;
        
        curr = curr->next;
        right = right->next->next;
        
        /*first two flip*/
        head = curr;
        curr->next = left;
        left->next = right;
        
        while (right!= 0){
            /*role reversal*/
            curr = right;
            right = curr->next;
            
            /*operation*/
            curr->next = head;
            left->next = right;
            head = curr;
        }
    }
};
void find_intersection(sll y_sll,sll y_branch){ // by value is intentional i don't want any changes; const and by ref bhi can?
    y_sll.reverse_ll();
    y_sll.display();
    y_branch.display();

    /*walk through both lists, the next element point of diff usse pahle one is int node*/
    node* walker1 = y_sll.head;
    node* walker2 = y_branch.head;

    while (walker2 || walker1 != 0){ //anyone hits zero 
        walker1 = walker1->next;
        walker2 = walker2->next;
        if (walker1->data != walker2->data){ //advance the pointers pahle phir condition check karring isliye sahi aara data pe hi check karne par
            cout << "Intersection node: " << walker1->data;
            break;
        }
    }
}
/*my concept flip the branch, first point of difference after common is the node*/
/*marker se check karlu aise toh lol*/
void input(sll &y){
    int r;
    while (r!=-1){
        cin >> r;
        if (r==-1) break;
        y.insert(r);
    }
    r=0; 
}
int main(){ 
    int i;

    cout << "Enter first element of root branch of Y-SLL: ";
    int l; cin >> l;
    sll y_sll(l);
    cout << "Enter elements in root branch (enter -1 to stop): ";
    input(y_sll);
    cout << "Enter first element of side-branch of Y-SLL: ";
    cin >> l;
    sll y_branch(l);
    cout << "Enter elements in side-branch (enter -1 to stop): ";
    input(y_branch);

    y_sll.y_maker(8,y_branch);

    cout << "\nY-list: \n";
    y_sll.display();
    y_branch.display();

    /*now algo must tell what's the common intersection point for two given linked lists*/
    find_intersection(y_sll,y_branch);
    return 0;
}