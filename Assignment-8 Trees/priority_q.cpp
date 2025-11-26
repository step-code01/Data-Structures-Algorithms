#include <iostream>
using namespace std;

class PQ {
    int h[100];
    int n;
public:
    PQ(){ n=0; }

    void push(int v){
        h[n]=v;
        int i=n;
        while(i>0 && h[(i-1)/2] < h[i]){
            int temp = h[i];
            h[i] = h[(i-1)/2];
            h[(i-1)/2] = temp;
            i=(i-1)/2;
        }
        n++;
    }

    int pop(){
        int r=h[0];
        h[0]=h[n-1];
        n--;
        int i=0;
        while(true){
            int l=2*i+1, rgt=2*i+2, mx=i;
            if(l<n && h[l] > h[mx]) mx=l;
            if(rgt<n && h[rgt] > h[mx]) mx=rgt;
            if(mx==i) break;
            int temp = h[i];
            h[i] = h[mx];
            h[mx] = temp;
            i=mx;
        }
        return r;
    }

    bool empty(){ return n==0; }
};

int main(){
    PQ q;
    q.push(10);
    q.push(30);
    q.push(20);
    while(!q.empty())
        cout<<q.pop()<<" ";
}