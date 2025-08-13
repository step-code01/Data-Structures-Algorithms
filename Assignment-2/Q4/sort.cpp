#include <iostream>
#include <cstring>

using namespace std;

void sort(char a[], int size) {
    int i, j;
    char temp;

    for (i=0; i<size-1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp; //ascii se same vahi sorting bubble sort
            } 
        }
    }
    cout << "Sorted string: " << a << endl;
}

int main() {
    cout << "Enter a string: ";
    char str[50];
    cin >> str;

    int length = strlen(str);

    sort(str, length);

    return 0;
}