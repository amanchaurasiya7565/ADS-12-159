#include <iostream>
using namespace std;

class CircularQueue {
public:
    int *arr;
    int front;
    int rear;
    int size;

    // Constructor
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor
    ~CircularQueue() {
        delete[] arr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if queue is full
    bool isFull() {
        return (front == 0 && rear == size - 1) ||
               (rear == (front - 1 + size) % size);
    }

    // Insert element
    void push(int val) {
        // Queue is full
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }

        // Queue is empty
        if (front == -1) {
            front = rear = 0;
        }

        // Rear reaches end, move to beginning
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        }

        // Normal insertion
        else {
            rear++;
        }

        arr[rear] = val;
    }

    // Delete element
    void pop() {
        // Queue is empty
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        // Only one element
        if (front == rear) {
            front = rear = -1;
        }

        // Front reaches end, move to beginning
        else if (front == size - 1) {
            front = 0;
        }

        // Normal deletion
        else {
            front++;
        }
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue: ";

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % size;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.display();

    // Trying to insert when queue is full
    q.push(6);

    q.pop();
    q.pop();

    q.display();

    // Circular insertion
    q.push(6);
    q.push(7);

    q.display();

    return 0;
}

