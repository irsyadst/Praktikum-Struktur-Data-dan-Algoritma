#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Masukkan panjang array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan index array ke-" << i << ": ";
        cin >> arr[i];
    }
    cout << "Data Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << "Nomor Genap : ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            cout << arr[i] << ", ";
        }
    }
    cout << endl << "Nomor Ganjil : ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            cout << arr[i] << ", ";
        }
    }
}