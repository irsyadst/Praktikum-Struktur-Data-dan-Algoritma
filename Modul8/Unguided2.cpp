#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int hitungVokal(const string &sentence)
{
    int count = 0;

    for (char ch : sentence)
    {
        ch = tolower(ch);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string sentence;

    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    int jumlahVokal = hitungVokal(sentence);

    cout << "Jumlah huruf vokal dalam kalimat: " << jumlahVokal << endl;

    return 0;
}
