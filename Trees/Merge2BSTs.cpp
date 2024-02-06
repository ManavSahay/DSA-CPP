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
        void getInOrder(Node* root, vector<int>& arr) {
            if (root == nullptr) {
                return;
            }

            getInOrder(root->left, arr);
            arr.push_back(root->data);
            getInOrder(root->right, arr);
            
        }

        Node* createBST(vector<int> arr, int start, int end) {
            if (start > end) {
                return nullptr;
            }

            int mid = (start + end) / 2;
            Node* root = new Node(arr.at(mid));
            root->left = createBST(arr, start, mid - 1);
            root->right = createBST(arr, mid + 1, end);
            return root;
        }

    public:
        Node* mergeBSTs(Node* root1, Node* root2) {
            vector<int> arr1;
            getInOrder(root1, arr1);
            
            vector<int> arr2;
            getInOrder(root2, arr2);

            vector<int> finalArr;
            int i = 0, j = 0;
            while (i < arr1.size() && j < arr2.size()) {
                if (arr1.at(i) < arr2.at(j)) {
                    finalArr.push_back(arr1.at(i));
                    i++;
                }
                else {
                    finalArr.push_back(arr2.at(j));
                    j++;
                }
            }

            while (i < arr1.size()) {
                finalArr.push_back(arr1.at(i));
                i++;
            }

            while (j < arr2.size()) {
                finalArr.push_back(arr2.at(j));
                j++;
            }

            return createBST(finalArr, 0, finalArr.size() - 1);
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
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* root = bst.mergeBSTs(root1, root2);
    bst.preOrder(root);

    return 0;
}
