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
    int countAndDeleteAll(int key){
        int count=0;
        node *temp;
        while(head!=0 && head->data==key){
            temp=head;
            head=head->next;
            delete temp;
            count++;
        }
        node *current=head;
        if(current==0){
            return count;
        }
        while(current->next!=0){
            if(current->next->data==key){
                temp=current->next;
                current->next=temp->next;
                delete temp;
                count++;
            }
            else{
                current=current->next;
            }
        }
        return count;
    }
};
int main(){
    Sll list(1);
    list.insert(2);
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(3);
    list.insert(1);

    cout << "Input Linked List: ";
    list.dispshort();

    int key=1;
    int occurrences=list.countAndDeleteAll(key);

    cout << "key: " << key << endl;
    cout << "Count: " << occurrences << endl;
    cout << "Updated Linked List: ";
    list.dispshort();

    return 0;
}
