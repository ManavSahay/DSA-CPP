#include <iostream>
#include <stdlib.h>
#define MAX_SIZE 5

using namespace std;

int top = -1;

void push(int[], int);
int pop(int[]);
void printStack(int[]);

int main() {
    int stack[MAX_SIZE];
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
                push(stack, pushElement);
                break;
            case 2:
                element = pop(stack);
                if (element == -1) {
                    cout << "Underflow" << endl;
                }
                else {
                    cout << "Element popped is: " << element << endl;
                }
                break;
            case 3:
                printStack(stack);
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

void push(int stack[], int data) {
    top++;
    if (top == MAX_SIZE) {
        cout << "Overflow" << endl;
        top--;
        return;
    }
    stack[top] = data;
}

int pop(int stack[]) {
    if (top <= -1) {
        return -1;
    }
    int poppedElement = stack[top];
    top--;
    return poppedElement;
}

void printStack(int stack[]) {
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}