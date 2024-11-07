#include <stdio.h>
#define MAX_SIZE 100
struct CQ
{
    int a;
    char arr[MAX_SIZE];
    int front;
    int rear;
};
void Initialise(struct CQ *s)
{
    s->front = -1;
    s->rear = -1;
}
void InsertCQ(struct CQ *s, char ad)
{
    if (s->rear == -1)
    {
        s->front++;
        s->arr[++s->rear] = ad;
    }
    else if ((s->rear + s->front) == s->a)
    {
        printf("Queue is Full\n");
    }
    else
    {
        s->rear++;
        s->arr[s->rear] = ad;
    }
}
void DeleteCQ(struct CQ *s)
{
    if (s->rear >= s->front)
    {
        printf("%c removed from front\n", s->arr[s->front]);
        s->front++;
    }
    else
    {
        printf("Nothing in Queue\n");
    }
}
void Display(struct CQ *s)
{
    for (int i = s->front; i <= s->rear; i++)
    {
        printf("|%c|", s->arr[i]);
    }
}
int main()
{
    int ch, l;
    struct CQ s;
    printf("Number of Elements: ");
    scanf("%d", &l);
    s.a = l - 1;
    Initialise(&s);
    printf("Menu\n");
    printf("1.Insert()\n");
    printf("2.Delete()\n");
    printf("3.Display()\n");
    printf("4.Exit\n");
    do
    {
        printf("Input Choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            char a;
            printf("Element to InsertCQ : ");
            scanf(" %c", &a);
            InsertCQ(&s, a);
        }
        else if (ch == 2)
        {
            DeleteCQ(&s);
        }
        else if (ch == 3)
        {
            printf("Queue is : ");
            Display(&s);
            printf("\n");
        }
        else if (ch == 4)
        {
            printf("\n!!!Exit!!!");
        }
        else
        {
            printf("Not a Valid Option\n");
        }

    } while (ch != 4);
    return 0;
}