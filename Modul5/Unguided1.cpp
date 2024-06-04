#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
struct Mahasiswa
{
    string nim;
    int nilai;
};

class HashTable
{
private:
    unordered_map<string, Mahasiswa> data;

public:
    void tambahData(const string &nim, int nilai)
    {
        Mahasiswa mahasiswa;
        mahasiswa.nim = nim;
        mahasiswa.nilai = nilai;
        data[nim] = mahasiswa;
        cout << "Data berhasil ditambahkan.\n";
    }

    void hapusData(const string &nim)
    {
        if (data.erase(nim) == 1)
        {
            cout << "Data dengan NIM " << nim << " berhasil dihapus.\n";
        }
        else
        {
            cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
        }
    }

    void cariDataByNIM(const string &nim)
    {
        auto it = data.find(nim);
        if (it != data.end())
        {
            cout << "Data dengan NIM " << nim << " ditemukan:\n";
            cout << "NIM: " << it->second.nim << "\n";
            cout << "Nilai: " << it->second.nilai << "\n";
        }
        else
        {
            cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
        }
    }

    void cariDataByRentangNilai(int minNilai, int maxNilai)
    {
        bool found = false;
        cout << "Data dengan rentang nilai " << minNilai << " - " << maxNilai << ":\n";
        for (const auto &pair : data)
        {
            if (pair.second.nilai >= minNilai && pair.second.nilai <= maxNilai)
            {
                cout << "NIM: " << pair.second.nim << ", Nilai: " << pair.second.nilai << "\n";
                found = true;
            }
        }
        if (!found)
        {
            cout << "Data tidak ditemukan.\n";
        }
    }
};

int main()
{
    HashTable hashTable;
    int choice;
    string nim;
    int nilai;

    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Cari Data berdasarkan NIM\n";
        cout << "4. Cari Data berdasarkan Rentang Nilai (80-90)\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan Nilai: ";
            cin >> nilai;
            hashTable.tambahData(nim, nilai);
            break;
        case 2:
            cout << "Masukkan NIM: ";
            cin >> nim;
            hashTable.hapusData(nim);
            break;
        case 3:
            cout << "Masukkan NIM: ";
            cin >> nim;
            hashTable.cariDataByNIM(nim);
            break;
        case 4:
            hashTable.cariDataByRentangNilai(80, 90);
            break;
        case 5:
            cout << "Terima kasih. Program selesai.\n";
            return 0;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

        cout << endl;
    }

    return 0;
}
