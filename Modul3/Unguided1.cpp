#include <iostream>
using namespace std;
struct Mahasiswa
{
    string nama;
    int usia;
    Mahasiswa *next;
};
class LinkedList
{
private:
    Mahasiswa *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void tambahMahasiswaAwal()
    {
        Mahasiswa *new_mahasiswa = new Mahasiswa;
        cout << "Masukkan nama mahasiswa: ";
        cin >> new_mahasiswa->nama;
        cout << "Masukkan usia mahasiswa: ";
        cin >> new_mahasiswa->usia;
        new_mahasiswa->next = NULL;
        if (head == NULL)
        {
            head = new_mahasiswa;
        }
        else
        {
            Mahasiswa *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = new_mahasiswa;
        }
        cout << "Mahasiswa berhasil ditambahkan." << endl;
    }
    void tambahMahasiswa()
    {
        int pilihan;
        cout << "1. Insert depan\n";
        cout << "2. Insert belakang\n";
        cout << "3. Insert tengah\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        if (pilihan == 1)
        {
            Mahasiswa *new_mahasiswa = new Mahasiswa;
            cout << "Masukkan nama mahasiswa: ";
            cin >> new_mahasiswa->nama;
            cout << "Masukkan usia mahasiswa: ";
            cin >> new_mahasiswa->usia;
            new_mahasiswa->next = head;
            head = new_mahasiswa;
        }
        else if (pilihan == 2)
        {
            Mahasiswa *new_mahasiswa = new Mahasiswa;
            cout << "Masukkan nama mahasiswa: ";
            cin >> new_mahasiswa->nama;
            cout << "Masukkan usia mahasiswa: ";
            cin >> new_mahasiswa->usia;
            new_mahasiswa->next = NULL;
            Mahasiswa *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = new_mahasiswa;
        }
        else if (pilihan == 3)
        {
            int posisi;
            cout << "Masukkan posisi: ";
            cin >> posisi;
            if (posisi < 1)
            {
                cout << "Posisi harus lebih besar dari 0." << endl;
            }
            else if (posisi == 1)
            {
                Mahasiswa *new_mahasiswa = new Mahasiswa;
                cout << "Masukkan nama mahasiswa: ";
                cin >> new_mahasiswa->nama;
                cout << "Masukkan usia mahasiswa: ";
                cin >> new_mahasiswa->usia;
                new_mahasiswa->next = head;
                head = new_mahasiswa;
            }
            else
            {
                Mahasiswa *new_mahasiswa = new Mahasiswa;
                cout << "Masukkan nama mahasiswa: ";
                cin >> new_mahasiswa->nama;
                cout << "Masukkan usia mahasiswa: ";
                cin >> new_mahasiswa->usia;
                Mahasiswa *current = head;
                for (int i = 1; i < posisi - 1; i++)
                {
                    if (current->next == NULL)
                    {
                        cout << "Posisi tidak valid." << endl;
                        return;
                    }
                    current = current->next;
                }
                new_mahasiswa->next = current->next;
                current->next = new_mahasiswa;
            }
        }
        else
        {
            cout << "Pilihan tidak valid." << endl;
        }
    }
    void hapusMahasiswa()
    {
        if (head == NULL)
        {
            cout << "Linked list kosong." << endl;
        }
        else
        {
            int posisi;
            cout << "Masukkan posisi: ";
            cin >> posisi;
            if (posisi < 1)
            {
                cout << "Posisi harus lebih besar dari 0." << endl;
            }
            else if (posisi == 1)
            {
                Mahasiswa *temp = head;
                head = head->next;
                delete temp;
            }
            else
            {
                Mahasiswa *current = head;
                for (int i = 1; i < posisi - 1; i++)
                {
                    if (current->next == NULL)
                    {
                        cout << "Posisi tidak valid." << endl;
                        return;
                    }
                    current = current->next;
                }
                Mahasiswa *temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            cout << "Mahasiswa berhasil dihapus." << endl;
        }
    }
    void tampilMahasiswa()
    {
        if (head == NULL)
        {
            cout << "Linked list kosong." << endl;
        }
        else
        {
            Mahasiswa *current = head;
            while (current != NULL)
            {
                cout << "Nama: " << current->nama << ", Usia: " << current->usia << endl;
                current = current->next;
            }
        }
    }
    void ubahMahasiswa()
    {
        if (head == NULL)
        {
            cout << "Linked list kosong." << endl;
        }
        else
        {
            int posisi;
            cout << "Masukkan posisi: ";
            cin >> posisi;
            if (posisi < 1)
            {
                cout << "Posisi harus lebih besar dari 0." << endl;
            }
            else if (posisi == 1)
            {
                // ubah depan
                cout << "Masukkan nama mahasiswa: ";
                cin >> head->nama;
                cout << "Masukkan usia mahasiswa: ";
                cin >> head->usia;
            }
            else
            {
                Mahasiswa *current = head;
                for (int i = 1; i < posisi; i++)
                {
                    if (current == NULL)
                    {
                        cout << "Posisi tidak valid." << endl;
                        return;
                    }
                    current = current->next;
                }
                if (current == NULL)
                {
                    cout << "Posisi tidak valid." << endl;
                }
                else
                {
                    cout << "Masukkan nama mahasiswa: ";
                    cin >> current->nama;
                    cout << "Masukkan usia mahasiswa: ";
                    cin >> current->usia;
                }
            }
            cout << "Mahasiswa berhasil diubah." << endl;
        }
    }
};
int main()
{
    LinkedList linkedList;
    int pilihan;
    linkedList.tambahMahasiswaAwal();
    do
    {
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Tampilkan Data\n";
        cout << "4. Ubah Data Mahasiswa\n";
        cout << "5. Exit\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            linkedList.tambahMahasiswa();
            break;
        case 2:
            linkedList.hapusMahasiswa();
            break;
        case 3:
            linkedList.tampilMahasiswa();
            break;
        case 4:
            linkedList.ubahMahasiswa();
            break;
        case 5:
            cout << "Terima Kasih" << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    } while (pilihan != 5);
    return 0;
}