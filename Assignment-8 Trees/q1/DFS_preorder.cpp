#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
void dfs_preorder(node* root){
    node* walk = root;
    if (walk == nullptr) return;
    cout << walk->data << " ";
    dfs_preorder(walk->left);
    dfs_preorder(walk->right);
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    dfs_preorder(root);
    return 0;
}
/*first attempt, 2nd try
void dfs_preorder(node* root){
    node* walk = root;
    if (walk->left != nullptr) return;
    cout << walk->data << " ";
    dfs_preorder(walk->left);
    dfs_preorder(walk->right);
}*/