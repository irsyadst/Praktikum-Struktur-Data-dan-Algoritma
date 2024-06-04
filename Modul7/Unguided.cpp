#include <iostream>
using namespace std;

struct Node
{
    string nama;
    string nim;
    Node *next;
};

class AntrianMahasiswa
{
private:
    Node *front;
    Node *rear;

public:
    AntrianMahasiswa()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty()
    {
        return (front == nullptr);
    }

    void enqueueData(string nama, string nim)
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Data " << nama << " (" << nim << ") ditambahkan" << endl;
    }

    void dequeueData()
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            cout << "Data " << temp->nama << " (" << temp->nim << ") dihapus" << endl;
            delete temp;

            if (front == nullptr)
            {
                rear = nullptr;
            }
        }
    }

    void viewData()
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
        }
        else
        {
            cout << "Data mahasiswa dalam antrian: " << endl;
            Node *current = front;
            int i = 1;

            while (current != nullptr)
            {
                cout << i << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
                current = current->next;
                i++;
            }
        }
    }

    void resetData()
    {
        while (!isEmpty())
        {
            dequeueData();
        }
    }
};

int main()
{
    AntrianMahasiswa antrian;

    int pilihan;
    string nama, nim;

    do
    {
        cout << "Menu: " << endl;
        cout << "1. Masukkan Data" << endl;
        cout << "2. Hapus Satu Data" << endl;
        cout << "3. Reset Data" << endl;
        cout << "4. Tampil Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan Nama Mahasiswa: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> nim;
            antrian.enqueueData(nama, nim);
            break;

        case 2:
            antrian.dequeueData();
            break;

        case 3:
            antrian.resetData();
            break;

        case 4:
            antrian.viewData();
            break;

        case 5:
            cout << "Terima kasih!" << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

        cout << endl;
    } while (pilihan != 5);

    return 0;
}
