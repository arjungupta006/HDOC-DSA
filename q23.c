/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Node* append(struct Node* head,int val){
    struct Node* temp = createNode(val);
    if(head==NULL) return temp;
    struct Node* p = head;
    while(p->next!=NULL) p = p->next;
    p->next = temp;
    return head;
}

struct Node* merge(struct Node* a, struct Node* b){
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while(a && b){
        if(a->data <= b->data){
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    if(a) tail->next = a;
    else tail->next = b;

    return dummy.next;
}

void printList(struct Node* head){
    while(head){
        printf("%d ",head->data);
        head = head->next;
    }
}

int main(){
    int n,m,x;
    struct Node* l1=NULL;
    struct Node* l2=NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        l1 = append(l1,x);
    }

    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        l2 = append(l2,x);
    }

    struct Node* merged = merge(l1,l2);
    printList(merged);
    return 0;
}