#include <stdio.h>

#define MAX_NODES 10

int n, i, j, visited[MAX_NODES], adj[MAX_NODES][MAX_NODES];

void dfs(int v)
{
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 1; i <= n; i++)
    {
        if (adj[v][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    printf("Enter graph data in matrix form:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    printf("DFS Traversal: ");
    dfs(v);

    for (i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            printf("\nDFS is not possible. Not all nodes are reachable\n");
            return 0;
        }
    }

    printf("\nVertex Connection:\n");
    for (i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            printf("%d is connected to: ", i);
            for (j = 1; j <= n; j++)
            {
                if (adj[i][j] && visited[j])
                {
                    printf("%d ", j);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
