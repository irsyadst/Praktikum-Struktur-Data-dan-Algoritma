#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari = 4;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            count++;
        }
    }

    cout << "\t Program Sequential Search Sederhana\n " << endl;
    cout << " data: {9, 4, 1, 4, 7, 10, 5, 4, 12, 4} " << endl;
    cout << "\n angka " << cari << " muncul sebanyak " << count << " kali dalam data." << endl;

    return 0;
}
