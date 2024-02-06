#include <iostream>
#include <stdlib.h>
#define MAX_SIZE 5

using namespace std;

int front = -1;
int rear = -1;

void push(int[], int);
int remove(int[]);
void printQueue(int[]);

int main() {
    int queue[MAX_SIZE];
    int choice, element;
    while (1) {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int pushElement;
                cout << "Enter element to be pushed: ";
                cin >> pushElement;
                push(queue, pushElement);
                break;
            case 2:
                element = remove(queue);
                if (element == -1) {
                    cout << "Underflow" << endl;
                }
                else {
                    cout << "Element popped is: " << element << endl;
                }
                break;
            case 3:
                printQueue(queue);
                break;
            case 4:
                cout << "Exiting!" << endl;
                exit(0);
                break;
            default:
                cout << "Invalid!" << endl;
        }
    }

    return 0;
}

void push(int queue[], int data) {
    rear++;
    if (rear >= MAX_SIZE) {
        cout << "Overflow" << endl;
        rear--;
        return;
    }
    queue[rear] = data;
}

int remove(int queue[]) {
    front++;
    if (front > rear) {
        front--;
        return -1;
    }
    int deletedElement = queue[front];
    return deletedElement;
}

void printQueue(int queue[]) {
    for (int i = front + 1; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}