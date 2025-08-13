#include <iostream>
using namespace std;
bool isVowel(char ch) {
    ch = tolower(ch); // Convert to lowercase for easier comparison
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    cout <<"Enter string 1: ";
    char str[50];
    cin >> str;
    char result[50];
    int resultIndex = 0;

    for (int i=0; str[i] !='\0'; ++i) {
        if (!isVowel(str[i])) {
            result[resultIndex] = str[i];
            resultIndex++;
        }
    }
    result[resultIndex] = '\0';

    cout << "String without vowels: " << result << endl;

    return 0;
}