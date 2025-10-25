#include <stdio.h>

int main(){
    int V = 4;
    int adj[4][4] = {0};

    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;

    printf("Adjacency Matrix (Undirected):\n");
    printf("    A B C D\n");
    for (int i = 0; i < V; i++){
        printf("%c | ", 'A' + i);
        for (int j = 0; j < V; j++){
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
