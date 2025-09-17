#include <iostream>
#include <queue>
using namespace std;
void generateBinary(int n) {
    queue<string> q;
    q.push("1");
    int i;
    for (i=0;i<n;i++) {
        string current = q.front();
        cout << current << " ";
        q.pop();

        q.push(current + "0");
        q.push(current + "1");
    }
    cout << endl;
}

int main() {
    int n1 = 2;
    cout << "Input: n = " << n1 << endl;
    cout << "Output: ";
    generateBinary(n1);

    cout << "--------------------" << endl;

    int n2 = 10;
    cout << "Input: n = " << n2 << endl;
    cout << "Output: ";
    generateBinary(n2);

    return 0;
}