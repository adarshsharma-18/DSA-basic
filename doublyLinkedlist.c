#include <stdio.h>
#include <stdlib.h>

struct node{
     struct node *prev;

    int data;
    struct node *next;
};

struct node * createnode(int data){
    struct node *newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertnode(struct node ** head_ref,int data){
    struct node *ptr = createnode(data);
    ptr->prev = (*head_ref);
    ptr->next = NULL;
    printf("%d\n",ptr->data);

}

void display(struct node *head_ref)
{
    struct node *ptr = head_ref;
    if (ptr == NULL) printf("NULL\n");
    else{
    while (ptr!= NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    }
}

int main(){
    struct node * head=(struct node *)malloc(sizeof(struct node));
    insertnode(&head,2);
    display(head);

}