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
        Node* createBST(int arr[], int start, int end) {
            if (start > end) {
                return nullptr;
            }

            int mid = (start + end) / 2;
            Node* root = new Node(arr[mid]);
            root->left = createBST(arr, start, mid - 1);
            root->right = createBST(arr, mid + 1, end);
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
    int arr[] = {3, 5, 6, 8, 10, 11, 12};
    int length = sizeof(arr) / sizeof(arr[0]);
    Node* root = bst.createBST(arr, 0, length - 1);

    bst.preOrder(root);

    return 0;
}