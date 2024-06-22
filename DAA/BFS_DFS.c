#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};
struct Graph {
    struct Node* adjList[80];
    bool visited[80];
    char vertexNames[80][20];
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    int i;
    for (i = 0; i < n; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = false;
        strcpy(graph->vertexNames[i], "");
    }
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}
void dfs(struct Graph* graph, int vertex) {
    struct Node* temp = graph->adjList[vertex];
    graph->visited[vertex] = true;
    printf("%s ", graph->vertexNames[vertex]);
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!graph->visited[adjVertex]) {
            dfs(graph, adjVertex);
        }
        temp = temp->next;
    }
}
void bfs(struct Graph* graph, int start) {
    struct Node* queue[80];
    int front = 0, rear = 0;
    queue[rear++] = createNode(start);
    graph->visited[start] = true;
    while (front < rear) {
        struct Node* currentNode = queue[front++];
        printf("%s ", graph->vertexNames[currentNode->data]);
        struct Node* temp = graph->adjList[currentNode->data];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!graph->visited[adjVertex]) {
                queue[rear++] = createNode(adjVertex);
                graph->visited[adjVertex] = true;
            }
            temp = temp->next;
        }
    }
}
void printAdjList(struct Graph* graph, int vertices) {
    int i;
    printf("\nAdjacency List:\n");
    for (i = 0; i < vertices; ++i) {
        printf("%s -> ", graph->vertexNames[i]);
        struct Node* temp = graph->adjList[i];
        while (temp != NULL) {
            printf("%s -> ", graph->vertexNames[temp->data]);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    struct Graph* graph = createGraph(80);
    int v1, v2, start_vertex, vertices = 0;
    char name[20];
    printf("Enter the Vertices----->\n");
    int vertex = 0;
    do {
        printf("Vertice Value : ");
        scanf("%d", &v1);
        if (v1 == -1)
            break;
        printf("Vertice Name : ");
        scanf("%s", name);
        strcpy(graph->vertexNames[v1], name);
        vertex++;
    } while (vertex < 80);
    printf("UnDirected Graph----->\n");
    while (true) {
        printf("Vertex 1 : ");
        scanf(" %d",&v1);
        printf("Vertex 2 : ");
        scanf(" %d",&v2);
        if (v1 == -1 || v2 == -1)
            break;
        addEdge(graph, v1, v2);
        vertices = (v1 > vertices) ? v1 : vertices;
        vertices = (v2 > vertices) ? v2 : vertices;
    }
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start_vertex);
    printf("Depth First Traversal: ");
    dfs(graph, start_vertex);
    for (int i = 0; i < 80; ++i) {
        graph->visited[i] = false;
    }
    printAdjList(graph, vertices + 1);
    printf("\nEnter the starting vertex for BFS: ");
    scanf("%d", &start_vertex);
    printf("Breadth First Traversal: ");
    bfs(graph, start_vertex);
    return 0;
}