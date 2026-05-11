#include <stdio.h>
#include <stdlib.h>

#define MAX_n 100

// Function to add an edge to the graph
void addEdge(int graph[MAX_n][MAX_n], int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1; // For undirected graph
}

// Recursive function to perform DFS and check for cycles
int isCyclicUtil(int graph[MAX_n][MAX_n], int currentVertex, int parent, int visited[MAX_n]) {
    visited[currentVertex] = 1;

    for (int i = 0; i < MAX_n; i++) {
        if (graph[currentVertex][i]) {
            if (!visited[i]) {
                if (isCyclicUtil(graph, i, currentVertex, visited))
                    return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }

    return 0;
}

// Function to check whether a graph contains a cycle
int isCyclic(int graph[MAX_n][MAX_n], int n) {
    int visited[MAX_n] = {0};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(graph, i, -1, visited))
                return 1;
        }
    }

    return 0;
}

int main() {
    int n, m;
    scanf("%d", &n);

    if (n <= 0 || n > MAX_n) {
        printf("Invalid number of n. Exiting...\n");
        return 1;
    }

    int graph[MAX_n][MAX_n] = {0}; // Initialize the adjacency matrix with zeros

    // Input the number of m
    scanf("%d", &m);

    if (m < 0 || m > n * (n - 1) / 2) {
        printf("Invalid number of m. Exiting...\n");
        return 1;
    }

    // Input m and construct the adjacency matrix
    for (int i = 0; i < m; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        // Validate input n
        if (start < 0 || start >= n || end < 0 || end >= n) {
            printf("Invalid n. Try again.\n");
            i--;
            continue;
        }

        addEdge(graph, start, end);
    }

    if (isCyclic(graph, n))
        printf("TIDAK BISA\n");
    else
        printf("BISA\n");

    return 0;
}
