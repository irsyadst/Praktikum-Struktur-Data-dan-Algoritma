#include <iostream>
#include <string>

using namespace std;

// Struktur Node untuk Linked List
struct Mahasiswa
{
    string nama;
    int usia;
    struct Mahasiswa *next;
};

// Fungsi untuk menambahkan data di depan Linked List
void insertDepan(struct Mahasiswa **head, string nama, int usia)
{
    struct Mahasiswa *newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = *head;
    *head = newNode;
}

// Fungsi untuk menambahkan data di belakang Linked List
void insertBelakang(struct Mahasiswa **head, string nama, int usia)
{
    struct Mahasiswa *newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Mahasiswa *tempNode = *head;
    while (tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }

    tempNode->next = newNode;
}

// Fungsi untuk menambahkan data di tengah Linked List
void insertTengah(struct Mahasiswa **head, string nama, int usia, int posisi)
{
    if (posisi <= 0)
    {
        cout << "Posisi tidak valid" << endl;
        return;
    }

    if (posisi == 1)
    {
        insertDepan(head, nama, usia);
        return;
    }

    struct Mahasiswa *newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->usia = usia;

    struct Mahasiswa *tempNode = *head;
    int counter = 1;
    while (tempNode != NULL && counter < posisi - 1)
    {
        tempNode = tempNode->next;
        counter++;
    }

    if (tempNode == NULL)
    {
        cout << "Posisi tidak valid" << endl;
        return;
    }

    newNode->next = tempNode->next;
    tempNode->next = newNode;
}

// Fungsi untuk menghapus data dari Linked List
void hapusData(struct Mahasiswa **head, string nama)
{
    if (*head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    if ((*head)->nama == nama)
    {
        struct Mahasiswa *tempNode = *head;
        *head = (*head)->next;
        delete tempNode;
        cout << "Data " << nama << " telah dihapus" << endl;
        return;
    }

    struct Mahasiswa *tempNode = *head;
    while (tempNode->next != NULL && tempNode->next->nama != nama)
    {
        tempNode = tempNode->next;
    }

    if (tempNode->next == NULL)
    {
        cout << "Data " << nama << " tidak ditemukan" << endl;
        return;
    }

    struct Mahasiswa *deleteNode = tempNode->next;
    tempNode->next = tempNode->next->next;
    delete deleteNode;
    cout << "Data " << nama << " telah dihapus" << endl;
}

// Fungsi untuk mengubah data dalam Linked List
void ubahData(struct Mahasiswa **head, string namaLama, string namaBaru, int usiaBaru)
{
    struct Mahasiswa *tempNode = *head;
    bool dataDitemukan = false;
    while (tempNode != NULL)
    {
        if (tempNode->nama == namaLama)
        {
            tempNode->nama = namaBaru;
            tempNode->usia = usiaBaru;
            dataDitemukan = true;
            break;
        }
        tempNode = tempNode->next;
    }

    if (dataDitemukan)
    {
        cout << "Data " << namaLama << " telah diubah menjadi " << namaBaru << " dengan usia " << usiaBaru << endl;
    }
    else
    {
        cout << "Data " << namaLama << " tidak ditemukan" << endl;
    }
}

// Fungsi untuk menampilkan seluruh data dalam Linked List
void tampilkanData(struct Mahasiswa *head)
{
    if (head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }
    struct Mahasiswa *tempNode = head;
    cout << "Data Mahasiswa:" << endl;
    while (tempNode != NULL)
    {
        cout << "Nama: " << tempNode->nama << ", Usia: " << tempNode->usia << endl;
        tempNode = tempNode->next;
    }
}

int main()
{
    struct Mahasiswa *head = NULL; // Pointer kepala Linked List
    int pilihan;
    string nama, namaLama, namaBaru;
    int usia, usiaBaru;
    int posisi;
    // // Menampilkan data pertama (nama dan usia pengguna)
    cout << "Masukkan nama anda: ";
    getline(cin, nama);
    cout << "Masukkan usia anda: ";
    cin >> usia;

    insertDepan(&head, nama, usia);

    do
    {
        cout << endl;
        cout << "Menu Linked List Non-Circular: " << endl;
        cout << "1. Masukkan data di depan" << endl;
        cout << "2. Masukkan data di belakang" << endl;
        cout << "3. Masukkan data di tengah" << endl;
        cout << "4. Hapus data" << endl;
        cout << "5. Ubah data" << endl;
        cout << "6. Tampilkan data" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilihan anda: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan nama: ";
            getline(cin, nama);
            cout << "Masukkan usia: ";
            cin >> usia;
            insertDepan(&head, nama, usia);
            break;
        case 2:
            cout << "Masukkan nama: ";
            getline(cin, nama);
            cout << "Masukkan usia: ";
            cin >> usia;
            insertBelakang(&head, nama, usia);
            break;
        case 3:
            cout << "Masukkan nama: ";
            getline(cin, nama);
            cout << "Masukkan usia: ";
            cin >> usia;
            cout << "Masukkan posisi: ";
            cin >> posisi;
            insertTengah(&head, nama, usia, posisi);
            break;
        case 4:
            cout << "Masukkan nama yang akan dihapus: ";
            getline(cin, nama);
            hapusData(&head, nama);
            break;
        case 5:
            cout << "Masukkan nama yang ingin diubah: ";
            getline(cin, nama);
            cout << "Masukkan nama baru: ";
            getline(cin, namaBaru);
            cout << "Masukkan usia baru: ";
            cin >> usiaBaru;
            ubahData(&head, nama, namaBaru, usiaBaru);
            break;
        case 6:
            tampilkanData(head);
            break;
        case 7:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    } while (pilihan != 7);

    return 0;
}