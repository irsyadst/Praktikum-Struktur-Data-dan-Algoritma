#include <iostream>
using namespace std;
#include <conio.h>
#include <iomanip>
int angka[7]={1, 8, 2, 5, 4, 9, 7};
int cari;
void selection_sort()
{
    int temp, min, i, j;
    for (i = 0; i < 7; i++)
    {
        min = i;
        for (j = i + 1; j < 7; j++)
        {
            if (angka[j] < angka[min])
            {
                min = j;
            }
        }
        temp = angka[i];
        angka[i] = angka[min];
        angka[min] = temp;
    }
}
void binarysearch()
{
    // searching
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 7;
    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (angka[tengah] == cari)
        {
            b_flag = 1;
            break;
        }
        else if (angka[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah - 1;
    }
    if (b_flag == 1)
        cout << "\n Data ditemukan pada index ke-" << tengah << endl;
    else
        cout << "\n Data tidak ditemukan\n";
}
int main()
{
    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";
    // tampilkan data awal
    for (int x = 0; x < 7; x++)
        cout << setw(3) << angka[x];
        cout << endl;
        cout << "\n Masukkan data yang ingin Anda cari : ";
        cin >> cari;
        cout << "\n Data diurutkan : ";
    // urutkan data dengan selection sort
    selection_sort();
    // tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++)
        cout << setw(3) << angka[x];
        cout << endl;
    binarysearch();
    _getche();
    return EXIT_SUCCESS;
}