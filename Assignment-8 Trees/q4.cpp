#include <iostream>
using namespace std;

class node {
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
node* prevNode = nullptr;

bool isBST(node* root) {
    if (root == nullptr)
        return true;

    if (!isBST(root->left))
        return false;

    if (prevNode != nullptr && root->data <= prevNode->data)
        return false;

    prevNode = root; 
    return isBST(root->right);
}

void inorder(node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node* root1 = new node(15);
    root1->left = new node(10);
    root1->right = new node(20);
    root1->left->left = new node(8);
    root1->left->right = new node(12);
    root1->right->left = new node(17);
    root1->right->right = new node(25);

    cout << "Tree 1 inorder: ";
    inorder(root1);
    cout << endl;

    prevNode = nullptr;
    if (isBST(root1))
        cout << "BST yes\n";
    else
        cout << "BST no\n";

    node* root2 = new node(10);
    root2->left = new node(5);
    root2->right = new node(8);

    cout << "\nTree 2 inorder: ";
    inorder(root2);
    cout << endl;

    prevNode = nullptr;
    if (isBST(root1))
        cout << "BST yes\n";
    else
        cout << "BST no\n";


    return 0;
}
