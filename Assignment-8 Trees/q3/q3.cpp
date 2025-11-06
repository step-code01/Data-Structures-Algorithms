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

node* insert(node* root, int key){
    if (root == nullptr)
        return new node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        cout << "Duplicate value " << key << " ignored.\n";

    return root;
}

node* deleteNode(node* root, int key){
    if (root == nullptr) return root;

    if (key < root->data) 
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* succParent = root;
        node* succ = root->right;
        while (succ->left != nullptr) {
            succParent = succ;
            succ = succ->left;
        }

        root->data = succ->data;

        if (succParent->left == succ) succParent->left = deleteNode(succParent->left, succ->data);
        else succParent->right = deleteNode(succParent->right, succ->data);
    }
    return root;
}

int maxDepth(node* root){
    if (root == nullptr)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int minDepth(node* root){
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    if (root->left == nullptr)
        return 1 + minDepth(root->right);
    if (root->right == nullptr)
        return 1 + minDepth(root->left);

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;
}

void inorder(node* root){
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node* root = nullptr;

    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 25);

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    cout << "Maximum Depth: " << maxDepth(root) << endl;
    cout << "Minimum Depth: " << minDepth(root) << endl;

    int delKey;
    cout << "\nEnter element to delete: ";
    cin >> delKey;

    root = deleteNode(root, delKey);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    cout << "Maximum Depth now: " << maxDepth(root) << endl;
    cout << "Minimum Depth now: " << minDepth(root) << endl;

    return 0;
}
