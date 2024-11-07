#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};
struct Stack{
    struct Node *data;
    struct Stack *next;
};
struct Node *parent = NULL;
struct Node *newNode(int a){
    struct Node *new;
    new = (struct Node *) malloc(sizeof(struct Node));
    new->data = a;
    new->right = NULL;
    new->left = NULL;
    return new;
}
void push (struct Stack **top, struct Node *n)
{
  struct Stack *new_n = (struct Stack *) malloc (sizeof (struct Stack));
  new_n->data = n;
  new_n->next = (*top);
  (*top) = new_n;
}
int isEmpty (struct Stack *top)
{
  if (top == NULL)
    return 1;
  else
    return 0;
}
struct Node *pop (struct Stack **top_n)
{
  struct Node *item;
  struct Stack *top;
  top = *top_n;
  item = top->data;
  *top_n = top->next;
  free (top);
  return item;
}
void Create(struct Node *root, int a){
    struct Node *temp = root;
    printf("Place Node %d\n",a);
    while(1){
        char ch;
        printf("Left or Right of Node %d (L/R) : ",temp->data);
        scanf(" %c",&ch);
        if(ch == 'l' || ch == 'L'){
            if(temp->left == NULL){
                temp->left = newNode(a);
                break;
            }
            else{
                temp = temp->left;
            }
        }
        else if(ch == 'r' || ch == 'R'){
            if (temp->right == NULL) {
                temp->right = newNode(a);
                break;
            } 
            else {
                temp = temp->right;
            }
        }
        else{
            printf("Try Again\n");
        }
    }
}
void InOrder(struct Node *root){
    struct Node *temp;
    temp = root;
    struct Stack *s1 = NULL;
    while(1){
        if(temp != NULL){
            push(&s1,temp);
            temp = temp->left;
        }
        else{
            if(isEmpty(s1) == 0){
                temp = pop(&s1);
                printf("%d ",temp->data);
                temp = temp->right;
            }
            else{
                break;
            }
        }
    }
}
void PreOrder(struct Node *root){
    struct Node *temp;
    temp = root;
    struct Stack *s1 = NULL;
    while(1){
        if(temp != NULL){
            printf("%d ",temp->data);
            push(&s1, temp);
            temp = temp->left;
        }
        else{
            if(isEmpty(s1) == 0){
                temp = pop(&s1);
                temp = temp->right;
            }
            else{
                break;
            }
        }
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
    int ch;
    do{
        printf("Enter Data for Node (-1 to Exit) : ");
        scanf("%d",&ch);
        if(ch == -1){
            Print(parent);
        }
        else{
            if(parent == NULL){
                printf("\nValue of Root Node : %d\n",ch);
                parent = newNode(ch);
            }
            else{
                Create(parent, ch);
            }
        }
    }while(ch != -1);
    return 0;
}