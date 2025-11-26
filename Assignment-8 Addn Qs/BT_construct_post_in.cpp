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

node* build_util(int post[], int in[], int n, int &pi, int s, int e){
    if(s>e) return nullptr;
    node* r = new node(post[pi--]);
    int i = idx(in, n, r->data);
    r->right = build_util(post, in, n, pi, i+1, e);
    r->left  = build_util(post, in, n, pi, s, i-1);
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
    int post[n], in[n];
    for(int i=0;i<n;i++) cin>>in[i];
    for(int i=0;i<n;i++) cin>>post[i];
    int pi = n-1;
    node* root = build_util(post, in, n, pi, 0, n-1);
    print(root);
}
