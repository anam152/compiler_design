#include <stdio.h>

int main() {
    char ch;  
    int lineCount = 0, tabCount = 0, spaceCount = 0;

    printf("Enter text :\n");

    // Read character by character from standard input
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            lineCount++;  
        } else if (ch == '\t') {
            tabCount++;  
        } else if (ch == ' ') {
            spaceCount++; 
        }
    }

    // Display the results
    printf("Number of lines: %d\n", lineCount);
    printf("Number of tabs: %d\n", tabCount);
    printf("Number of spaces: %d\n", spaceCount);

    return 0;
}

