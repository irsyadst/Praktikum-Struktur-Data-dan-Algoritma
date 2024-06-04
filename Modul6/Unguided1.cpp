#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseString(string input)
{
    stack<char> charStack;
    string reversedString;
    for (char c : input)
    {
        charStack.push(c);
    }
    while (!charStack.empty())
    {
        reversedString += charStack.top();
        charStack.pop();
    }

    return reversedString;
}

int main()
{
    string input;
    for (int i = 0; i < 5; i++)
    {
    cout << "Masukkan string: ";
    getline(cin, input);

    string reversed = reverseString(input);

    cout << "String terbalik: " << reversed << endl;
    }

    return 0;
}
