#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int d){ data=d; left=nullptr; right=nullptr; }
};

int idx(int in[], int n, int v){
    for(int i=0;i<n;i++) if(in[i]==v) return i;
    return -1;
}

node* build_util(int pre[], int in[], int n, int &pi, int s, int e){
    if(s>e) return nullptr;
    node* r = new node(pre[pi++]);
    int i = idx(in, n, r->data);
    r->left = build_util(pre, in, i, pi, s, i-1);
    r->right = build_util(pre, in, n, pi, i+1, e);
    return r;
}

void print(node* r){
    if(!r) return;
    cout<<r->data<<" ";
    print(r->left);
    print(r->right);
}

int main(){
    int n; cin>>n;
    int pre[n], in[n];
    for(int i=0;i<n;i++) cin>>pre[i];
    for(int i=0;i<n;i++) cin>>in[i];
    int pi=0;
    node* root = build_util(pre, in, n, pi, 0, n-1);
    print(root);
}
