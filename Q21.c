#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){

    int n;
    scanf("%d",&n);

    struct Node *head=NULL,*temp=NULL,*newnode=NULL;

    for(int i=0;i<n;i++){

        newnode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }

    struct Node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }

    return 0;
}