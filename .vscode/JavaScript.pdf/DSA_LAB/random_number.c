#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void generateDataFile(int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    srand(time(0));
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", rand() % MAX);  // random numbers between 0 and 99
    }
    fclose(file);
}

int main() {
    int n = 100; // Number of random numbers to generate
    generateDataFile(n, "data.txt");
    printf("Data file generated successfully.\n");
    return 0;
}
