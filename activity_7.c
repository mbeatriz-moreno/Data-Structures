#include <stdio.h>

void printSpiral(int m, int n, int matrix[m][n]){
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while(top<=bottom && left<=right){
        
        for(int i=left; i<=right; i++){ // izquierda - derecha
            printf("%d ", matrix[top][i]);
        }
        top++;

        
        for(int i=top; i<=bottom; i++){ // arriba - abajo
            printf("%d ", matrix[i][right]);
        }
        right--;

        
        if(top<=bottom){ // derecha - izquierda
            for(int i=right; i>=left; i--){
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        
        if(left<=right){ // abajo - arriba
            for(int i=bottom; i>=top; i--){
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
}

int main(){
    int matrix[5][4] = {
        {1,  2,  3,  4},
        {14, 15, 16, 5},
        {13, 20, 17, 6},
        {12, 19, 18, 7},
        {11, 10, 9,  8}
    };

    printf("Spiral order: ");
    printSpiral(5, 4, matrix);
    printf("\n");

    return 0;
}

/* To solve this activity four variables are used to control the matrix: 
top (first unvisited row), bottom (last unvisited row), left (first unvisited column), right (last unvisited column)

The algorithm follows four steps in a loop:
1. Traverse left to right across the top row.
2. Traverse top to bottom along the right column, then decrease right.
3. Traverse right to left across the bottom row.
4. Traverse bottom to top along the left column

And this process repeats until all elements are covered.
*/
