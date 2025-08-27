#include <iostream>
using namespace std;

/*concept - shift till 2 occurs from back*/

void dupli_two(int arr[], int size) {
    int i,j;
    for(i=size-1;i>=0;i--){
        if(arr[i]==2){
            if(i+1<size) { //boundary pr 2 hai toh duplicate can't leave it
                for(j=size-1;j>i;j--){ 
                    arr[j]=arr[j-1];
                }
                arr[i+1] = 2;
                i--;  //skip dupli
            }
        }
    }
    cout << "New array: ";
    for (i=0;i<size;i++) cout << arr[i];
}
int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    cout << "Enter array elements: ";
    int *ptr = new int[size];
    for (int i=0;i<size;i++) {cin >>ptr[i];}

    cout << "Original array: ";
    for (int i=0;i<size;i++) {cout <<ptr[i];}
    cout << endl;

    dupli_two(ptr,size);
    delete[] ptr;
}