#include <iostream>
using namespace std;

void reverse(int *a, int size){
    int i,j,temp;
    for (i=0,j=size-1;i<j;i++,j--){ /*only swap till half of array*/
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    cout << "Reversed array is: ";
    for (i=0;i<size;i++) cout << a[i];
}

int main(){
    cout << "Enter the size of array" <<endl;
    int size;
    cin >> size;

    cout << "Enter the array" << endl;
    int *ptr;
    ptr = new int[size];
    for (int i=0;i<size;i++) cin >> ptr[i];

    reverse(ptr,size);
    delete[] ptr;
    return 0;
}