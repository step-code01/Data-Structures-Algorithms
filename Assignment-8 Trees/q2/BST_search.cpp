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

node* bst_search_recursive(node* root, int key){
    if (root == nullptr || root->data == key) return root;
    if (key < root->data) return bst_search_recursive(root->left, key);
    else return bst_search_recursive(root->right, key);
}

node* bst_search_iter(node* root, int key){
    while (root != nullptr && root->data != key){
        root = (key < root->data) ? root->left : root->right;
    }
    return root;
}

int main(){
    node* root = new node(15);
    root->left = new node(10);
    root->right = new node(20);
    root->left->left = new node(8);
    root->left->right = new node(12);
    root->right->left = new node(17);
    root->right->right = new node(25);

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    node* ans1 = bst_search_recursive(root, key);
    node* ans2 = bst_search_iter(root, key);

    if (ans1 != nullptr)
        cout << key << " found (recursive)\n";
    else
        cout << key << " not found (recursive)\n";

    if (ans2 != nullptr)
        cout << key << " found (iterative)\n";
    else
        cout << key << " not found (iterative)\n";

    return 0;
}
