#include <stdio.h>
#define MAX 10

void topologicalSort(int n, int graph[MAX][MAX])
{
    int count = 0, front = 0, rear = -1;
    int inDegree[MAX], result[MAX], queue[MAX];
    for (int i = 0; i < n; i++)
    {
        inDegree[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j]==1)
                inDegree[j]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            queue[++rear] = i;
        }
    }
    while (front <= rear)
    {
        int u = queue[front++];
        result[count++] = u;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && --inDegree[v] == 0)
            {
                queue[++rear] = v;
            }
        }
    }
    printf(" topo");
    for (int i = 0; i < n; i++)
    {
        printf("%d", result[i] + 1);
    }
}
int main()
{
    int n;
    int graph[MAX][MAX];
    printf(" vertices");
    scanf("%d", &n);
    printf(" enter matrixx");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    topologicalSort(n, graph);
    return 0;
}