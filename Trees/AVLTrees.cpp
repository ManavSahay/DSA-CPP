#include <iostream>
#include <cmath>

using namespace std;

class Node {
    public:
        int data, height;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(int data) {
            this->data = data;
            this->height = 1;
        }
};

class AVL {
    private:
        int height(Node* root) {
            if (root == nullptr) {
                return 0;
            }
            return root->height;
        }

        int getBalance(Node* root) {
            if (root == nullptr) {
                return 0;
            }
            return height(root->left) - height(root->right);
        }

        Node* rightRotate(Node* y) {
            Node* x = y->left;
            Node* temp = x->right;

            x->right = y;
            y->left = temp;

            y->height = max(height(y->left), height(y->right)) + 1;
            x->height = max(height(x->left), height(x->right)) + 1;

            return x;
        }
        
        Node* leftRotate(Node* x) {
            Node* y = x->right;
            Node* temp = y->left;

            y->left = x;
            x->right = temp;

            x->height = max(height(x->left), height(x->right)) + 1;
            y->height = max(height(y->left), height(y->right)) + 1;

            return y;
        }

    public:
        Node* insert(Node* root, int key) {
            if (root == nullptr) {
                return new Node(key);
            }

            if (key < root->data) {
                root->left = insert(root->left, key);
            }
            else if (key > root->data) {
                root->right = insert(root->right, key);
            }
            else {
                return root;
            }

            root->height = 1 + max(height(root->left), height(root->right));

            int bf = getBalance(root);

            // LL Case
            if (bf > 1 && key < root->left->data) {
                return rightRotate(root);
            }

            // RR Case
            if (bf < -1 && key > root->right->data) {
                return leftRotate(root);
            }

            // LR Case
            if (bf > 1 && key > root->left->data) {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }

            // RL Case
            if (bf < -1 && key < root->right->data) {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

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
    AVL avl;
    Node* root = nullptr;
    int arr[] = {10, 20, 30, 40, 50, 25};
    int length = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < length; i++) {
        root = avl.insert(root, arr[i]);
    }

    avl.preOrder(root);

    return 0;
}
