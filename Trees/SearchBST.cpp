#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

class BST {
    public:
        Node* insert(Node* root, int val) {
            if (root == nullptr) {
                return new Node(val);
            }

            if (root->data > val) {
                root->left = insert(root->left, val);
            }

            else {
                root->right = insert(root->right, val);
            }
            return root;
        }

        void inorder(Node* root) {
            if (root == nullptr) {
                return;
            }
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }

        bool search(Node* root, int key) {
            if (root == nullptr) {
                return false;
            }

            if (root->data == key) {
                return true;
            }

            if (root->data > key) {
                return search(root->left, key);
            }

            else {
                return search(root->right, key);
            }
        }
};

int main() {
    int arr[] = {5, 1, 3, 4, 2, 7};
    int length = sizeof(arr) / sizeof(arr[0]);
    Node* root = nullptr;
    BST bst;

    for (int i = 0; i < length; i++) {
        root = bst.insert(root, arr[i]);
    }

    bst.inorder(root);
    cout << endl;

    if (bst.search(root, 1)) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not Found" << endl;
    }

    return 0;
}