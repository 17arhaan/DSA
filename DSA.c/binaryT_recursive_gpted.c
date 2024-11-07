#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int data, numNodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the elements for the binary tree:\n");
    for (int i = 0; i < numNodes; ++i) {
        printf("Node %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("\nInOrder Traversal ------> \n");
    inOrderTraversal(root);
    printf("\n\nPreOrder Traversal ------> \n");
    preOrderTraversal(root);
    printf("\n\nPostOrder Traversal -------> \n");
    postOrderTraversal(root);
    printf("\n");
    return 0;
}