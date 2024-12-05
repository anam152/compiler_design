#include <stdio.h>

int main() {
    char ch;
    int spaces = 0, tabs = 0, newlines = 0;

    printf("Enter a paragraph (Ctrl+Z to finish, press enter again to see results) :\n");

    // Read characters until EOF (Ctrl+D on Unix/Mac, Ctrl+Z on Windows)
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            spaces++;
        } else if (ch == '\t') {
            tabs++;
        } else if (ch == '\n') {
            newlines++;
        }
    }

    printf("Spaces: %d\n", spaces);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);

    return 0;
}
