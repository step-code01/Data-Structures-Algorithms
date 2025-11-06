#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

node* search(node* root, int key){
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

node* bst_min(node* root){
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}
node* bst_max(node* root) {
    while (root && root->right != nullptr)
        root = root->right;
    return root;
}
node* inorder_successor(node* root, node* x) {
    if (x->right != nullptr)
        return bst_min(x->right);

    node* succ = nullptr;
    while (root != nullptr) {
        if (x->data < root->data) {
            succ = root;
            root = root->left;
        } 
        else if (x->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}
node* inorder_predecessor(node* root, node* x) {
    if (x->left != nullptr)
        return bst_max(x->left);

    node* pred = nullptr;
    while (root != nullptr) {
        if (x->data > root->data) {
            pred = root;
            root = root->right;
        } 
        else if (x->data < root->data)
            root = root->left;
        else
            break;
    }
    return pred;
}

int main() {
    node* root = new node(15);
    root->left = new node(10);
    root->right = new node(20);
    root->left->left = new node(8);
    root->left->right = new node(12);
    root->right->left = new node(17);
    root->right->right = new node(25);

    int key;
    cout << "Enter key to find its inorder successor and predecessor: ";
    cin >> key;

    node* target = search(root, key);
    if (!target) {
        cout << "Key not found in BST\n";
        return 0;
    }

    node* succ = inorder_successor(root, target);
    node* pred = inorder_predecessor(root, target);

    if (pred)
        cout << "Inorder Predecessor of " << key << " is " << pred->data << endl;
    else
        cout << "No inorder predecessor for " << key << endl;

    if (succ)
        cout << "Inorder Successor of " << key << " is " << succ->data << endl;
    else
        cout << "No inorder successor for " << key << endl;

    return 0;
}
