#include <iostream>
#include <vector>

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
    private:
        void printPath(vector<int> path) {
            for (int i = 0; i < path.size(); i++) {
                cout << path.at(i) << " -> ";
            }
            cout << "nullptr" << endl;
        }

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

        void printRoot2LeafPath(Node* root, vector<int> path) {
            if (root == nullptr) {
                return;
            }

            path.push_back(root->data);

            if (root->left == nullptr && root->right == nullptr) {
                printPath(path);
            }

            printRoot2LeafPath(root->left, path);
            printRoot2LeafPath(root->right, path);

            path.pop_back();
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

    vector<int> path;

    bst.printRoot2LeafPath(root, path);

    return 0;
}