#include <iostream>
#include <string>

using namespace std;

class Skincare
{
public:
    string namaProduk;
    int harga;
    Skincare *prev;
    Skincare *next;

    // Constructor
    Skincare(string _namaProduk, int _harga)
    {
        namaProduk = _namaProduk;
        harga = _harga;
        prev = nullptr;
        next = nullptr;
    }
};

class TokoSkincare
{
private:
    Skincare *head;

public:
    // Constructor
    TokoSkincare()
    {
        head = nullptr;
    }

    // Destructor
    ~TokoSkincare()
    {
        // Hapus semua node pada double linked list saat objek dihapus
        Skincare *current = head;
        while (current != nullptr)
        {
            Skincare *next = current->next;
            delete current;
            current = next;
        }
    }

    // Menambahkan data pada akhir double linked list
    void tambahData(string namaProduk, int harga)
    {
        Skincare *newSkincare = new Skincare(namaProduk, harga);

        if (head == nullptr)
        {
            head = newSkincare;
        }
        else
        {
            Skincare *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newSkincare;
            newSkincare->prev = current;
        }

        cout << "Data berhasil ditambahkan." << endl;
    }

    // Menghapus data dari double linked list
    void hapusData(string namaProduk)
    {
        if (head == nullptr)
        {
            cout << "Data kosong." << endl;
            return;
        }

        Skincare *current = head;
        while (current != nullptr && current->namaProduk != namaProduk)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Data tidak ditemukan." << endl;
        }
        else
        {
            if (current->prev != nullptr)
            {
                current->prev->next = current->next;
            }
            else
            {
                head = current->next;
            }

            if (current->next != nullptr)
            {
                current->next->prev = current->prev;
            }

            delete current;
            cout << "Data berhasil dihapus." << endl;
        }
    }

    // Mengupdate data dalam double linked list
    void updateData(string namaLama)
    {
        if (head == NULL)
        {
            cout << "Linked list kosong!" << endl;
        }
        else
        {
            Skincare *current = head;
            while (current != NULL && current->namaProduk != namaLama)
            {
                current = current->next;
            }
            if (current == NULL)
            {
                cout << "Data tidak ditemukan!" << endl;
            }
            else
            {
                string namaBaru;
                int harga;

                cout << "Masukkan nama baru: ";
                cin >> namaBaru;
                current->namaProduk = namaBaru;
                cout << "Masukkan harga baru: ";
                cin >> harga;
                current->harga = harga;
                cout << "Data berhasil diubah!" << endl;
            }
        }

        /* if (head == nullptr)
        {
            cout << "Data kosong." << endl;
            return;
        }

        Skincare *current = head;
        while (current != nullptr && current->namaProduk != namaProduk)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Data tidak ditemukan." << endl;
        }
        else
        {
            current->harga = harga;
            cout << "Data berhasil diupdate." << endl;
        } */
    }

    // Menambahkan data pada urutan tertentu dalam double linked list
    void tambahDataUrutanTertentu(string namaProduk, int harga, int urutan)
    {
        Skincare *newSkincare = new Skincare(namaProduk, harga);

        if (head == nullptr)
        {
            head = newSkincare;
        }
        else
        {
            Skincare *current = head;
            int count = 1;
            while (current->next != nullptr && count < urutan - 1)
            {
                current = current->next;
                count++;
            }
            if (count < urutan - 1)
            {
                cout << "Urutan tertentu tidak valid." << endl;
                return;
            }

            newSkincare->prev = current;
            newSkincare->next = current->next;
            if (current->next != nullptr)
            {
                current->next->prev = newSkincare;
            }
            current->next = newSkincare;
        }

        cout << "Data berhasil ditambahkan pada urutan tertentu." << endl;
    }

    // Menghapus data pada urutan tertentu dalam double linked list
    void hapusDataUrutanTertentu(int urutan)
    {
        if (head == nullptr)
        {
            cout << "Data kosong." << endl;
            return;
        }

        Skincare *current = head;
        int count = 1;
        while (current->next != nullptr && count < urutan)
        {
            current = current->next;
            count++;
        }

        if (count < urutan)
        {
            cout << "Urutan tertentu tidak valid." << endl;
        }
        else
        {
            if (current->prev != nullptr)
            {
                current->prev->next = current->next;
            }
            else
            {
                head = current->next;
            }

            if (current->next != nullptr)
            {
                current->next->prev = current->prev;
            }

            delete current;
            cout << "Data pada urutan tertentu berhasil dihapus." << endl;
        }
    }

    // Menghapus seluruh data dalam double linked list
    void hapusSeluruhData()
    {
        Skincare *current = head;
        while (current != nullptr)
        {
            Skincare *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        cout << "Seluruh data berhasil dihapus." << endl;
    }

    // Menampilkan data dalam double linked list
    void tampilkanData()
    {
        if (head == nullptr)
        {
            cout << "Data kosong." << endl;
            return;
        }

        cout << "Data di dalam toko skincare: " << endl;
        Skincare *current = head;
        while (current != nullptr)
        {
            cout << "Nama Produk: " << current->namaProduk << ", Harga: " << current->harga << endl;
            current = current->next;
        }
    }
};

int main()
{
    TokoSkincare tokoSkincare;
    int pilihan;
    string namaProduk;
    int harga;
    int urutan;
    do
    {
        cout << "======================================" << endl;
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "======================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
string namaLama;
        switch (pilihan)
        {
        case 1:
            cout << "Masukkan Nama Produk: ";
            cin.ignore();
            getline(cin, namaProduk);
            cout << "Masukkan Harga: ";
            cin >> harga;
            tokoSkincare.tambahData(namaProduk, harga);
            break;
        case 2:
            cout << "Masukkan Nama Produk yang ingin dihapus: ";
            cin.ignore();
            getline(cin, namaProduk);
            tokoSkincare.hapusData(namaProduk);
            break;
        case 3:
            cout << "Masukkan nama yang ingin diubah: ";
            cin.ignore();
            getline(cin, namaLama);
            tokoSkincare.updateData(namaLama);
            break;
        case 4:
            cout << "Masukkan Nama Produk: ";
            cin.ignore();
            getline(cin, namaProduk);
            cout << "Masukkan Harga: ";
            cin >> harga;
            cout << "Masukkan Urutan Tertentu: ";
            cin >> urutan;
            tokoSkincare.tambahDataUrutanTertentu(namaProduk, harga, urutan);
            break;
        case 5:
            cout << "Masukkan Urutan Tertentu yang ingin dihapus: ";
            cin >> urutan;
            tokoSkincare.hapusDataUrutanTertentu(urutan);
            break;
        case 6:
            tokoSkincare.hapusSeluruhData();
            break;
        case 7:
            tokoSkincare.tampilkanData();
            break;
        case 8:
            cout << "Terima kasih telah menggunakan program ini." << endl;
            break;
        default:
            cout << "Pilihan menu tidak valid." << endl;
            break;
        }
    } while (pilihan != 8);

    return 0;
}