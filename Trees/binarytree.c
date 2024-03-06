#include <stdio.h>
#include <stdlib.h>
struct node 
{
    struct node *left, *right;
    int data;
};

struct node *getnode() {
    return malloc(sizeof(struct node));
}

struct node *insert(struct node *cur, struct node *nw) {
    if(!cur)
        return nw;
    if(nw->data < cur->data)
        cur->left = insert(cur->left,nw);
    else if(nw->data > cur->data)
        cur->right = insert(cur->right,nw);
    else{
        printf("Node already exists");
        free(nw);
    }
    return cur;
}

void inorder(struct node *cur) {
    if(!cur)
        return;
    inorder(cur->left);
    printf("%d ",cur->data);
    inorder(cur->right);
}

void preorder(struct node *cur) {
    if(!cur)
        return;
    printf("%d ",cur->data);
    inorder(cur->left);
    inorder(cur->right);
}

void postorder(struct node *cur) {
    if(!cur)
        return;
    inorder(cur->left);
    inorder(cur->right);
    printf("%d ",cur->data);
}

void displayLeaf(struct node *cur) {
    if(!cur)
        return;
    displayLeaf(cur->left);
    if(!cur->left && !cur->right)
        printf("%d ",cur->data);
    displayLeaf(cur->right);
}

void displayInternal(struct node *cur) {
    if(!cur)
        return;
    displayInternal(cur->left);
    if(!cur->left && !cur->right)
        return;
    else
        printf("%d ",cur->data);
    displayInternal(cur->right);
}

int main()
{
    struct node *root = NULL, *nw;
    int ch;

    do{
        printf("0-Exit 1-Insert 2-Inorder 3-Preorder 4-Postorder 5-DisplayLeaf 6-DisplayInternal => ");
        scanf("%d", &ch);
        switch(ch) {
            case 0: break;
            case 1: nw = getnode();
                    nw->left = nw->right = NULL;
                    scanf("%d", &nw->data);
                    root = insert(root, nw);
                    break;
            case 2: if(root == NULL)
                        printf("No elements in tree\n");
                    else {
                        inorder(root);
                        printf("\n");
                    }
                    break;
            case 3: if(root == NULL)
                        printf("No elements in tree\n");
                    else {
                        preorder(root);
                        printf("\n");
                    }
                    break;
            case 4: if(root == NULL)
                        printf("No elements in tree\n");
                    else {
                        postorder(root);
                        printf("\n");
                    }
                    break;
            case 5: if(root == NULL)
                        printf("No elements in tree\n");
                    else {
                        displayLeaf(root);
                        printf("\n");
                    }
                    break;
            case 6: if(root == NULL)
                        printf("No elements in tree\n");
                    else {
                        displayInternal(root);
                        printf("\n");
                    }
                    break;
        }
    }while(ch!=0);
    return 0;
}