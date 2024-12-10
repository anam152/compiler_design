#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_KEYWORDS 32

// Array of C language keywords
const char *keywords[NUM_KEYWORDS] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", 
    "double", "else", "enum", "extern", "float", "for", "goto", "if", 
    "inline", "int", "long", "register", "return", "short", "signed", "sizeof", 
    "static", "struct", "switch", "typedef", "union", "unsigned", "void", 
    "volatile", "while"
};

// Function to check if the word is a keyword
int i;
bool isKeyword(const char *word) {
    for (i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return true;  // Word matches a keyword
        }
    }
    return false;  // Word is not a keyword
}

int main() {
	while (true){
	
    char word[50];

	printf("			===   Program to check Keywords ===\n\n");

    
    printf("Enter a word: ");
    scanf("%s", word);

   
    if (isKeyword(word)) {
        printf("-> \"%s\" is a  keyword.\n", word);
    } else {
        printf("-> \"%s\" is not a keyword\n", word);
    }
}
    return 0;
}

