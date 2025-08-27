#include <iostream>
using namespace std;

void dutch_algo(int ptr[],int size){
    int ztr = 0; 
    int tpr = size-1;

    int i;
    int temp=0; //imp
    //assuming 1st and last ele 0,2 hai respectively rn
    for (i=0;i<=tpr;){ //stop when high crosses mid stop - imp 
        if (ptr[i] == 0){ //if 0 to go left end
            temp = ptr[i];
            ptr[i] = ptr[ztr];
            ptr[ztr] = temp;

            ztr++;
            i++;
        }
        else if (ptr[i] == 2){ //if 2 go to right end processed first req
            temp = ptr[i];
            ptr[i] = ptr[tpr];
            ptr[tpr] = temp;

            tpr--;
            //don't move mid until processed
        }
        else if (ptr[i] == 1){
            i++;//1 hai toh auto sort to middle, just increment mid
    }}

    cout << "sorted array: ";
    for (int i=0;i<size;i++) cout << ptr[i];
}

int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    cout << "Enter array elements: ";
    int *ptr = new int[size];
    for (int i=0;i<size;i++) {cin >>ptr[i];}

    dutch_algo(ptr,size);
    delete[] ptr;
}

/*simpler method - just bubble sort it out easier, but slower.*/