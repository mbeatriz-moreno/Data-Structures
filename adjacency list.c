#include <stdio.h>
#include <stdlib.h>

#define V 4  

typedef struct Node{
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjList[], int src, int dest){
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

void printGraph(Node* adjList[]){
    printf("Adjacency List (Directed):\n");
    for (int i = 0; i < V; i++){
        printf("%c → ", 'A' + i);
        Node* temp = adjList[i];
        while (temp){
            printf("%c ", 'A' + temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    Node* adjList[V] = {NULL};

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);

    printGraph(adjList);

    for (int i = 0; i < V; i++){
        Node* temp = adjList[i];
        while (temp){
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    return 0;
}
