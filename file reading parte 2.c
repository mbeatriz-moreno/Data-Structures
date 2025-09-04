#include <stdio.h>
#include <stdlib.h>

float totalSale(float sales[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += sales[i];
    }
    return sum;
}

float maxSale(float sales[], int count) {
    float max = sales[0];
    for (int i = 1; i < count; i++) {
        if (sales[i] > max) {
            max = sales[i];
        }
    }
    return max;
}

int main() {
    FILE *fptr;
    char filename[] = "sales.txt";
    char line[100];
    int count = 0;

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fptr) != NULL) {
        count++;
    }

    printf("The file contains %d lines\n", count);

    rewind(fptr);

    float *sales = (float *)malloc(sizeof(float) * count);
    if (sales == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fptr);
        return 1;
    }

    for (int i = 0; i < count; i++) {
        if (fgets(line, sizeof(line), fptr) != NULL) {
            sales[i] = strtof(line, NULL);
        } else {
            sales[i] = 0.0;
        }
    }

    printf("Sales data:\n");
    for (int i = 0; i < count; i++) {
        printf("%.2f\n", sales[i]);
    }

    float total = totalSale(sales, count);
    float max = maxSale(sales, count);

    printf("Total sales: %.2f\n", total);
    printf("Max sale: %.2f\n", max);

    free(sales);
    fclose(fptr);

    return 0;
}
