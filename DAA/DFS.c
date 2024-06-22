#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Graph {
    int vertices;
    int adjacencyMatrix[MAX_SIZE][MAX_SIZE];
};

void initializeGraph(struct Graph *graph, int vertices) {
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph *graph, char src, char dest) {
    graph->adjacencyMatrix[src - 'A'][dest - 'A'] = 1;
    graph->adjacencyMatrix[dest - 'A'][src - 'A'] = 1;
}

void DFS(struct Graph *graph, bool visited[], int vertex) {
    printf("%c ", vertex + 'A');

    visited[vertex] = true;

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(graph, visited, i);
        }
    }
}

int main() {
    int vertices, edges;
    char src, dest;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph graph;
    initializeGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination): \n");
    for (int i = 0; i < edges; i++) {
        scanf(" %c %c", &src, &dest);
        addEdge(&graph, src - 'A', dest - 'A');
    }

    bool visited[MAX_SIZE] = {false};

    printf("Enter the source for DFS traversal: ");
    scanf(" %c", &src);

    printf("DFS traversal from %c: ", src);
    DFS(&graph, visited, src - 'A');

    return 0;
}
