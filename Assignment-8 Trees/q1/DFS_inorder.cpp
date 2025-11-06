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
void dfs_inorder(node* root){
    node* walk = root;
    if (walk == nullptr) return;
    dfs_inorder(walk->left);
    cout << walk->data << " ";
    dfs_inorder(walk->right);
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    dfs_inorder(root);
    return 0;
}