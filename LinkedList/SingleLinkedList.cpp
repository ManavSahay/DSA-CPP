#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
    int data;
    node *next;
}node;

node *head, *insertionNode, *temp1, *temp2, *temp3, *newNode;
int sizeGlobal;

void createList();
void printList();
void insertFirst();
void insertLast();
void insertMiddle(int position);
void deleteFirst();
void deleteLast();
void deleteMiddle(int position);
void reverse();

int main() {
    int choice;
    createList();
    printList();

    do {
        cout << "----------------------" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Reverse" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "----------------------" << endl;

        switch (choice) {
        
            case 1:
                int insCase;
                cout << "----------------------" << endl;
                cout << "1. Insert at first" << endl;
                cout << "2. Insert at last" << endl;
                cout << "3. Insert at a position" << endl;
                cout << "Enter your choice: ";
                cin >> insCase;

                switch (insCase) {
                    case 1:
                        insertFirst();
                        break;
                    
                    case 2:
                        insertLast();
                        break;
                    case 3:
                        int position;
                        cout << "Enter position: ";
                        cin >> position;
                        insertMiddle(position);
                        break;
                    default:
                        cout << "Invalid" << endl;
                        break;
                }

                break;
            
            case 2:
                int delCase;
                cout << "----------------------" << endl;
                cout << "1. Deletion at first" << endl;
                cout << "2. Deletion at last" << endl;
                cout << "3. Deletion at a position" << endl;
                cout << "Enter your choice: ";
                cin >> delCase;

                switch (delCase) {
                    case 1:
                        deleteFirst();
                        break;
                    
                    case 2:
                        deleteLast();
                        break;
                    case 3:
                        int position;
                        cout << "Enter position: ";
                        cin >> position;
                        deleteMiddle(position);
                        break;
                    default:
                        cout << "Invalid" << endl;
                        break;
                }

                break;
            
            case 3:
                printList();
                break;

            case 4:
                reverse();
                break;

            case 5:
                cout << "Exitting" << endl;
                break;
            
            default:
                cout << "Invalid" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

void createList() {
    int size;
    cout << "Enter Size: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        newNode = (node *) malloc (sizeof(node));
        cout << "Enter value: ";
        cin >> newNode->data;

        if (head == NULL) {
            head = newNode;
            temp1 = newNode;
        }
        else {
            temp1->next = newNode;
            temp1 = newNode;
        }
    }
    temp1->next = NULL;
    temp1 = head;
    temp2 = temp1->next;
    sizeGlobal = size;
}

void printList() {
    cout << "----------------------" << endl;
    while (temp1 != NULL) {
        cout << temp1->data << endl;
        temp1 = temp1->next;
    }
    cout << "----------------------" << endl;
    temp1 = head;
}

void insertFirst() {
    newNode = (node *) malloc(sizeof(node));
    cout << "Enter value: ";
    cin >> newNode->data;
    newNode->next = head;
    head = newNode;
    temp1 = head;
    sizeGlobal++;
}

void insertLast() {
    newNode = (node *) malloc(sizeof(node));
    cout << "Enter value: ";
    cin >> newNode->data;

    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = newNode;
    newNode->next = NULL;
    temp1 = head;
    sizeGlobal++;
}

void insertMiddle(int position) {
    if (position > sizeGlobal) {
        cout << "Size exceeded" << endl;
        return;
    }
    if (position == 0) {
        cout << "0 cannot be entered" << endl;
        return;
    }
    for (int i = 0; i < position - 1; i++) {
        temp1 = temp1->next;
        temp2 = temp1->next;
    }

    newNode = (node *) malloc(sizeof(node));
    cout << "Enter value: ";
    cin >> newNode->data;
    temp1->next = newNode;
    newNode->next = temp2;
    temp1 = head;
    temp2 = temp1->next;
    sizeGlobal++;
}

void deleteFirst() {
    head = head->next;
    free(temp1);
    temp1 = head;
    sizeGlobal--;
}

void deleteLast() {
    while (temp1->next != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = NULL;
    free(temp1);
    temp1 = head;
    temp2 = temp1->next;
    sizeGlobal--;
}

void deleteMiddle(int position) {
    if (position > sizeGlobal) {
        cout << "Size exceeded" << endl;
        return;
    }
    if (position == 0) {
        cout << "0 cannot be entered" << endl;
        return;
    }
    for (int i = 0; i < position; i++) {
        temp2 = temp1;
        temp1 = temp1->next;
        temp3 = temp1->next;
    }
    free(temp1);
    temp2->next = temp3;
    temp1 = head;
    temp2 = temp1->next;
    sizeGlobal--;
}

void reverse() {
    temp2 = temp1->next;
    node *temp3;
    do
    {
        temp3 = temp2->next;
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = temp3;
    } while (temp2->next != NULL);
    temp2->next = temp1;
    head->next = NULL;
    head = temp2;
    temp1 = head;
}