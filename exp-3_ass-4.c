#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

char **foo(const char *filename, int *numStrings) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return NULL;
    }

    char **stringArray = (char **)malloc(MAX_WORDS * sizeof(char *));
    if (stringArray == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return NULL;
    }

    char buffer[256]; // Assuming a maximum line length of 255 characters

    int count = 0;
    while (count < MAX_WORDS && fgets(buffer, sizeof(buffer), file) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // Remove the newline character
            len--; // Update the length
        }

        stringArray[count] = (char *)malloc((len + 1) * sizeof(char));
        if (stringArray[count] == NULL) {
            printf("Memory allocation failed.\n");
            fclose(file);
            for (int i = 0; i < count; i++) {
                free(stringArray[i]);
            }
            free(stringArray);
            return NULL;
        }

        strcpy(stringArray[count], buffer);
        count++;
    }

    fclose(file);
    *numStrings = count;
    return stringArray;
}

int main() {
    int numStrings;
    char **stringArray = foo("input.txt", &numStrings);

    if (stringArray != NULL) {
        printf("Read %d strings from the file:\n", numStrings);
        for (int i = 0; i < numStrings; i++) {
            printf("%s\n", stringArray[i]);
            free(stringArray[i]);
        }
        free(stringArray);
    }

    return 0;
}
