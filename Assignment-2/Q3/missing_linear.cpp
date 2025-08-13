#include <iostream>
using namespace std;
int findMissingNumber(int arr[], int size) {
    // Check if the first element is not 1, implying 1 is the missing number.
    if (arr[0] != 1) {
        return 1;
    }
    
    // Iterate through the array to find a gap of more than 1
    for (int i=0; i<size-1; i++) {
        if (arr[i+1] != arr[i] + 1) {
            return arr[i] + 1;
        }
    }
    
    // If no gap is found, the missing number is the one after the last element.
    return arr[size-1] + 1;
}

int main() {
    cout << "Enter the size of array" <<endl;
    int size;
    cin >> size;

    cout << "Enter the array" << endl;
    int *numbers;
    numbers = new int[size];
    for (int i=0;i<size;i++) cin >> numbers[i];

    int missingNumber = findMissingNumber(numbers, size);
    cout << "The missing number is: " << missingNumber << endl;
    delete[] numbers;

    return 0;
}