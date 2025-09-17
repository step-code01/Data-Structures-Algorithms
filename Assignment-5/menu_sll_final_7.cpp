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
    void display(){ 
        cout << "Linked List: \n";
        node *display = head;
        while (display != 0){ 
            cout << "Data: " << display->data <<endl;
            cout << "Address of next element: " << display->next <<endl;
            display = display->next; 
        }
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
        node *finder = head; //find the ele req, then insert next
        while (finder->data != elem){
            finder = finder->next;
        }
        node *newinsert = new node(newdata); //A->C, want to add B in between
        //newinsert->data = newdata; not req? kar toh rha hai upar vo
        newinsert->next = finder->next; //B->C //pahle copy old next address to new data other it will be lost
        finder->next = newinsert; // A->B
    }
    void insertStart(int newh){
        node *newhead = new node(newh);
        newhead->next = head;
        head = newhead;
    }
    void deletionStart(){
        node *newstart = head->next; //set to next element
        delete head; //deallocate current head
        head = newstart;
    }
    void deletionLast(){ //v.imp fn can't be named delete since its a keyword v.imp
        node *seclast = head; //start from head 
        while ((seclast->next)->next != 0){ //2nd last node want to go
            seclast = seclast->next;
        }
        node* nodeToDelete = seclast->next; 
        seclast->next = 0;   
        delete nodeToDelete; 
    } //edge case of ll being size 1 head ke saath need to do, do that

    void deleteNode(int valueToDelete){
        node* current = head;
        while (current->next->data != valueToDelete){
        current = current->next;
        }
        node* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        delete nodeToDelete;
    }
void search(int valueToFind) {
    node* current = head;
    int position = 1;
    while (current->data != valueToFind) {
        current = current->next;
        position++;
    }
    cout << "Found " << valueToFind << " at position: " << position << endl;
}
};
/*duplicate elements how tackle if elem based matching?*/
int main() {
    int l;
    cout << "Enter the 1st element to initialize the linked list: ";
    cin >> l;
    Sll list(l);

    int choice;
    int data, element;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert after a specific node\n";
        cout << "4. Delete from the beginning\n";
        cout << "5. Delete from the end\n";
        cout << "6. Delete a specific node\n";
        cout << "7. Search for a node\n";
        cout << "8. Display the list\n";
        cout << "0. Exit\n";
        cout << "---------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                cin >> data;
                list.insertStart(data);
                list.dispshort();
                break;

            case 2:
                cout << "Enter value to insert at the end: ";
                cin >> data;
                list.insert(data);
                list.dispshort();
                break;

            case 3:
                cout << "Enter the existing element to insert after: ";
                cin >> element;
                cout << "Enter the new value to insert: ";
                cin >> data;
                list.insert(data, element);
                list.dispshort();
                break;

            case 4:
                cout << "Deleting from the beginning...\n";
                list.deletionStart();
                list.dispshort();
                break;

            case 5:
                cout << "Deleting from the end...\n";
                list.deletionLast();
                list.dispshort();
                break;

            case 6:
                cout << "Enter the value of the node to delete: ";
                cin >> data;
                list.deleteNode(data);
                list.dispshort();
                break;

            case 7:
                cout << "Enter the value to search for: ";
                cin >> data;
                list.search(data);
                break;

            case 8:
                list.dispshort();
                break;

            case 0:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice. Please enter a number from the menu.\n";
        }
    }
    return 0;
}