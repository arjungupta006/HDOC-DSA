#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    int n,x,key;
    struct node *head=NULL,*temp=NULL,*newnode,*prev,*curr;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=NULL;
  
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }

    scanf("%d",&key);

    curr=head;
    prev=NULL;

    while(curr!=NULL){
        if(curr->data==key){
            if(prev==NULL){
                head=curr->next;
            }else{
                prev->next=curr->next;
            }
            free(curr);
            break;
        }
        prev=curr;
        curr=curr->next;
    }

    temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        if(temp->next!=NULL) printf(" ");
        temp=temp->next;
    }

    return 0;
}