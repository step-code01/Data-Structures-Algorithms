#include <iostream>
using namespace std;
int findMissingNumber(int arr[], int size) {
    int low = 0;
    int high = size - 1;
    int ans = size + 1; // Default case where the last number is missing

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            ans = mid + 1;
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    cout << "Enter the size of array" <<endl;
    int size;
    cin >> size;

    cout << "Enter the array" << endl;
    int *numbers;
    numbers = new int[size];
    for (int i=0;i<size;i++) cin >> numbers[i];

    cout << "The missing number is: " << findMissingNumber(numbers, size) << endl;
    delete[] numbers;
    return 0;
}