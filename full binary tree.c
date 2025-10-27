#include <stdio.h>

#define MAX_ELEMENTS 20

typedef struct{
    char nodes[MAX_ELEMENTS];
    int numElements;
} Tree;

int main(){
    Tree tree;

    tree.nodes[0] = 'G';
    tree.nodes[1] = 'D';
    tree.nodes[2] = 'I';
    tree.nodes[3] = 'B';
    tree.nodes[4] = 'F';
    tree.nodes[5] = 'H';
    tree.nodes[6] = 'J';
    tree.nodes[7] = 'A';
    tree.nodes[8] = 'C';
    tree.nodes[9] = 'K';
    tree.nodes[10] = 'E';

    tree.numElements = 11;

    printf("Árbol binario completo representado en arreglo:\n");
    for (int i = 0; i < tree.numElements; i++){
        printf("[%d] = %c\n", i, tree.nodes[i]);
    }

    return 0;
}
