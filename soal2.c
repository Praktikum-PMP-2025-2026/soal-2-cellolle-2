	/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : : 05 - Foundation of Algorithm
 *   Hari dan Tanggal    : Senin, 11 May 2026
 *   Nama (NIM)          : Marcello Menata Pandiangan (13224069)
 *   Nama File           : prak5_13224069.c
 *   Deskripsi           : Jadwal Misi Bertabrakan
 *  SUMBER https://www.w3resource.com/c-programming-exercises/graph/c-graph-exercises-6.php
 *  SUMBER https://www.geeksforgeeks.org/c/graph-cycle-detection-in-c/
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_n 100

struct Graph {
    int totaln;
    int** matriks;
};

// Create a graph
struct Graph* createGraph(int n)
{
    struct Graph* graph= (struct Graph*)malloc(sizeof(struct Graph));
    graph->totaln = n;

    graph->matriks
        = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph->matriks[i]
            = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph->matriks[i][j] = 0;
        }
    }
    return graph;
}


void tambahm(struct Graph* graph, int src, int dest)
{
    graph->matriks[src][dest] = 1;
}

int DFS(struct Graph* graph, int vertex,
                      int* telahdikunjungi, int* stack)
{
    if (!telahdikunjungi[vertex]) {
        telahdikunjungi[vertex] = 1;
        stack[vertex] = 1;

        for (int v = 0; v < graph->totaln; v++) {
            if (graph->matriks[vertex][v]) {
                if (!telahdikunjungi[v]
                    && DFS(graph, v, telahdikunjungi,
                                         stack)) {
                    return 1;
                }
                else if (stack[v]) {
                    return 1;
                }
            }
        }
    }
    stack[vertex]= 0; 
    return 0;
}

int Cek(struct Graph* graph)
{
    int* telahdikunjungi
        = (int*)malloc(graph->totaln * sizeof(int));
    int* stack
        = (int*)malloc(graph->totaln * sizeof(int));

    for (int i = 0; i < graph->totaln; i++) {
        telahdikunjungi[i] = 0;
        stack[i] = 0;
    }

    for (int i = 0; i < graph->totaln; i++) {
        if (DFS(graph, i, telahdikunjungi,stack)) {
             return 1;
        }
    }
    return 0;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    struct Graph* graph = createGraph(n);
    for (int i = 0; i < m; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        tambahm:(graph, start, end);
    }
    if (Cek(graph)) {
        printf("TIDAK BISA\n");
    }
    else {
        printf("BISA\n");
    }
    return 0;
}
