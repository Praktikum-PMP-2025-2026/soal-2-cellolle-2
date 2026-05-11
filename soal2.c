	/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : : 05 - Foundation of Algorithm
 *   Hari dan Tanggal    : Senin, 11 May 2026
 *   Nama (NIM)          : Marcello Menata Pandiangan (13224069)
 *   Nama File           : prak5_13224069.c
 *   Deskripsi           : Jadwal Misi Bertabrakan
 *  SUMBER https://www.w3resource.com/c-programming-exercises/graph/c-graph-exercises-6.php
 * 
 */


#include <stdio.h>
#include <stdlib.h>

#define total 100

void addEdge(int graph[total][total], int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1; 
}

int isCyclicUtil(int graph[total][total], int currentVertex, int parent, int visited[total]) {
    visited[currentVertex] = 1;

    for (int i = 0; i < total; i++) {
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

int isCyclic(int graph[total][total], int n) {
    int visited[total] = {0};

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
    int graph[total][total] = {0}; 
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        addEdge(graph, start, end);
    }

    if (isCyclic(graph, n))
        printf("TIDAK BISA\n");
    else
        printf("BISA\n");

    return 0;
}
