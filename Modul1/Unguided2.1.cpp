#include <iostream>
using namespace std;

struct Waktu
{
    int jam;
    int menit;
    int detik;
};

void printWaktu(Waktu w)
{
    cout << w.jam << ":" << w.menit << ":" << w.detik << endl;
}

int main()
{
    Waktu w1 = {10, 20, 30};
    printWaktu(w1);

    return 0;
}
