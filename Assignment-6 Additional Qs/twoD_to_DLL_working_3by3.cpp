#include <iostream>
using namespace std;
/*works for only same length dll + only 3x3 
now make it nxnlogic*/
class dll;
class node{
    int data;
    node* prev;
    node* next;
    node* up;
    node* down;
    public:
    node(){ 
        data = 0;
        next = nullptr;
        prev = nullptr;
        up = nullptr;
        down = nullptr;
    }
    node(int d, node* p = nullptr, node* n = nullptr,node* u = nullptr, node* dw = nullptr){
        data = d;
        prev = p;
        next = n;
        up = u;
        down = dw;
    }
    friend class dll;
    friend void twoD_to_DLL_maker(int arr[][3]);
};
class dll{
    node* head;
    node* marker;
    int count;
    public:
    dll(int h){
        head = new node(h);
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
    void deletion(int poselem){
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
    friend void twoD_to_DLL_maker(int arr[][3]);
};
void twoD_to_DLL_maker(int arr[][3]){
    int x,y,z;
    dll d1(arr[0][0]);
    dll d2(arr[1][0]);
    dll d3(arr[2][0]);

    int i,j;
    for (i=0;i<3;i++){
        for (j=1;j<3;j++){
            if (i==0) d1.insert(arr[0][j]);
            else if (i==1) d2.insert(arr[1][j]);
            else d3.insert(arr[2][j]);
        }
    }

    node* b1 = d1.head;
    node* b2 = d2.head;
    node* b3 = d3.head;

    while (b1 !=nullptr){
        b1->up = nullptr;
        b1->down = b2;
        b2->up = b1;
        b2->down = b3;
        b3->up = b2;
        b3->down = nullptr;

        b1 = b1->next;
        b2 = b2->next;
        b3 = b3->next;
    }

    node* disp1 = d1.head;
    node* disp2 = d1.head->next;
    node* disp3 = d1.head->next->next;

    while (disp1 != nullptr){
        cout << disp1->data << " <-> " << disp2 ->data << " <-> " << disp3->data <<endl;
        disp1 = disp1->down;
        disp2 = disp2->down;
        disp3 = disp3->down;
        if (disp1!=nullptr && (disp1->up != nullptr || disp1->down != nullptr)) cout << "| " << " " << "   | " << " " << "   | " << " " <<endl ;
    }
}
int main(){
    int arr[3][3];
    cout << "Enter an 2D matrix: \n";

    int i,j;
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    twoD_to_DLL_maker(arr);
    return 0;
}
