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
void bst_min(node* root){
    if (root == nullptr){
        cout << "Tree is empty\n";
        return;
    }
    while (root->left!=nullptr){
        root = root->left;
    }
    cout << "Minimum element: " << root->data<<endl;
    return;
}
void bst_max(node* root){
    if (root == nullptr){ 
        cout << "Tree is empty\n";
        return;
    }
    while (root->right!=nullptr){
        root = root->right;
    }
    cout << "Maximum element: " << root->data<<endl;
    return;
}
int main(){
    node* root = new node(15);
    root->left = new node(6);
    root->left->left = new node(3);
    root->left->left->left = new node(2);
    root->left->left->right = new node(4);
    root->left->right = new node(7);
    root->left->right->right = new node(13);
    root->left->right->right->left = new node(9);
    root->right = new node(18);
    root->right->left = new node(17);
    root->right->right = new node(20);

    bst_min(root);
    bst_max(root);
    return 0;
}