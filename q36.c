#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;

    if (q->rear == NULL) {
        temp->next = temp;
        q->front = q->rear = temp;
        return;
    }

    temp->next = q->front;
    q->rear->next = temp;
    q->rear = temp;
}

void dequeue(struct Queue* q) {
    if (q->front == NULL)
        return;

    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
        return;
    }

    struct Node* temp = q->front;
    q->front = q->front->next;
    q->rear->next = q->front;
    free(temp);
}

void printQueue(struct Queue* q) {
    if (q->front == NULL)
        return;

    struct Node* temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
}

int main() {
    int n, m, x;
    scanf("%d", &n);

    struct Queue* q = createQueue();

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(q, x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue(q);
    }

    printQueue(q);

    return 0;
}
