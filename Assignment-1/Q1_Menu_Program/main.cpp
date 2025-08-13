/*1) Develop a Menu driven program to demonstrate the following operations of Arrays
——MENU——- 
1. CREATE
2. DISPLAY
3. INSERT
4. DELETE
5. LINEAR SEARCH
6. EXIT*/

/*hashmap se try krra tha better optimised*/
#include <iostream>
using namespace std;
 
class Create{
    public:
    void create(int size){
        int i;
        int arr[size];
        cout << "Enter the elements of the array: ";
        for (i=0;i<size;i++) cin >> arr[i];
        cout << "Your array has been created." <<endl;
        Create(int val) : baseValue(val) {}
    }
};
class Display : public Create{ // Inherit to get values from Create
    public:
    Display()

};
class Insert{

};
class Delete{

};
class LinearSearch{

};

int main(){
    cout << "Welcome to array menu!" <<endl;
    cout << "What would you like to do?\n";
    cout << "\t1.Create\n\t2.Display\n\t3.Insert\n\t4.Delete\n\t5.Linear Search\n\t6.Exit\n";
    
    int option;
    cin >> option;

    if (option==6) {cout << "Exiting program"; return 1;}
    
    /*creating objects*/
    Create arr_create;
    Display arr_display;
    Insert arr_insert;
    Delete arr_delete;
    LinearSearch arr_lsearch;

    if (option==1){
        cout << "Enter the size of array you want to create" <<endl;
        int size;
        cin >> size;
        arr_create.create(size);
    }
    else if (option==2){
        cout << 
    }
}

