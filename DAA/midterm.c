#include <stdio.h>
#include <stdlib.h>

struct adlist {
    int vertice;
    struct adlist* link;
};

struct stack {
    int vertice;
    struct stack* link;
};

struct stack* stack_create() {
    return (struct stack*)calloc(1, sizeof(struct stack));
}

void push(struct stack* stack, int vertice) {
    struct stack* new_node = stack_create();
    new_node->vertice = vertice;
    new_node->link = stack->link;
    stack->link = new_node;
}

int pop(struct stack* stack) {
    if (stack->link == NULL) return -1;
    int vertice = stack->link->vertice;
    stack->link = stack->link->link;
    return vertice;
}

void dfs(struct adlist** list, int vertices) {
    int* visited = (int*)calloc(vertices, sizeof(int));
    struct stack* stack = stack_create();
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) push(stack, i);
        while (stack->link) {
            int curr = pop(stack);
            if (!visited[curr]) {
                visited[curr] = 1;
                printf("%d ", curr);
            }
            for (struct adlist* x = list[curr]; x; x = x->link)
                if (!visited[x->vertice]) push(stack, x->vertice);
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    int v;
    scanf("%d", &v);
    struct adlist** list = (struct adlist**)malloc(v * sizeof(struct adlist*));
    for (int i = 0; i < v; ++i) {
        list[i] = (struct adlist*)calloc(1, sizeof(struct adlist));
        list[i]->vertice = i;
    }
    int a;
    do {
        printf("Enter 1 for edge, 2 to break: ");
        scanf("%d", &a);
        if (a == 1) {
            printf("Enter source and destination: ");
            int s, d;
            scanf("%d %d", &s, &d);
            struct adlist* ob = (struct adlist*)malloc(sizeof(struct adlist));
            ob->vertice = d;
            ob->link = list[s]->link;
            list[s]->link = ob;
        }
    } while (a != 2);
    dfs(list, v);
    return 0;
}
