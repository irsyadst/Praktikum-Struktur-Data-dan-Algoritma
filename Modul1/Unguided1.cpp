#include <iostream>
using namespace std;

int tambah(int a, int b)
{
    return a + b;
}

float bagi(float a, float b)
{
    return a / b;
}

int main()
{
    int x = 5;
    int y = 10;
    float z = 3.5;

    cout << "Hasil penjumlahan " << x << " dan " << y << " adalah " << tambah(x, y) << endl;
    cout << "Hasil pembagian " << y << " dengan " << z << " adalah " << bagi(y, z) << endl;

    return 0;
}
