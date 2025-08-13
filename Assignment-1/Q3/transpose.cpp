#include <iostream>
using namespace std;

void input(int arr[10][10], int rows, int cols) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i=0; i<rows;i++) {
        for (int j=0; j<cols;j++) cin >> arr[i][j];
    }
}

void transpose(int original[10][10], int transposed[10][10], int rows, int cols) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols;j++) transposed[j][i] = original[i][j];
    }
}

void print(int arr[10][10], int rows, int cols) {
    for (int i=0; i<rows;i++) {
        for (int j=0; j<cols;j++)  cout << arr[i][j] << "  ";
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns of the matrix:" << endl;
    cin >> rows >> cols;

    int original[10][10];
    int transposed[10][10];

    input(original, rows, cols);

    transpose(original, transposed, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    print(original, rows, cols);

    cout << "\nTransposed Matrix:" << endl;
    print(transposed, cols, rows); /*col,row order swap for transpose imp*/

    return 0;
}