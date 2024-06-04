#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(string sentence)
{
    stack<char> charStack;
    int length = sentence.length();

    for (int i = 0; i < length; i++)
    {
        charStack.push(sentence[i]);
    }

    for (int i = 0; i < length; i++)
    {
        if (sentence[i] != charStack.top())
        {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main()
{
    string sentence;
    for (int i = 0; i < 5; i++)
    {
        cout << "Masukkan kalimat: ";
        getline(cin, sentence);

        if (isPalindrome(sentence))
        {
            cout << "Kalimat tersebut adalah palindrom" << endl;
        }
        else
        {
            cout << "Kalimat tersebut bukan palindrom" << endl;
        }
    }

    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    if (isPalindrome(sentence))
    {
        cout << "Kalimat tersebut adalah palindrom" << endl;
    }
    else
    {
        cout << "Kalimat tersebut bukan palindrom" << endl;
    }

    return 0;
}