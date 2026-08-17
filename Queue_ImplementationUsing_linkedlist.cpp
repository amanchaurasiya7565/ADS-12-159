#include<iostream>
using namespace std;
class Node {
    public:
        int data;
        Node *next;
        Node (int val){
            data = val;
            next = NULL;
        }
};
class Queue{
    public:
        Node *front;
        Node *rear;
        Queue(){
            front = rear = NULL;
        }

    bool isEmpty(){
    return front == NULL;
}
    void push(int val){
        Node *newNode = new Node(val);
        if (isEmpty()){
             rear=  front = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void pop(){
       if (isEmpty()){
           cout << "Queue is Empty\n";
           return;
       }
           Node *temp = front;
           int val = front->data;
       if (front ==rear ) {
           front = rear = NULL;
        }
        else{
            front = front->next;
        }
        delete temp;
    }
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return front->data;
    }
    void display(){

        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        Node *temp = front;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    cout<<q.getFront()<<endl;
    q.display();
    cout<<q.isEmpty();
}