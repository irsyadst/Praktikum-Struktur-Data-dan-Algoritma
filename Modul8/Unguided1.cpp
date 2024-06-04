#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int binarySearch(const string &sentence, char target)
{
    int left = 0;
    int right = sentence.length() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (sentence[mid] == target)
        {
            return mid;
        }

        if (sentence[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    string sentence;
    char target;

    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;
    target = tolower(target);

    int index = binarySearch(sentence, target);

    if (index != -1)
    {
        cout << "Huruf '" << target << "' ditemukan pada indeks ke-" << index << endl;
    }
    else
    {
        cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;
    }
    return 0;
}
