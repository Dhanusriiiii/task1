#include <stdio.h>
#include <stdlib.h>

void writeFile() {
    FILE *fp;
    char data[100];

    fp = fopen("codtech.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter text to write to the file:\n");
    scanf(" %[^\n]", data);  // To read line with spaces
    fprintf(fp, "%s\n", data);
    fclose(fp);
    printf("Data written successfully.\n\n");
}

void readFile() {
    FILE *fp;
    char ch;

    fp = fopen("codtech.txt", "r");
    if (fp == NULL) {
        printf("File not found. Please write to file first.\n\n");
        return;
    }

    printf("Contents of the file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
    printf("\n");
}

void appendFile() {
    FILE *fp;
    char data[100];

    fp = fopen("codtech.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter text to append to the file:\n");
    scanf(" %[^\n]", data);
    fprintf(fp, "%s\n", data);
    fclose(fp);
    printf("Data appended successfully.\n\n");
}

int main() {
    int choice;

    while (1) {
        printf("=== File Handling Menu ===\n");
        printf("1. Write to File (Create/Overwrite)\n");
        printf("2. Read from File\n");
        printf("3. Append to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: writeFile(); break;
            case 2: readFile(); break;
            case 3: appendFile(); break;
            case 4: exit(0);
            default: printf("Invalid choice. Try again.\n\n");
        }
    }

    return 0;
}