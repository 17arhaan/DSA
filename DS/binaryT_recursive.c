#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *right, *left;
};
struct Node*root = NULL;

struct Node *Create(){
    struct Node *t;
    int a;
    printf("Value for Node : ");
    scanf("%d",&a);
    if (a == -1){
        return NULL;
    }
    else{
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = a;
        printf("Data for Left of %d Node : ",t->data);
        t->left = Create();
        printf("Data for Right of %d Node : ",t->data);
        t->right = Create();
        return t;
    }
}
void InOrder(struct Node *root){
    if(root != NULL){
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
}
void PreOrder(struct Node *root){
    if(root != NULL){
        printf("%d ",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void PostOrder(struct Node *root){
    if(root != NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ",root->data);
    }
}
void Print(struct Node *root){
    printf("\nInOrder Traversal ------> \n");
    InOrder(root);
    printf("\nPreOrder Traversal ------> \n");
    PreOrder(root);
    printf("\nPostOrder Traversal -------> \n");
    PostOrder(root);
}
int main(){
    printf("Root Node (Enter -1 for NULL)\n");
    parent = Create();
    Print(parent);
return 0;
}
