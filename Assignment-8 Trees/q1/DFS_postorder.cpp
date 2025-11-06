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
void dfs_postorder(node* root){
    node* walk = root;
    if (walk == nullptr) return;
    dfs_postorder(walk->left);
    dfs_postorder(walk->right);
    cout << walk->data << " ";
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    dfs_postorder(root);
    return 0;
}