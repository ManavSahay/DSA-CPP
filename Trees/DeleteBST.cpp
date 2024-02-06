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

        Node* deleteNode(Node* root, int val) {
            if (root->data < val) {
                root->right = deleteNode(root->right, val);
            }
            else if (root->data > val) {
                root->left = deleteNode(root->left, val);
            }
            else {
                // Case 1 -> Leaf Node
                if (root->left == nullptr && root->right == nullptr) {
                    return nullptr;
                }

                // Case 2 -> Only left or right child exists
                if (root->left == nullptr) {
                    return root->right;
                }
                else if (root->right == nullptr) {
                    return root->left;
                }

                // Case 3 -> If both the child exists
                Node* IS = findInorderSuccessor(root->right);
                root->data = IS->data;
                root->right = deleteNode(root->right, IS->data);
            }
            return root;
        }
        
        Node* findInorderSuccessor(Node* root) {
            while (root->left != nullptr) {
                root = root->left;
            }
            return root;
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

    root = bst.deleteNode(root, 5);
    bst.inorder(root);

    return 0;
}