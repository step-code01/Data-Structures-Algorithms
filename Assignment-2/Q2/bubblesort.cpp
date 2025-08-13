#include <iostream>
using namespace std;
void sort (int *a,int size){
    int i,j;
    int temp;
    for (i=0; i<size-1; i++){
        for (j=0; j<size-1-i; j++){
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    cout << "Sorted Array: ";
    for (i=0;i<size;i++) cout << a[i] << " ";
    cout << endl;
}


int main(){
    cout << "Enter the size of array" <<endl;
    int size;
    cin >> size;

    cout << "Enter the array" << endl;
    int *numbers;
    numbers = new int[size];
    for (int i=0;i<size;i++) cin >> numbers[i];

    sort(numbers,size);
    return 0;
}
