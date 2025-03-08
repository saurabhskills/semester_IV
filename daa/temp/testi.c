#include <stdio.h>
#include <stdlib.h>

int graph[100][100];
int visited[100];
int queue[100], front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == 99) {
        printf("Queue is full\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;
    } else {
        vertex = queue[front++];
        return vertex;
    }
}

void BFS(int start, int n) {
    int i, vertex;
    enqueue(start);
    visited[start] = 1;
    while (front <= rear) {
        vertex = dequeue();
        printf("%d ", vertex);
        for (i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void DFS(int start, int n) {
    printf("%d ", start);
    visited[start] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}

int main() {
    int n;
    printf("Enter the size of Adjacency Matrix: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter for vertex no. %d:\n", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("DFS traversal starting from vertex 0:\n");
    DFS(0, n);

    // Reset visited array for BFS
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("\nBFS traversal starting from vertex 0:\n");
    BFS(0, n);

    return 0;
}
