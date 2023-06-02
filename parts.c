#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//softwareNuggets

struct Part {
    int id;
    char partno[24];
    float cost;
};

void writeToFile(struct Part parts[], int numParts) 
{
    FILE *file = fopen("C:\\MinGW\\parts.bin", "wb");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    for (int i = 0; i < numParts; i++) {
        fwrite(&parts[i], sizeof(struct Part), 1, file);
    }

    fclose(file);
}

void readFromFile() 
{
    FILE *file = fopen("C:\\MinGW\\parts.bin", "rb");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    struct Part part;
    int numParts = 0;

    while (fread(&part, sizeof(struct Part), 1, file) == 1) {
        printf("Record %d:\n", numParts + 1);
        printf("ID: %d\n", part.id);
        printf("Part Number: %s\n", part.partno);
        printf("Cost: %.2f\n", part.cost);
        printf("---------------------\n");
        numParts++;
    }

    fclose(file);

    printf("Total records read: %d\n", numParts);
}

int main() 
{
    struct Part parts[3]; 
    int numParts = 0;

    parts[0].id = 1;
    strcpy(parts[0].partno, "Part 1");
    parts[0].cost = 10.99;

    parts[1].id = 2;
    strcpy(parts[1].partno, "Part 2");
    parts[1].cost = 20.49;

    parts[2].id = 3;
    strcpy(parts[2].partno, "Part 3");
    parts[2].cost = 5.99;

    numParts=3;

    // Write the array to file
    writeToFile(parts, numParts);

    // Read from the file and display the records
    readFromFile();

    return 0;
}
    
