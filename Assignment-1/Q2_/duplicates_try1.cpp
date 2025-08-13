/*Design the logic to remove the duplicate elements from an Array and after the deletion the array should contain the unique elements.*/
#include <iostream>
using namespace std;
void duplicate(int *a,int size){
    int i,j;
    int d_arr[size]; /*array to store positions of duplicate elements, duplicate elements won't be greater than original arr size itself*/
    int k=0;
    for (i=0;i<size;i++){
        for (j=i+1;j<size;j++){ /*no need to check with itself*/
            if (a[i] == a[j]){
                d_arr[k] = j; /*store indexes where duplicates found*/
                k++;
            }
        }
    }
    cout << "Duplicate(s) at index: ";
    for (i=0;i<k;i++) cout << d_arr[i] << ","; 
    
    /*deletion logic*/
    for (i=0;i<k;i++){ /*run till jitne duplicates hai*/
        for (j=0;j<(size-d_arr[i]);j++){
            a[d_arr[i]+j] = a[d_arr[i] + j + 1];
    }}
        
    cout << "Array with unique elements: ";
    for (i=0;i<size-k;i++) cout << a[i]; 
}
int main(){
    cout << "Enter the size of array" <<endl;
    int size;
    cin >> size;

    cout << "Enter the array" << endl;
    int *ptr;
    ptr = new int[size];
    for (int i=0;i<size;i++) cin >> ptr[i];

    duplicate(ptr,size);
    delete[] ptr;
}

/*failed cuz once you shift - new indexes, d_arr becomes redundant*/
/*if not edit in same array - just copy the elements except the ones' index in d_arr and store in new arr*/
