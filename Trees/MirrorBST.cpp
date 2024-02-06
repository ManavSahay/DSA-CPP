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

        Node* createMirror(Node* root) {
            if (root == nullptr) {
                return nullptr;
            }

            Node* leftMirror = createMirror(root->left);
            Node* rightMirror = createMirror(root->right);

            root->left = rightMirror;
            root->right = leftMirror;
            return root;
        }

        void preOrder(Node* root) {
            if (root == nullptr) {
                return;
            }
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
};

int main() {
    BST bst;
    int values[] = {8, 5, 3, 6, 10, 11};
    int length = sizeof(values) / sizeof(values[0]);
    Node* root = nullptr;

    for (int i = 0; i < length; i++) {
        root = bst.insert(root, values[i]);
    }

    bst.inorder(root);
    cout << endl;

    root = bst.createMirror(root);
    bst.preOrder(root);

    return 0;
}