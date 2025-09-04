#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char filename[] = "sales.txt";

    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("ERROR IN FILE CREATION\n");
        exit(-1);
    }

    fprintf(fptr, "120.50\n450.75\n89.00\n230.40\n");
    fclose(fptr);

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("ERROR OPENING FILE FOR READING\n");
        exit(-1);
    }

    int lineCount = 0;
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        lineCount++;
    }

    printf("The file has %d lines\n", lineCount);

    float *sales = (float *)malloc(sizeof(float) * lineCount);
    if (sales == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fptr);
        return 1;
    }

    rewind(fptr);
    int i = 0;
    while (fgets(buffer, sizeof(buffer), fptr) != NULL && i < lineCount) {
        sales[i] = strtof(buffer, NULL);
        i++;
    }

    printf("Sales values:\n");
    for (i = 0; i < lineCount; i++) {
        printf("%.2f\n", sales[i]);
    }

    free(sales);
    fclose(fptr);

    return 0;
}
