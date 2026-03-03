/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *ptr1 = head1, *ptr2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < len2 - len1; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 && ptr2) {
        if (ptr1 == ptr2) {
            printf("%d", ptr1->data);
            return 0;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection");
    return 0;
}
