#include <iostream>

using namespace std;

// Maximum size of the array
int MAX_SIZE = 100;

void createArray(int arr[], int &size) {
    cout << "Enter the number of elements (max " << MAX_SIZE << "): ";
    cin >> size;

    if (size <= 0 || size > MAX_SIZE) {
        cout << "Invalid size. Please enter a value between 1 and " << MAX_SIZE << "." << endl;
        size = 0;
        return;
    }

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }
    cout << "Array created successfully." << endl;
}

void displayArray(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Array elements are: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &size) {
    if (size >= MAX_SIZE) {
        cout << "Array is full. Cannot insert more elements." << endl;
        return;
    }

    int element, position;
    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the position to insert at (0 to " << size << "): ";
    cin >> position;

    if (position < 0 || position > size) {
        cout << "Invalid position." << endl;
        return;
    }

    for (int i = size; i > position; --i) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
    cout << "Element inserted successfully." << endl;
}

void deleteElement(int arr[], int &size) {
    if (size == 0) {
        cout << "Array is empty. Nothing to delete." << endl;
        return;
    }

    int position;
    cout << "Enter the position of the element to delete (0 to " << size - 1 << "): ";
    cin >> position;

    if (position < 0 || position >= size) {
        cout << "Invalid position." << endl;
        return;
    }

    for (int i = position; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element deleted successfully." << endl;
}

void linearSearch(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty. Cannot search." << endl;
        return;
    }

    int element;
    cout << "Enter the element to search for: ";
    cin >> element;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            cout << "Element " << element << " found at position " << i << "." << endl;
            return;
        }
    }
    cout << "Element " << element << " not found in the array." << endl;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. LINEAR SEARCH" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createArray(arr, size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, size);
                break;
            case 4:
                deleteElement(arr, size);
                break;
            case 5:
                linearSearch(arr, size);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
