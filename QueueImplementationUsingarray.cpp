#include <iostream>
using namespace std;

class Queue {
public:
    int *arr;
    int front;
    int rear;
    int size;

    // Constructor
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == size - 1);
    }

    // Insert element
    void push(int value) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = value;
    }

    // Delete element
    void pop() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Deleted Element: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        return arr[front];
    }

    // Get queue size
    int getSize() {
        if (isEmpty())
            return 0;

        return rear - front + 1;
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue Elements: ";

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    Queue q(20);

    cout << "Inserting Elements..." << endl;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.display();

    cout << "Front Element: " << q.getFront() << endl;
    cout << "Queue Size: " << q.getSize() << endl;

    cout << "\nDeleting Elements..." << endl;

    q.pop();
    q.pop();

    q.display();

    cout << "Front Element: " << q.getFront() << endl;
    cout << "Queue Size: " << q.getSize() << endl;

    cout << "\nAdding More Elements..." << endl;

    q.push(60);
    q.push(70);

    q.display();

    cout << "Is Queue Empty? " << q.isEmpty() << endl;

    return 0;
}