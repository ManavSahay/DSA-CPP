#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node{
    int data;
    node* left;
    node* right;
}node;

node *takeInput();
void preOrder(node *root);
void inOrder(node *root);
void postOrder(node *root);
void printTree(node *root);

int main() {
    node *root = takeInput();
    printTree(root);

    return 0;
}

node *takeInput() {
    node *root = (node *) malloc(sizeof(node));
    int rootData;
    cout << "Enter data: ";
    cin >> rootData;
    
    if (rootData == -1) {
        return NULL;
    }
    else {
        root->data = rootData;
        root->left = takeInput();
        root->right = takeInput();
        return root;
    }
}

void printTree(node *root) {
    int choice;
    do {
        cout << "1. PreOrder" << endl;
        cout << "2. InOrder" << endl;
        cout << "3. PostOrder" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                preOrder(root);
                break;

            case 2:
                inOrder(root);
                break;

            case 3:
                postOrder(root);
                break;
            
            case 4:
                cout << "Exitting" << endl;
                break;

            default:
                cout << "Invalid" << endl;
                break;
        }
    } while(choice != 4);
}

void preOrder(node *root) {
    if (root != NULL)
    {
        printf("%d\n",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root) {
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\n",root->data);
        inOrder(root->right);
    }
}

void postOrder(node *root) {
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\n",root->data);
    }
}