#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        int data;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(int data): data(data) {}
};

class BST {
    private:
        vector<int> inorder;
        
        void getInOrder(Node* root) {
            if (root == nullptr) {
                return;
            }

            getInOrder(root->left);
            inorder.push_back(root->data);
            getInOrder(root->right);
        }

        Node* createBST(int start, int end) {
            if (start > end) {
                return nullptr;
            }

            int mid = (start + end) / 2;
            Node* root = new Node(inorder.at(mid));
            root->left = createBST(start, mid - 1);
            root->right = createBST(mid + 1, end);
            return root;
        }

    public:
        void preOrder(Node* root) {
            if (root == nullptr) {
                return;
            }
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }

        Node* balanceBST(Node* root) {
            getInOrder(root);

            root = createBST(0, inorder.size() - 1);
            return root;
        }
};

int main() {
    BST bst;
    Node* root = new Node(8);
    root->left = new Node(6);
    root->left->left = new Node(5);
    root->left->left->left = new Node(3);

    root->right = new Node(10);
    root->right->right = new Node(11);
    root->right->right->right = new Node(12);

    root = bst.balanceBST(root);
    bst.preOrder(root);

    return 0;
}