#include <iostream>
using namespace std;

// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;

// Inisialisasi
void init()
{
    root = NULL;
}

// Cek Node
int isEmpty()
{
    if (root == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(char data)
{
    if (isEmpty() == 1)
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kiri ada atau tidak
        if (node->left != NULL)
        {
            // kalau ada
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Tambah Kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (root == NULL)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kanan ada atau tidak
        if (node->right != NULL)
        {
            // kalau ada
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Ubah Data Tree
void update(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Lihat Isi Data Tree
void retrieve(Pohon *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

// Cari Data Tree
void find(Pohon *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node: " << node->data << endl;
            cout << "Root: " << root->data << endl;
            if (!node->parent)
                cout << "Parent: (tidak punya parent)" << endl;
            else
                cout << "Parent: " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling: " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling: " << node->parent->right->data << endl;
            else
                cout << "Sibling: (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri: (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri: " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan: (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan: " << node->right->data << endl;
        }
    }
}

// Penelurusan (Traversal)
// preOrder
void preOrder(Pohon *node = root)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node = root)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node = root)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear()
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic()
{
    cout << "\nSize Tree: " << size() << endl;
    cout << "Height Tree: " << height() << endl;
    cout << "Average Node of Tree: " << size() / height() << endl;
}

int main()
{
    init();
    int choice;
    char data;
    Pohon *currentNode = NULL;
    while (true)
    {
        cout << "\nBinary Tree Program" << endl;
        cout << "1. Buat Node" << endl;
        cout << "2. Tambah Node Kiri" << endl;
        cout << "3. Tambah Node Kanan" << endl;
        cout << "4. Ubah Data Node" << endl;
        cout << "5. Lihat Isi Data Node" << endl;
        cout << "6. Cari Data Node" << endl;
        cout << "7. PreOrder Traversal" << endl;
        cout << "8. InOrder Traversal" << endl;
        cout << "9. PostOrder Traversal" << endl;
        cout << "10. Hapus SubTree" << endl;
        cout << "11. Clear Tree" << endl;
        cout << "12. Karakteristik Tree" << endl;
        cout << "13. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nMasukkan data node: ";
            cin >> data;
            buatNode(data);
            break;
        case 2:
            if (isEmpty() == 0)
            {
                cout << "\nMasukkan data node kiri: ";
                cin >> data;
                currentNode = insertLeft(data, currentNode);
            }
            break;
        case 3:
            if (isEmpty() == 0)
            {
                cout << "\nMasukkan data node kanan: ";
                cin >> data;
                currentNode = insertRight(data, currentNode);
            }
            break;
        case 4:
            if (isEmpty() == 0)
            {
                cout << "\nMasukkan data node yang ingin diubah: ";
                cin >> data;
                update(data, currentNode);
            }
            break;
        case 5:
            if (isEmpty() == 0)
            {
                retrieve(currentNode);
            }
            break;
        case 6:
            if (isEmpty() == 0)
            {
                find(currentNode);
            }
            break;
        case 7:
            if (isEmpty() == 0)
            {
                cout << "\nPreOrder Traversal:";
                preOrder();
                cout << endl;
            }
            break;
        case 8:
            if (isEmpty() == 0)
            {
                cout << "\nInOrder Traversal:";
                inOrder();
                cout << endl;
            }
            break;
        case 9:
            if (isEmpty() == 0)
            {
                cout << "\nPostOrder Traversal:";
                postOrder();
                cout << endl;
            }
            break;
        case 10:
            if (isEmpty() == 0)
            {
                deleteSub(currentNode);
            }
            break;
        case 11:
            if (isEmpty() == 0)
            {
                clear();
            }
            break;
        case 12:
            if (isEmpty() == 0)
            {
                characteristic();
            }
            break;
        case 13:
            cout << "\nTerima kasih!" << endl;
            return 0;
        default:
            cout << "\nPilihan tidak valid. Silakan pilih kembali." << endl;
        }
    }
}
