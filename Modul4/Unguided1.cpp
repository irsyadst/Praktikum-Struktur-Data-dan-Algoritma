#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    Mahasiswa *next;
};

Mahasiswa *head = NULL;
Mahasiswa *tail = NULL;

void tambahDepan()
{
    Mahasiswa *new_mhs = new Mahasiswa;
    cout << "Masukkan Nama Mahasiswa: ";
    cin >> new_mhs->nama;
    cout << "Masukkan NIM Mahasiswa: ";
    cin >> new_mhs->nim;
    new_mhs->next = NULL;
    if (head == NULL)
    {
        head = new_mhs;
        tail = new_mhs;
    }
    else
    {
        new_mhs->next = head;
        head = new_mhs;
    }
    cout << "Mahasiswa berhasil ditambahkan di depan.\n\n";
}

void tambahBelakang()
{
    Mahasiswa *new_mhs = new Mahasiswa;
    cout << "Masukkan Nama Mahasiswa: ";
    cin >> new_mhs->nama;
    cout << "Masukkan NIM Mahasiswa: ";
    cin >> new_mhs->nim;
    new_mhs->next = NULL;
    if (head == NULL)
    {
        head = new_mhs;
        tail = new_mhs;
    }
    else
    {
        tail->next = new_mhs;
        tail = new_mhs;
    }
    cout << "Mahasiswa berhasil ditambahkan di belakang.\n\n";
}

void tambahTengah()
{
    int posisi;
    cout << "Masukkan Posisi yang ingin ditambahkan: ";
    cin >> posisi;
    if (posisi == 1)
    {
        tambahDepan();
    }
    else
    {
        Mahasiswa *new_mhs = new Mahasiswa;
        cout << "Masukkan Nama Mahasiswa: ";
        cin >> new_mhs->nama;
        cout << "Masukkan NIM Mahasiswa: ";
        cin >> new_mhs->nim;
        new_mhs->next = NULL;
        Mahasiswa *temp = head;
        for (int i = 1; i < posisi - 1; i++)
        {
            temp = temp->next;
        }
        new_mhs->next = temp->next;
        temp->next = new_mhs;
        cout << "Mahasiswa berhasil ditambahkan di tengah.\n\n";
    }
}

void ubahDepan()
{
    if (head == NULL)
    {
        cout << "Linked List kosong.\n\n";
    }
    else
    {
        cout << "Data Mahasiswa di Depan: " << head->nama << " - " << head->nim << "\n";
        cout << "Masukkan Nama Mahasiswa Baru: ";
        cin >> head->nama;
        cout << "Masukkan NIM Mahasiswa Baru: ";
        cin >> head->nim;
        cout << "Data Mahasiswa berhasil diubah di depan.\n\n";
    }
}

void ubahBelakang()
{
    if (head == NULL)
    {
        cout << "Linked List kosong.\n\n";
    }
    else
    {
        cout << "Data Mahasiswa di Belakang: " << tail->nama << " - " << tail->nim << "\n";
        cout << "Masukkan Nama Mahasiswa Baru: ";
        cin >> tail->nama;
        cout << "Masukkan NIM Mahasiswa Baru: ";
        cin >> tail->nim;
        cout << "Data Mahasiswa berhasil diubah di belakang.\n\n";
    }
}

void ubahTengah()
{
    int posisi;
    cout << "Masukkan Posisi yang ingin diubah: ";
    cin >> posisi;
    Mahasiswa *temp = head;
    for (int i = 1; i < posisi; i++)
    {
        temp = temp->next;
    }
    cout << "Data Mahasiswa di Posisi " << posisi << ": " << temp->nama << " - " << temp->nim << "\n";
    cout << "Masukkan Nama Mahasiswa Baru: ";
    cin >> temp->nama;
    cout << "Masukkan NIM Mahasiswa Baru: ";
    cin >> temp->nim;
    cout << "Data Mahasiswa berhasil diubah di tengah.\n\n";
}

void hapusDepan()
{
    if (head == NULL)
    {
        cout << "Linked List kosong.\n\n";
    }
    else
    {
        Mahasiswa *temp = head;
        head = head->next;
        delete temp;
        cout << "Mahasiswa berhasil dihapus di depan.\n\n";
    }
}

void hapusBelakang()
{
    if (head == NULL)
    {
        cout << "Linked List kosong.\n\n";
    }
    else if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
        cout << "Mahasiswa berhasil dihapus di belakang.\n\n";
    }
    else
    {
        Mahasiswa *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
        cout << "Mahasiswa berhasil dihapus di belakang.\n\n";
    }
}

void hapusTengah()
{
    int posisi;
    cout << "Masukkan Posisi yang ingin dihapus: ";
    cin >> posisi;
    if (posisi == 1)
    {
        hapusDepan();
    }
    else if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
        cout << "Mahasiswa berhasil dihapus di tengah.\n\n";
    }
    else
    {
        Mahasiswa *temp1 = head;
        for (int i = 1; i < posisi - 1; i++)
        {
            temp1 = temp1->next;
        }
        Mahasiswa *temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        cout << "Mahasiswa berhasil dihapus di tengah.\n\n";
    }
}

void hapusList()
{
    if (head == NULL)
    {
        cout << "Linked List kosong.\n\n";
    }
    else
    {
        while (head != NULL)
        {
            Mahasiswa *temp = head;
            head = head->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
        cout << "Seluruh data mahasiswa berhasil dihapus.\n\n";
    }
}

void tampilkan()
{
    if (head == NULL)
    {
        cout << "Linked List kosong.\n\n";
    }
    else
    {
        cout << "Daftar Mahasiswa:\n";
        Mahasiswa *temp = head;
        while (temp != NULL)
        {
            cout << temp->nama << " - " << temp->nim << "\n";
            temp = temp->next;
        }
        cout << "\n";
    }
}

int main()
{
    int pilihan;
    do
    {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tambah Tengah\n";
        cout << "4. Ubah Depan\n";
        cout << "5. Ubah Belakang\n";
        cout << "6. Ubah Tengah\n";
        cout << "7. Hapus Depan\n";
        cout << "8. Hapus Belakang\n";
        cout << "9. Hapus Tengah\n";
        cout << "10. Hapus List\n";
        cout << "11. Tampilkan\n";
        cout << "0. Keluar\n";
        cout << "Pilih Operasi: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            tambahDepan();
            break;
        case 2:
            tambahBelakang();
            break;
        case 3:
            tambahTengah();
            break;
        case 4:
            ubahDepan();
            break;
        case 5:
            ubahBelakang();
            break;
        case 6:
            ubahTengah();
            break;
        case 7:
            hapusDepan();
            break;
        case 8:
            hapusBelakang();
            break;
        case 9:
            hapusTengah();
            break;
        case 10:
            hapusList();
            break;
        case 11:
            tampilkan();
            break;
        case 0:
            break;
        default:
            cout << "Pilihan tidak tersedia.\n\n";
        }
    } while (pilihan != 0);
    return 0;
}