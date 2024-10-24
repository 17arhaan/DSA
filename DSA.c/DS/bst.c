#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *right;
    struct Node *left;
} *root = NULL;
struct Node* Create(struct Node * parent, int a){
    if(parent == NULL){
        parent = (struct Node*) malloc(sizeof(struct Node));
        parent->data = a;
        return parent;
    }
    else{
        if(a < parent->data){
            parent->left = Create(parent->left, a);
        }
        else if(a > parent->data){
            parent->right = Create(parent->right, a);
        }
        else{
            printf("Duplicates are not Allowed \n");
        }
        return parent;
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
    int a;
    printf("Root Node (Input -1 to Exit)");
    while (a != -1){
        scanf("%d",&a);
        root = Create(root, a);
    }
    Print(root);
    return 0;
}