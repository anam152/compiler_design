#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    int whitespaceCount = 0, newlineCount = 0;

    cout << "Enter text (Press Ctrl+D or Ctrl+Z to end input):\n";

    char ch;
    while (cin.get(ch))
    { // Reads input character by character
        if (ch == ' ')
        {
            whitespaceCount++;
        }
        else if (ch == '\n')
        {
            newlineCount++;
        }
    }

    cout << "Number of whitespaces: " << whitespaceCount << endl;
    cout << "Number of newlines: " << newlineCount << endl;

    return 0;
}
