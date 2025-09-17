#include <iostream>
#include <queue>
using namespace std;

void printQueue(std::queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void sortQueue(queue<int> &q){
    int n = q.size();
    for(int i=0; i<n; i++){
        int min_val = q.front();
        q.pop();
        for(int j=0; j<n-1-i; j++){
            int current = q.front();
            q.pop();
            if(current < min_val){
                q.push(min_val);
                min_val = current;
            } else {
                q.push(current);
            }
        }
        q.push(min_val);
    }
}

int main(){
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    cout << "Input: ";
    printQueue(q);

    sortQueue(q);

    cout << "Output: ";
    printQueue(q);

    return 0;
}