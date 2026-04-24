#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int x) {
        Node* temp = new Node(x);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == NULL) {
            cout << -1 << endl;
            return;
        }
        Node* temp = front;
        cout << front->data << endl;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
    }
};

int main() {
    int N;
    cin >> N;
    Queue q;

    while (N--) {
        string op;
        cin >> op;
        if (op == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (op == "dequeue") {
            q.dequeue();
        }
    }
    return 0;
}
