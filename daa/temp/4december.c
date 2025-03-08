/*
    DATE: 04/12/24
    Write a C/C++ program to implement:
        1. DFS
        2. BFS
*/
#include <stdio.h>
int graph[100][100];
int visited[100];

void BFS() {

};
void DFS(int start, int n)
{
    printf("%d ", start);
    visited[start] = 1;
    for (int i = 0; i < n; i++)
    {
        if (graph[start][i] == 1 && !visited[i])
        {
            DFS(i, n);
        }
    }
};
int main()
{
    int n;
    printf("Enter the size of Adjacency Matrix: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter for vertex no. %d:\n", i);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    DFS(0, n);

    return 0;
}
