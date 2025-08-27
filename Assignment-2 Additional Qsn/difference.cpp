/*Find two numbers in an array whose difference equals K. Given an array arr[] and a positive
integer k, the task is to count all pairs (i, j) such that i < j and absolute value of (arr[i] - arr[j])
is equal to k.*/
#include <iostream>
using namespace std;
void difference_count(int arr[],int size,int k){
    int i,j;
    int count_flag=0; //keep it that way usual
    cout << "k = (i,j): ";
    for (i=0;i<size;i++){
        for (j=i+1;j<size;j++){
            if ((arr[i] - arr[j] == k) || (arr[i] - arr[j] == -k)){
                cout << "(" << arr[i] << "," << arr[j] << ")";
                count_flag++;
            }
        }
    }
    cout <<endl;
    cout << "The number of such pairs are: "<< count_flag << endl;
}
int main(){
    cout << "Enter the size of array you want to create: ";
    int size;
    cin >> size;

    cout << "Enter the value of k (k+ve): ";
    int k;
    cin >> k;

    cout << "Enter the elements of array: ";
    int arr[size];
    int i;
    for (i=0;i<size;i++) cin>>arr[i];

    difference_count(arr,size,k);
}