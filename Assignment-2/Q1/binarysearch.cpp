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
    cout << "Sorted Array: ";
    for (i=0;i<size;i++){
        cout << a[i];
    }
    cout <<endl;
}
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid; 
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    // If the loop finishes, the target was not found
    return -1;
}

int main() {
    cout << "Enter the size of array" <<endl;
    int size;
    cin >> size;

    cout << "Enter the array" << endl;
    int *numbers;
    numbers = new int[size];
    for (int i=0;i<size;i++) cin >> numbers[i];

    cout << "Enter the value you want to find: ";
    int target;
    cin >> target;

    sort(numbers,size); /*binary search sorted array chahiye*/
    int result = binarySearch(numbers, size, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << "." << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}