#include <iostream>
#include <cstring>
using namespace std;
void reverse(string str, int length){
    int i, j;
    char temp;

    for (i=0, j=length-1; i<j; i++,j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    cout << "Reversed string is: " << str << endl;

}

int main() {
    cout <<"Enter string 1: ";
    char str[50];
    cin >> str;

    int length = strlen(str);
    reverse(str,length);
    return 0;
}