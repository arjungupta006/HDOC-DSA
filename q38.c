#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Deque {
    struct Node *front, *rear;
    int size;
};

struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

void push_front(struct Deque* dq, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = dq->front;

    if (dq->front != NULL)
        dq->front->prev = temp;
    else
        dq->rear = temp;

    dq->front = temp;
    dq->size++;
}

void push_back(struct Deque* dq, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = dq->rear;

    if (dq->rear != NULL)
        dq->rear->next = temp;
    else
        dq->front = temp;

    dq->rear = temp;
    dq->size++;
}

int pop_front(struct Deque* dq) {
    if (dq->front == NULL)
        return -1;

    struct Node* temp = dq->front;
    int val = temp->data;

    dq->front = dq->front->next;
    if (dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    dq->size--;
    return val;
}

int pop_back(struct Deque* dq) {
    if (dq->rear == NULL)
        return -1;

    struct Node* temp = dq->rear;
    int val = temp->data;

    dq->rear = dq->rear->prev;
    if (dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    dq->size--;
    return val;
}

int front(struct Deque* dq) {
    if (dq->front == NULL)
        return -1;
    return dq->front->data;
}

int back(struct Deque* dq) {
    if (dq->rear == NULL)
        return -1;
    return dq->rear->data;
}

int empty(struct Deque* dq) {
    return dq->size == 0;
}

int size(struct Deque* dq) {
    return dq->size;
}

void clear(struct Deque* dq) {
    while (dq->front != NULL)
        pop_front(dq);
}

void reverse(struct Deque* dq) {
    struct Node* curr = dq->front;
    struct Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL)
        dq->front = temp->prev;

    temp = dq->front;
    dq->front = dq->rear;
    dq->rear = temp;
}

void printDeque(struct Deque* dq) {
    struct Node* temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Deque* dq = createDeque();
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            int x;
            scanf("%d", &x);
            push_front(dq, x);
        } else if (strcmp(op, "push_back") == 0) {
            int x;
            scanf("%d", &x);
            push_back(dq, x);
        } else if (strcmp(op, "pop_front") == 0) {
            printf("%d\n", pop_front(dq));
        } else if (strcmp(op, "pop_back") == 0) {
            printf("%d\n", pop_back(dq));
        } else if (strcmp(op, "front") == 0) {
            printf("%d\n", front(dq));
        } else if (strcmp(op, "back") == 0) {
            printf("%d\n", back(dq));
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", size(dq));
        } else if (strcmp(op, "empty") == 0) {
            printf("%d\n", empty(dq));
        } else if (strcmp(op, "clear") == 0) {
            clear(dq);
        } else if (strcmp(op, "reverse") == 0) {
            reverse(dq);
        }
    }

    printDeque(dq);

    return 0;
}
