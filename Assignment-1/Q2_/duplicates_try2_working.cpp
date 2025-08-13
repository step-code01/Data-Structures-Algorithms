/*Design the logic to remove the duplicate elements from an Array and after the deletion the array should contain the unique elements.*/
#include <iostream>
using namespace std;
void sort (int *a,int size){
    int i,j;
    i=0;
    int temp;
    for (i=0;i<size;i++){
        for (j=0;j<size-1-i;j++){
            if (a[j] > a[j+1] && j+1<size) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
        }
    }
    }
}
void duplicate(int *a,int size){
    /*deletion logic*/ /*two pointer method - only works for sorted array, most efficient*/
    if (size<=1) return;
    int i,j,k;
    i=0;
    for (j=1;j<size;j++){
        if (a[i] != a[j]){
            i++; //increment the pointer 
            a[i] = a[j];
        }
    }

    int new_size = i+1; //this pointer would tell last location of unique elements
    cout << "Array with unique elements: ";
    for (k = 0; k < new_size; k++) cout << a[k]; 

}
int main(){
    cout << "Enter the size of array" <<endl;
    int size;
    cin >> size;

    cout << "Enter the array" << endl;
    int *ptr;
    ptr = new int[size];
    for (int i=0;i<size;i++) cin >> ptr[i];

    sort(ptr,size);
    duplicate(ptr,size);
    delete[] ptr; /*whole array ke liye, if only one - delete ptr*/
    return 0;
}