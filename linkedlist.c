#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createnode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp->next != NULL)
    {
        temp->data = data;
        temp->next = NULL;
    }
    return temp;
}

void insertatfront(struct node **head_ref, int data)
{
    struct node *ptr = createnode(data);
    ptr->next = *head_ref;
    *head_ref = ptr;
}

void insertbyindex(struct node **head_ref, int index, int data)
{
    struct node *ptr = createnode(data);
    struct node *temp = *head_ref;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    ptr->data = data;
    ptr->next = temp->next;
    temp->next = ptr;
}

void insertatend(struct node **head_ref, int data)
{
    struct node *temp = createnode(data);
    while (*head_ref != NULL)
    {
        head_ref = &((*head_ref)->next);
    }
    temp->next = *head_ref;
    *head_ref = temp;
}

void deleteatfront(struct node **head_ref)
{
    struct node *ptr = *head_ref;
    *head_ref = (*head_ref)->next;
    ptr->next = NULL;
    free(ptr);
}

/*

temp->next = temp->next->next;


*/
void deletebyindex(struct node **head_ref, int index)
{
    struct node *temp = *head_ref;
    for (int i = 0; i < index - 1; i++)
    {
        (*head_ref) = (*head_ref)->next;
    }
    (*head_ref)->next = (*head_ref)->next->next;

    free(temp);
}

void deleteatend(struct node **head_ref)
{
    
    while ((*head_ref)->next!= NULL)
    {
        (*head_ref) = (*head_ref)->next;
    }
    struct node *temp = (*head_ref)->next;
    (*head_ref)->next = NULL;

    free(temp);
}

void display(struct node *temp)
{

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{

    struct node *head = NULL;
    int n;
    int i=0;
    while (i==0)
    {
        printf("1.insert at front \n");
        printf("2.insert at end \n");
        printf("3.insert by index \n");
        printf("4.delete at front \n");
        printf("5.delete by index \n");
        printf("6.delete at end \n");
        printf("7.display \n");
        printf("8.exit \n");
        printf("enter your choice: ");
        int ch, data, index;
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:

            printf("enter data: ");
            scanf("%d", &data);
            insertatfront(&head, data);
            break;
        case 2:

            printf("enter data: ");
            scanf("%d", &data);
            insertatend(&head, data);
            break;
        case 3:
            printf("enter index: ");
            scanf("%d", &index);
            printf("enter data: ");
            scanf("%d", &data);
            insertbyindex(&head, index, data);
            break;
        case 4:
            deleteatfront(&head);
            break;

        case 5:
            printf("enter index: ");
            scanf("%d", &index);
            deletebyindex(&head, index);
            break;
        case 6:
            deleteatend(&head);
            break;
        case 7:
            display(head);
            break;
        case 8:
            exit(0);
            i=1;
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }
    return 0;
    // scanf("%d",&n)
    // insertatend(&head, 3);
    // insertatend(&head, 1);
    // insertatend(&head, 2);
    // insertatfront(&head, 0);
    // insertbyindex(&head, 2, 4);

    /*struct node * second=NULL;
    struct node * third=NULL;
    struct node * forth=NULL;
    head= (struct node *)malloc(sizeof(struct node));
    second= (struct node *)malloc(sizeof(struct node));
    third= (struct node *)malloc(sizeof(struct node));
    forth= (struct node *)malloc(sizeof(struct node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=12;
    third->next=forth;

    forth->data=123;
    forth->next=NULL;*/

    display(head);

    return 0;
}
