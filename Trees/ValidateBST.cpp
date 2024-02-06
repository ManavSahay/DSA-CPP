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

        bool isValidBST(Node* root, Node* min, Node* max) {
            if (root == nullptr) {
                return true;
            }

            if (min != nullptr && root->data <= min->data) {
                return false;
            }

            else if (max != nullptr && root->data >= max->data) {
                return false;
            }

            return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
        }  
};

int main() {
    BST bst;
    int values[] = {8, 5, 3, 6, 10, 11, 14};
    int length = sizeof(values) / sizeof(values[0]);
    Node* root = nullptr;

    for (int i = 0; i < length; i++) {
        root = bst.insert(root, values[i]);
    }

    bst.inorder(root);
    cout << endl;

    if (bst.isValidBST(root, nullptr, nullptr)) {
        cout << "Valid BST" << endl;
    }
    else {
        cout << "Invalid BST" << endl;
    }

    return 0;
}