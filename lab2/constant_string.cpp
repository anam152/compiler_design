#include <iostream>
#include <string>

using namespace std;

bool isConstant(const string &str, const string &predefinedConstant)
{
    return str == predefinedConstant;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    // Example constant for comparison
    const string constantValue = "hello"; //

    if (isConstant(input, constantValue))
    {
        cout << "The string is a constant: \"" << constantValue << "\".\n";
    }
    else
    {
        cout << "The string is not the predefined constant.\n";
    }

    return 0;
}
