#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node* left;
    node* right;
    node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
}node;

node *insertBST(node *root, int data);
bool searchTree(node *root, int data);
void inOrder(node *root);

int main() {
    node *root = NULL;
    int rootValue, length, elementToBeFound;
    bool found;

    cout << "Enter length: ";
    cin >> length;

    cout << "Enter root value: ";
    cin >> rootValue;

    root = insertBST(root, rootValue);

    cout << "Enter other values: " << endl;
    for (int i = 0; i < length - 1; i++) {
        int value;
        cin >> value;
        insertBST(root, value);
    }

    cout << "---------------------" << endl;
    inOrder(root);
    cout << "---------------------" << endl;

    cout << "Input element to be found: ";
    cin >> elementToBeFound;

    found = searchTree(root, elementToBeFound);
    if (found) {
        cout << "Element found" << endl;
    }
    else {
        cout << "Element not found" << endl;
    }

    return 0;
}

void inOrder(node *root) {
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\n",root->data);
        inOrder(root->right);
    }
}

node *insertBST(node *root, int data) {
    if (root == NULL) {
        return new node(data);
    }

    if (data < root->data) {
        root->left = insertBST(root->left, data);
    }
    else {
        root->right = insertBST(root->right, data);
    }
    return root;
}

bool searchTree(node *root, int data) {
    if (root->data == data) {
        return true;
    }
    else if (root == NULL) {
        return false;
    }
    else if (root->data < data) {
        return searchTree(root->right, data);
    }
    else {
        return searchTree(root->left, data);
    }
}