#include <stdio.h>
#include <string.h>
int main()
{
    char keyword[32][10] = {
        "auto", "double", "int", "struct", "break", "else", "long",
        "switch", "case", "enum", "register", "typedef", "char",
        "extern", "return", "union", "const", "float", "short",
        "unsigned", "continue", "for", "signed", "void", "default",
        "goto", "sizeof", "voltile", "do", "if", "static", "while"};
    char str[50];
    printf("Enter any string : ");
    scanf("%c", str);
    int flag = 0, i;
    for (i = 0; i < 32; i++)
    {
        if (strcmp(str, keyword[i]) == 0)
        {
            flag = 1;
        }
    }
    if (flag == 1)
        printf("It is a keyword");
    else
        printf("It is not a keyword");
}