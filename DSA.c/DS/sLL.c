#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *first = NULL, *temp, *t;
void AddB(int a)
{
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = a;
    temp->next = NULL;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        temp->next = first;
        first = temp;
    }
}
void AddE(int a)
{
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = a;
    temp->next = NULL;
    struct Node *ptr;
    ptr = first;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}
int RemoveB()
{
    struct Node *ptr;
    ptr = first;
    int s;
    s = ptr->data;
    first = first->next;
    free(ptr);
    return s;
}
int RemoveE()
{
    struct Node *ptr, *pt;
    ptr = first->next;
    pt = first;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        pt = pt->next;
    }
    pt->next = NULL;
    int s;
    s = ptr->data;
    free(ptr);
    return s;
}
void Display()
{
    if (first == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        t = first;
        while (t != NULL)
        {
            printf("|%d|----->", t->data);
            t = t->next;
        }
        printf("NULL\n");
    }
}

void Reverse(){
    t = head;
    temp = NULL;
    while(t != NULL){
        temp = t->prev;
        t->prev = t->next;
        t->next = temp;
        t = t->prev;
    }
    head = temp->prev;
}


int main(){
    int ch;
    int ele;
    printf("-------MENU------");
    printf("\n1.AddF()\n2.AddR()\n3.RemoveF()\n4.RemoveE()\n5.Display()\n6.Exit");   
     do
    {
        printf("Input Choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            int ele;
            printf("Element to Add : ");
            scanf("%d", &ele);
            AddB(ele);
        }
        else if (ch == 2)
        {
            int ele;
            printf("Element to Add : ");
            scanf("%d", &ele);
            AddE(ele);
        }
        else if (ch == 3)
        {
            int ele;
            ele = RemoveB();
        }
        else if (ch == 4)
        {
            int ele;
            ele = RemoveE();
        }
        else if (ch == 5)
        {
            printf("List is : ");
            Display();
        }
        else if (ch == 6)
        {
            printf("Exit\n");
        }
        else
        {
            printf("Try Again\n");
        }
    } while (ch != 6);
    return 0;
}

