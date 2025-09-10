#include <iostream>
#include <stack>
using namespace std;

void nextGreaterElement(int arr[], int n) {
    stack<int> s;
    int nge[n];
    int i;
    for (i=n-1;i>=0;i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        nge[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }

    for (int i=0;i<n;i++) {
        cout << arr[i] << " -> " << nge[i] << endl;
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreaterElement(arr, n);
    return 0;
}
