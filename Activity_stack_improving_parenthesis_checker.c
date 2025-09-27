#include <stdio.h>
#include <string.h>

#define MAX 200000

typedef struct{
    char bracket;
    int index;
} StackItem;

int main(void){
    FILE *file;
    char line[MAX];

    file = fopen("texto.txt", "r");
    if (file == NULL){
        printf("No se pudo abrir el archivo texto.txt\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)){
        size_t length = strlen(line);
        if (length > 0 && line[length - 1] == '\n') {
            line[length - 1] = '\0';
            length--;
        }

        StackItem stack[MAX];
        int topIndex = -1;
        int errorIndex = -1;

        for (int i = 0; i < (int)length; i++){
            char current = line[i];

            if (current == '(' || current == '[' || current == '{'){
                ++topIndex;
                stack[topIndex].bracket = current;
                stack[topIndex].index = i;
            }else if (current == ')' || current == ']' || current == '}'){
                if (topIndex == -1) {
                    errorIndex = i;
                    break;
                }
                char expected = (current == ')') ? '(' : (current == ']') ? '[' : '{';
                if (stack[topIndex].bracket != expected){
                    errorIndex = i;
                    break;
                }
                --topIndex;
            }
        }

        if (errorIndex != -1){
            printf("ERROR %d\n", errorIndex);
        } else if (topIndex != -1) {
            printf("ERROR %d\n", stack[0].index);
        } else{
            printf("OK\n");
        }
    }

    fclose(file);
    return 0;
}
