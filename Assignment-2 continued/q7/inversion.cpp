/*so its just bubble sort and counter ko ++ karna when condition satisfy?
O(n2) hai for large arr, slow but ok*/
#include <iostream>
using namespace std;
void inversions_count(int arr[], int size){
    int i,j,temp;
    int counter_flag=0; //v.imp! i forget
    cout << "Inversion pairs: (arr[i],arr[j]): ";
    for (i=0;i<size;i++){
        for (j=i;j<size;j++){ //i<j fashion
            if (arr[i]>arr[j]){
                counter_flag++;
                cout <<"(" << arr[i] << "," << arr[j] << ")"; // instead of i,j do arr[i],arr[j] no
            }
        }
    }
    cout << "No of inversions are: \n" << counter_flag;
}
int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter the array: ";
    int arr[size]; //do dma better
    
    int i;
    for (i=0;i<size;i++)cin >> arr[i];

    inversions_count(arr,size);
    return 0;
}
/*more efficient krne k liye i think - 
eg. 1 7 4 6 3 2 
1 hai toh no need to check skip poora i iteration - (smallest no k liye)
7 hai toh sbse bada hi hai - all count aage jitne hai (i<j) - (largest no k liye)
beech ka hai - check usse kitne no bade hai arr me -> utne hi inv? if aage lie karte?
aisa kuch*/

