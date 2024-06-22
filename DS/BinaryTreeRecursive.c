#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};

struct Node* createNode(int data){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode ->data = data;
    newNode ->left = NULL;
    newNode ->right = NULL;
    return newNode;
}
struct Node* insertNode(struct Node*root , int data){
    if(root == NULL){
        return createNode(data);
    }
    else{
        if(data <= root -> data){
           root -> left = insertNode(root->left,data); 
        }
        else{
            root -> right = insertNode(root->right,data);
        }
        return root;
    }
}

void inOrderTraversal(struct Node*root){
    if(root!=NULL){
        inOrderTraversal(root->left);
        printf(" %d ",root ->data);
        inOrderTraversal(root ->right);
    }
}

void preOrderTraversal(struct Node*root){
    if(root != NULL){
        printf(" %d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node*root){
    if(root != NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf(" %d ",root->data);
    }
}

int main(){
    int data,numNodes;
    struct Node*root = NULL;

    printf("Enter the number of Nodes: ");
    scanf("%d",numNodes);

    printf("Enter the binary tree:-\n");
    for ( int i = 0 ; i < numNodes ; i++)
    {
        printf("Enter Node %d: ",i+1);
        scanf("%d",&data);
        root  = insertNode(root,data);
    }

    printf("\n");
    printf(" InOrder -------> \n");
    inOrderTraversal(root);
    printf("\n\n PreOrder -------> \n");
    preOrderTraversal(root);
    printf("\n\n PostOrder -------> \n");
    postOrderTraversal(root);
    return 0;
}