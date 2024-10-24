#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next, *prev;
};
struct Node *first = NULL, *temp, *t;
void Add(int a)
{
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = a;
    temp->next = NULL;
    if (first == NULL)
    {
        first = temp;
        first->prev = NULL;
    }
    else
    {
        struct Node *ptr;
        ptr = first;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
}
int Remove()
{
    if (first->next == NULL)
    {
        int a = first->data;
        free(first);
        return a;
    }
    else
    {
        struct Node *ptr;
        ptr = first;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        int a = ptr->data;
        ptr = ptr->prev;
        ptr->next = NULL;
        return a;
    }
}
void Display()
{
    if (first == NULL)
    {
        printf("NULL");
    }
    else
    {
        t = first;
        while (t != NULL)
        {
            printf("|%d|->", t->data);
            t = t->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    printf("Menu\n");
    printf("1.Add()\n2.Remove()\n3.Display()\n4.Exit()\n");
    int a = 0;
    do
    {
        printf("Input Choice : ");
        scanf("%d", &a);
        if (a == 1)
        {
            int ele;
            printf("Element to Add : ");
            scanf("%d", &ele);
            Add(ele);
        }
        else if (a == 2)
        {
            int ele;
            ele = Remove();
            printf("%d removed fromn LL\n", ele);
        }
        else if (a == 3)
        {
            printf("LL --------->\n");
            Display();
        }
        else if (a == 4)
        {
            printf("!!!Exit!!!");
        }
        else
        {
            printf("Try Again");
        }
    } while (a != 4);
    return 0;
}