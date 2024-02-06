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

        void printInRange(Node* root, int k1, int k2) {
            if (root == nullptr) {
                return;
            }

            if (root->data >= k1 && root->data <= k2) {
                printInRange(root->left, k1, k2);
                cout << root->data << " ";
                printInRange(root->right, k1, k2);
            }

            else if (root->data < k1) {
                printInRange(root->left, k1, k2);
            }

            else {
                printInRange(root->right, k1, k2);
            }
        }
};

int main() {
    BST bst;
    int values[] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    int length = sizeof(values) / sizeof(values[0]);
    Node* root = nullptr;

    for (int i = 0; i < length; i++) {
        root = bst.insert(root, values[i]);
    }

    bst.inorder(root);
    cout << endl;

    bst.printInRange(root, 5, 12);

    return 0;
}