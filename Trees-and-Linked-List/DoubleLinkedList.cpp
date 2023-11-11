#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
    int data;
    node *next;
    node *prev;
}node;

node *head, *newNode, *temp1, *temp2, *temp3;

int sizeGlobal;

void createList(int length);
void printList();
void insertFirst();
void insertMiddle(int position);
void insertLast();
void deleteFirst();
void deleteLast();
void deleteMiddle(int position);

int main() {
    int length, choice;
    cout << "Enter Length: ";
    cin >> length;
    createList(length);
    printList();

    do {
        cout << "----------------------" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Exit" << endl;
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
                cout << "Exitting" << endl;
                break;
            
            default:
                cout << "Invalid" << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

void createList(int length) {
    sizeGlobal = length;
    for (int i = 0; i < length; i++) {
        newNode = (node *) malloc(sizeof(node));
        cout << "Enter data: ";
        cin >> newNode->data;

        if (head == NULL) {
            head = newNode;
            temp1 = newNode;
            head->prev = NULL;
        }
        else {
            temp1->next = newNode;
            newNode->prev = temp1;
            temp1 = newNode;
        }
    }
    temp1->next = NULL;
    temp1 = head;
    temp2 = temp1->next;
}

void printList() {
    int choice;
    cout << "------------------" << endl;
    cout << "How to print" << endl;
    cout << "1. From Left" << endl;
    cout << "2. From Right" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            while (temp1 != NULL) {
                cout << temp1->data << endl;
                temp1 = temp1->next;
            }
            break;
        case 2:
            while (temp1->next != NULL) {
                temp1 = temp1->next;
            }
            while (temp1 != NULL) {
                cout << temp1->data << endl;
                temp1 = temp1->prev;
            }
            break;
        default:
            cout << "Wrong Input" << endl;
    }
    temp1 = head;
}

void insertFirst() {
    newNode = (node *) malloc(sizeof(node *));
    cout << "Enter data: ";
    cin >> newNode->data;

    newNode->prev = NULL;
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    temp1 = head;
    sizeGlobal++;
}

void insertLast() {
    newNode = (node *) malloc(sizeof(node));
    cout << "Enter data: ";
    cin >> newNode->data;

    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }

    temp1->next = newNode;
    newNode->prev = temp1;
    newNode->next = NULL;
    temp1 = head;
    sizeGlobal++;
}

void insertMiddle(int position) {
    if (position == 0 || position > sizeGlobal) {
        cout << "Invalid Position" << endl;
    }

    newNode = (node *) malloc(sizeof(node));
    cout << "Enter data: ";
    cin >> newNode->data;

    for (int i = 0; i < position - 1; i++) {
        temp1 = temp1->next;
        temp2 = temp1->next;
    }
    newNode->prev = temp1;
    newNode->next = temp2;
    temp1->next = newNode;
    temp2->prev = newNode;

    temp1 = head;
    temp2 = temp1->next;

    sizeGlobal++;
}

void deleteFirst() {
    temp1 = head->next;
    temp1->prev = NULL;
    free(head);
    head = temp1;
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
    if (position == 0 || position > sizeGlobal) {
        cout << "Invalid Position" << endl;
    }

    temp2 = temp1->prev;
    temp3 = temp1;
    temp1 = temp1->next;

    for (int i = 0; i < position; i++) {
        temp2 = temp1->prev;
        temp3 = temp1;
        temp1 = temp1->next;
    }

    free(temp3);
    temp2->next = temp1;
    temp1->prev = temp2;

    temp1 = head;
    temp2 = temp1->next;

    sizeGlobal--;
}