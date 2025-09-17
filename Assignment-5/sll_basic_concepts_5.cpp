#include <iostream>
using namespace std;
class node{ //single atomic unit of ll
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
    node* head; //points to first head node
    node* walker; //yeh train ko traverse kar rha
    public:
    Sll(int l){
        node* n = new node(l);
        head = n;
        walker = head;
    }   
    void insert(int newdata){
        node* newNode = new node(newdata); //v.imp stack pe karra tha but heap pe karo!
        walker->next = newNode; //next pointer inside head node points to next new node
        walker = newNode;
    }
    void display(){ //to display the list, we can create a temp pointer which goes thru the list
        cout << "Linked List: \n";
        node *display = head; //head se chalu
        while (display != 0){ 
            cout << "Data: " << display->data <<endl;
            cout << "Address of next element: " << display->next <<endl;
            display = display->next; //go to next node address 
        }
    }
};
int main(){
    int l;
    cout << "Enter the 1st element in linked list: ";
    cin >> l;

    Sll s(l);
}
