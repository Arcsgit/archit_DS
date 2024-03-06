#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *getnode() {
    return malloc(sizeof(struct node));
}

void display(struct node *head) {
    for(struct node *cur=head; cur!=NULL; cur=cur->next)
        printf("%d ", cur->data);
    printf("\n");
}

int search(struct node *head, int key) {
    struct node *cur=head;
    for(int pos=1; cur!=NULL; cur=cur->next, pos++)
    {
        if(cur->data == key)
            return pos;
    }
    return 0;
} 

struct node *insertFront(struct node *head, int data) {
    struct node *nw = getnode();
    nw->data = data;
    if(head == NULL)
        nw->next = NULL;
    else 
        nw->next = head;
    head = nw;
    return head;
}

struct node *insertRear(struct node *head, int data) {
    struct node *nw = getnode();
    nw->data = data;
    nw->next = NULL;
    if(head == NULL)
        head = nw;
    else {
        struct node *cur=head;
        for(; cur->next!=NULL; cur=cur->next);
        cur->next = nw;
    }
    return head;
}

struct node *insertPosition(struct node *head, int pos) {
    struct node *nw = getnode();
    int data;
    printf("Enter data : ");
    scanf("%d", &data);
    nw->data = data;
    if(head == NULL) {
        head = nw;
        nw->next = NULL;
    }
    else {
        struct node *cur=head;
        if(pos<1) {
            nw->next = head;
            head = nw;
        }
        else {
            for(int i=1; i<pos-1; i++, cur=cur->next);
            nw->next = cur->next;
            cur->next = nw;
        }
    }
    return head;
} 

struct node *deleteFront(struct node *head) {
    printf("Deleted data : %d\n", head->data);
    head = head->next;
    return head;
}

struct node *duplicate(struct node *head) {
    struct node *prev=NULL, *cur=head;
    if(cur==NULL)
        return head;
    if(cur->next!=NULL) {
        prev = cur;
        cur = cur->next;
        while(cur!=NULL) {
            if(prev->data == cur->data) {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
            else {
                prev = cur;
                cur = prev->next;
            }
        }   
    }
    return head;
}

int main()
{
    struct node *head=NULL;
    int ch, data;
    do {
        printf("0-Exit 1-Display 2-Search\n3-InsertFront 4-InsertRear 5-InsertAtAnyPosition\n6-DeleteFront 7-DeleteRear 8-DeleteAtAnyPosition 9-DeleteData : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 0: break;
            case 1: if(head == NULL)
                        printf("List is empty\n");
                    else 
                        display(head);
                    break;
            case 2: if(head == NULL)
                        printf("List is empty\n");
                    else {
                        printf("Enter element to find : ");
                        scanf("%d", &data);
                        int pos = search(head,data);
                        if(!pos)
                            printf("Element not found\n");
                        else
                            printf("Element is present in position %d\n",pos);
                    }
                    break;
            case 3: printf("Enter data : ");
                    scanf("%d", &data);
                    head = insertFront(head, data);
                    break;
            case 4: printf("Enter data : ");
                    scanf("%d", &data);
                    head = insertRear(head, data);
                    break;
            case 5: printf("Enter position : ");
                    scanf("%d", &data);
                    head = insertPosition(head, data);
                    break;
            case 6: if(head == NULL)
                        printf("List is empty\n");
                    else 
                        head = deleteFront(head);
                    break;
        }
    }while(ch!=0);
    return 0;
}