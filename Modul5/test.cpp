#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int TABLE_SIZE = 11;
int NIM;
int nilai;
class HashNode
{
public:
    int NIM;
    int nilai;
    HashNode(int NIM, int nilai)
    {
        this->NIM = NIM;
        this->nilai = nilai;
    }
};
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(long key)
    {
        return key % TABLE_SIZE;
    }
    void insert(int NIM, int nilai)
    {
        int hash_val = hashFunc(NIM);
        for (auto node : table[hash_val])
        {
            if (node->NIM == NIM)
            {
                node->nilai = nilai;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(NIM, nilai));
    }
    void remove(int NIM)
    {
        int hash_val = hashFunc(NIM);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->NIM == NIM)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    void searchByNIM(int NIM)
    {
        int hash_val = hashFunc(NIM);
        for (auto node : table[hash_val])
        {
            if (node->NIM == NIM)
            {
                cout << "Data dengan NIM " << NIM << " ditemukan:\n";
                cout << "NIM: " << node->NIM << "\n";
                cout << "Nilai: " << node->nilai << "\n";
            }
            else
            {
                cout << "Data dengan NIM " << NIM << " tidak ditemukan.\n";
            }
        }
    }
    void cariDataByRentangNilai(int minNilai, int maxNilai)
    {
        cout << "Data dengan rentang nilai " << minNilai << " - " << maxNilai << ":\n";
        for (auto pair : table)
        {
            for (auto node : pair)
            {
                if (node->nilai >= minNilai && node->nilai <= maxNilai)
                {
                    cout << "NIM: " << node->NIM << ", Nilai: " << node->nilai << "\n";
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->NIM << ", " << pair->nilai << "]";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    HashMap employee_map;
    int choice;
    int NIM;
    int nilai, minNilai, maxNilai;

    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Cari Data berdasarkan NIM\n";
        cout << "4. Cari Data berdasarkan Rentang Nilai (80-90)\n";
        cout << "5. Tampilkan Data\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan NIM: ";
            cin >> NIM;
            cout << "Masukkan Nilai: ";
            cin >> nilai;
            employee_map.insert(NIM, nilai);
            break;
        case 2:
            cout << "Masukkan NIM: ";
            cin >> NIM;
            employee_map.remove(NIM);
            cout << "Data telah dihapus!" << endl;
            break;
        case 3:
            cout << "Masukkan NIM: ";
            cin >> NIM;
            employee_map.searchByNIM(NIM);
            break;
        case 4:
            employee_map.cariDataByRentangNilai(80, 90);
            break;
        case 5:
            employee_map.print();
            break;
        case 6:
            cout << "Terima kasih. Program selesai.\n";
            return 0;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
        cout << endl;
    }
}