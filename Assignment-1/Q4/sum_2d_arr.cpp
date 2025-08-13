#include <iostream>
using namespace std;

void input(int arr[10][10], int rows, int cols) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i=0; i<rows;i++) {
        for (int j=0; j<cols;j++) cin >> arr[i][j];
    }
}

void row_Sum(int arr[10][10], int rows, int cols) {
    cout << "\nSum of each row:" << endl;
    for (int i=0; i<rows;i++) {
        int sum = 0;
        for (int j=0; j<cols;j++) sum += arr[i][j];
        cout << "Row " << i+1 << ": " << sum << endl;
    }
}

void col_Sum(int arr[10][10], int rows, int cols) {
    cout << "\nSum of each column:" << endl;
    for (int j=0; j<cols; j++) {
        int sum = 0;
        for (int i=0; i<rows; i++) sum += arr[i][j];
        cout << "Column " << j+1 << ": " << sum << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns of the matrix:" << endl;
    cin >> rows;
    cin >> cols;

    int matrix[10][10];

    input(matrix, rows, cols);
    
    row_Sum(matrix, rows, cols);
    col_Sum(matrix, rows, cols);    

    return 0;
}