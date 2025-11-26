#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=nullptr;
        right=nullptr;
    }
};

int sumLeftLeaves_util(node* r, bool isLeft){
    if(!r) return 0;
    if(!r->left && !r->right && isLeft)
        return r->data;
    return sumLeftLeaves_util(r->left, true) + sumLeftLeaves_util(r->right, false);
}

int sumLeftLeaves(node* root){
    return sumLeftLeaves_util(root, false);
}

int main(){
    node* root=new node(3);
    root->left=new node(9);
    root->right=new node(20);
    root->right->left=new node(15);
    root->right->right=new node(7);
    cout<<sumLeftLeaves(root);
}
