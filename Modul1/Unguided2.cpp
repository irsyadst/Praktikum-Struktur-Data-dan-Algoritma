#include <iostream>
using namespace std;

class Mahasiswa
{
private:
    string nama;
    int umur;
    string jurusan;

public:
    void setNama(string nm)
    {
        nama = nm;
    }
    string getNama()
    {
        return nama;
    }
    void setUmur(int um)
    {
        umur = um;
    }
    int getUmur()
    {
        return umur;
    }
    void setJurusan(string jur)
    {
        jurusan = jur;
    }
    string getJurusan()
    {
        return jurusan;
    }
};

int main()
{
    Mahasiswa mhs1;
    mhs1.setNama("Muhammad Irsyad");
    mhs1.setUmur(20);
    mhs1.setJurusan("Teknik Informatika");

    cout << "Nama: " << mhs1.getNama() << endl;
    cout << "Umur: " << mhs1.getUmur() << endl;
    cout << "Jurusan: " << mhs1.getJurusan() << endl;

    return 0;
}
