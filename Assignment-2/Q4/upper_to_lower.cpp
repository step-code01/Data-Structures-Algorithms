#include <iostream>
using namespace std;

void toLowercase(char str[]) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

int main() {
    cout <<"Enter string 1: ";
    char str[50];
    cin >> str;

    cout << "Original string: " << str << endl; 
    toLowercase(str);
    cout << "Lowercase string: " << str << endl;

    return 0;
}