#include <iostream>
using namespace std;

void input(int arr[][10], int rows, int cols) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i=0; i<rows;i++) {
        for (int j=0; j<cols;j++)cin >> arr[i][j];
    }
}

// matrix mult
void multMatrix(int arr1[][10], int arr2[][10], int arr3[][10], int row1, int col1, int col2) {
    int sum = 0;
    for (int i=0; i<row1; i++) {
        for (int j=0; j<col2;j++) {
            sum = 0;
            for (int k=0; k<col1; k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            arr3[i][j] = sum;
        }
    }
}

void print(int arr3[][10], int rows, int cols) {
    cout << "The resultant matrix is:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << arr3[i][j] << "  ";
        cout << endl;
    }
}

int main() {
    int row1, col1, row2, col2;
    cout << "Enter the row and column of the first matrix:" << endl;
    cin >> row1 >> col1;
    cout << "Enter the row and column of the second matrix:" << endl;
    cin >> row2 >> col2;

    int arr1[10][10];
    int arr2[10][10];
    int arr3[10][10];

    if (col1 != row2) {
        cout << "Matrix Multiplication not possible" << endl;
    } else {
        cout << "For Matrix 1:" << endl;
        input(arr1, row1, col1);
        cout << "For Matrix 2:" << endl;
        input(arr2, row2, col2);
        multMatrix(arr1, arr2, arr3, row1, col1, col2);
        print(arr3, row1, col2);
    }
    return 0;
}