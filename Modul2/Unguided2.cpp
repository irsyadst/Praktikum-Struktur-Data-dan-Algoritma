#include <iostream>
using namespace std;

int main()
{
    int x, y, z;

    cout << "Masukkan jumlah index x: ";
    cin >> x;
    cout << "Masukkan jumlah index y: ";
    cin >> y;
    cout << "Masukkan jumlah index z: ";
    cin >> z;

    int arr[x][y][z];

    cout << "Masukkan array: " << endl;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "arr[" << i << "][" << j << "][" << k << "]= ";
                cin >> arr[i][j][k];
            }
        }
    }

    cout << "Elemen array: " << endl;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
