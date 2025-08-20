/*just sort the array in descending order, if diff !=0 gaps mil gye, and gaps+1 -distinct ele
since we just have to tell no of distinct ele and not what the distinct ele's are*/
#include <iostream>
using namespace std;
void bubble_sort(int arr[], int size){
    int i,j,temp;
    if (size==1){ cout << "Bro. What u doing."; return;}
    for (i=0;i<size;i++){
        for (j=i;j<size;j++){
            if (arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    /*debug k liye*/
    cout << "Sorted array: ";
    for (i=0;i<size;i++) cout << arr[i];
    cout << endl;
}
void distinct(int arr[],int size){
    int i,j;
    int counter_flag=0;
    for (i=0,j=1;j<size;i++,j++){//j pahle end pahuchega sufficient hai?
        if (arr[j]-arr[i]!=0){
            counter_flag++;
        }
    } 
    cout << "no of distinct elements: " << counter_flag + 1 << endl; //gaps+1 distinct ele
}
int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter the array: ";
    int arr[size]; //make dma standard practice cpp habit
    
    int i;
    for (i=0;i<size;i++)cin >> arr[i];

    bubble_sort(arr,size);
    distinct(arr,size);
}