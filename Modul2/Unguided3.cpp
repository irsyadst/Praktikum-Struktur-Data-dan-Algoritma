#include <iostream>
using namespace std;

int main()
{
    int n, max, min, lokmax, lokmin;
    double sum = 0, avg;

    cout << "Masukkan panjang array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan index array ke-" << i << ": ";
        cin >> arr[i];
    }

    max = arr[0];
    min = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            lokmax = i;
        }
        if (arr[i] < min)
        {
            min = arr[i];
            lokmin = i;
        }
        sum += arr[i];
    }

    avg = sum / n;

    cout << "Nilai Maksimum adalah " << max << " berada di index array ke-" << lokmax << endl;
    cout << "Nilai Minimum adalah " << min << " berada di index array ke-" << lokmin << endl;
    cout << "Nilai Rata-rata adalah " << avg << endl;

    return 0;
}
