#include <stdio.h>
#include <string.h>
#include <ctype.h>

void categorize_code(const char* code) {
    // Delimiters
    char delimiters[] = " ,;(){}[]\""; // Basic delimiters used in C

    // Declare variables outside the loop
    int length = strlen(code);
    int i = 0;

    // Loop through the input code and categorize
    printf("\nCategorizing your code:\n");

    // Loop through each character in the code
    while (i < length) {
        // Check for delimiters
        if (strchr(delimiters, code[i])) {
            printf("Delimiter: '%c'\n", code[i]);
            i++;  // Move to the next character
        }
        // Check for constants (numbers)
        else if (isdigit(code[i])) {
            printf("Constant: ");
            while (isdigit(code[i])) {
                putchar(code[i]);
                i++;  // Move to the next character
            }
            printf("\n");
        }
        // Check for variables (identifiers)
        else if (isalpha(code[i]) || code[i] == '_') {
            printf("Variable: ");
            while (isalnum(code[i]) || code[i] == '_') {
                putchar(code[i]);
                i++;  // Move to the next character
            }
            printf("\n");
        }
        // Check for operators (basic operators for this example)
        else if (code[i] == '+' || code[i] == '-' || code[i] == '*' || code[i] == '/' ||
                 code[i] == '=' || code[i] == '>' || code[i] == '<') {
            printf("Operator: '%c'\n", code[i]);
            i++;  // Move to the next character
        } else {
            i++;  // Skip unknown characters
        }
    }
}

int main() {
    char code[256];

    // Take the entire line of code as input from the user
    printf("Enter a line of code: ");
    fgets(code, sizeof(code), stdin); // Use fgets to allow spaces in input

    // Remove the newline character at the end of the input string
    code[strcspn(code, "\n")] = 0;

    // Categorize the code
    categorize_code(code);

    return 0;
}

