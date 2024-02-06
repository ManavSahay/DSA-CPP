#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

class Node {
    public:
        int data;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(int data): data(data) {}
};

class Info {
    public:
        bool isBST;
        int size;
        int minimum;
        int maximum;

        Info(bool isBST, int size, int minimum, int maximum) {
            this->isBST = isBST;
            this->size = size;
            this->minimum = minimum;
            this->maximum = maximum;
        }
};

class BST {
    public:
        int maxBST = 0;

        Info* largestBST(Node* root) {
            if (root == nullptr) {
                return new Info(true, 0, INT_MAX, INT_MIN);
            }

            Info* leftInfo = largestBST(root->left);
            Info* rightInfo = largestBST(root->right);
            int size = leftInfo->size + rightInfo->size + 1;
            int minimum = min(root->data, min(leftInfo->minimum, rightInfo->minimum));
            int maximum = max(root->data, max(leftInfo->maximum, rightInfo->maximum));

            if (root->data <= leftInfo->maximum || root->data >= rightInfo->minimum) {
                return new Info(false, size, minimum, maximum);
            }

            if (leftInfo->isBST && rightInfo->isBST) {
                maxBST = max(maxBST, size);
                return new Info(true, size, minimum, maximum);
            }

            return new Info(false, size, minimum, maximum);
        }
};

int main() {
    BST bst;
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    Info* info = bst.largestBST(root);
    cout << "Largest BST = " << bst.maxBST << endl;

    return 0;
}