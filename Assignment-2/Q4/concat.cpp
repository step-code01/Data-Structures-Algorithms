#include <iostream>
#include <cstring>
using namespace std;

int main() {
    cout <<"Enter string 1: ";
    char str1[50];
    cin >> str1;
    cout <<"Enter string 2: ";
    char str2[50];
    cin >> str2;
    char result[100];
    int i, j;

    for (i=0; str1[i] !='\0'; i++) {
        result[i] = str1[i];
    }
    
    for (j=0; str2[j] !='\0'; j++) {
        result[i+j] = str2[j];
    }
    result[i+j] = '\0'; //safe practice w strings

    cout << "Concatenated string is: " << result << endl;

    return 0;
}