#include <iostream>
using namespace std;

struct TreeNode
{
    char MuhammadIrsyad_2211102048;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *root;

void createTree(char data)
{
    if (root != NULL)
    {
        cout << "Pohon sudah dibuat." << endl;
        return;
    }

    root = new TreeNode;
    root->MuhammadIrsyad_2211102048 = data;
    root->left = NULL;
    root->right = NULL;

    cout << "Pohon dibuat dengan simpul akar: " << root->MuhammadIrsyad_2211102048 << endl;
}

TreeNode *insertLeft(char data, TreeNode *node)
{
    if (node == NULL)
    {
        cout << "Simpul induk tidak valid." << endl;
        return NULL;
    }

    if (node->left != NULL)
    {
        cout << "Simpul sudah memiliki anak kiri." << endl;
        return NULL;
    }

    TreeNode *newNode = new TreeNode;
    newNode->MuhammadIrsyad_2211102048 = data;
    newNode->left = NULL;
    newNode->right = NULL;

    node->left = newNode;
    cout << "Simpul " << data << " ditambahkan sebagai anak kiri dari " << node->MuhammadIrsyad_2211102048 << endl;

    return newNode;
}

TreeNode *insertRight(char data, TreeNode *node)
{
    if (node == NULL)
    {
        cout << "Simpul induk tidak valid." << endl;
        return NULL;
    }

    if (node->right != NULL)
    {
        cout << "Simpul sudah memiliki anak kanan." << endl;
        return NULL;
    }

    TreeNode *newNode = new TreeNode;
    newNode->MuhammadIrsyad_2211102048 = data;
    newNode->left = NULL;
    newNode->right = NULL;

    node->right = newNode;
    cout << "Simpul " << data << " ditambahkan sebagai anak kanan dari " << node->MuhammadIrsyad_2211102048 << endl;

    return newNode;
}

void updateNode(char newData, TreeNode *node)
{
    if (node == NULL)
    {
        cout << "Simpul tidak valid." << endl;
        return;
    }

    node->MuhammadIrsyad_2211102048 = newData;
    cout << "Data simpul diperbarui menjadi " << newData << endl;
}

void traversePreOrder(TreeNode *node)
{
    if (node == NULL)
        return;

    cout << node->MuhammadIrsyad_2211102048 << " ";
    traversePreOrder(node->left);
    traversePreOrder(node->right);
}

void traverseInOrder(TreeNode *node)
{
    if (node == NULL)
        return;

    traverseInOrder(node->left);
    cout << node->MuhammadIrsyad_2211102048 << " ";
    traverseInOrder(node->right);
}

void traversePostOrder(TreeNode *node)
{
    if (node == NULL)
        return;

    traversePostOrder(node->left);
    traversePostOrder(node->right);
    cout << node->MuhammadIrsyad_2211102048 << " ";
}

int calculateSize(TreeNode *node)
{
    if (node == NULL)
        return 0;

    return 1 + calculateSize(node->left) + calculateSize(node->right);
}

int calculateHeight(TreeNode *node)
{
    if (node == NULL)
        return 0;

    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

void displayData(TreeNode *node, int level)
{
    if (node != NULL)
    {
        displayData(node->right, level + 1);

        for (int i = 0; i < level; i++)
            cout << "     ";
        cout << node->MuhammadIrsyad_2211102048 << endl;

        displayData(node->left, level + 1);
    }
}

void displayData()
{
    cout << "Data yang ada dalam pohon:" << endl;
    displayData(root, 0);
    cout << endl;
}

int main()
{
    root = NULL;

    char rootData;
    cout << "Masukkan data untuk simpul akar: ";
    cin >> rootData;
    createTree(rootData);

    char choice;
    do
    {
        cout << "\nMENU\n";
        cout << "1. Tambahkan anak kiri\n";
        cout << "2. Tambahkan anak kanan\n";
        cout << "3. Perbarui data simpul\n";
        cout << "4. Traversal pre-order\n";
        cout << "5. Traversal in-order\n";
        cout << "6. Traversal post-order\n";
        cout << "7. Tampilkan data pohon\n";
        cout << "8. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            char parentData, newData;
            cout << "Masukkan data simpul induk: ";
            cin >> parentData;
            cout << "Masukkan data simpul baru: ";
            cin >> newData;

            TreeNode *parent = root;
            while (parent != NULL)
            {
                if (parent->MuhammadIrsyad_2211102048 == parentData)
                    break;

                if (parent->left != NULL && parent->left->MuhammadIrsyad_2211102048 == parentData)
                {
                    parent = parent->left;
                    break;
                }
                else if (parent->right != NULL && parent->right->MuhammadIrsyad_2211102048 == parentData)
                {
                    parent = parent->right;
                    break;
                }

                if (parent->left != NULL)
                    parent = parent->left;
                else if (parent->right != NULL)
                    parent = parent->right;
                else
                    parent = NULL;
            }

            if (parent != NULL)
                insertLeft(newData, parent);
            else
                cout << "Simpul induk tidak ditemukan." << endl;

            break;
        }
        case '2':
        {
            char parentData, newData;
            cout << "Masukkan data simpul induk: ";
            cin >> parentData;
            cout << "Masukkan data simpul baru: ";
            cin >> newData;

            TreeNode *parent = root;
            while (parent != NULL)
            {
                if (parent->MuhammadIrsyad_2211102048 == parentData)
                    break;

                if (parent->left != NULL && parent->left->MuhammadIrsyad_2211102048 == parentData)
                {
                    parent = parent->left;
                    break;
                }
                else if (parent->right != NULL && parent->right->MuhammadIrsyad_2211102048 == parentData)
                {
                    parent = parent->right;
                    break;
                }

                if (parent->left != NULL)
                    parent = parent->left;
                else if (parent->right != NULL)
                    parent = parent->right;
                else
                    parent = NULL;
            }

            if (parent != NULL)
                insertRight(newData, parent);
            else
                cout << "Simpul induk tidak ditemukan." << endl;

            break;
        }
        case '3':
        {
            char nodeData, newData;
            cout << "Masukkan data simpul yang akan diperbarui: ";
            cin >> nodeData;
            cout << "Masukkan data baru: ";
            cin >> newData;

            TreeNode *node = root;
            while (node != NULL)
            {
                if (node->MuhammadIrsyad_2211102048 == nodeData)
                    break;

                if (node->left != NULL && node->left->MuhammadIrsyad_2211102048 == nodeData)
                {
                    node = node->left;
                    break;
                }
                else if (node->right != NULL && node->right->MuhammadIrsyad_2211102048 == nodeData)
                {
                    node = node->right;
                    break;
                }

                if (node->left != NULL)
                    node = node->left;
                else if (node->right != NULL)
                    node = node->right;
                else
                    node = NULL;
            }

            if (node != NULL)
                updateNode(newData, node);
            else
                cout << "Simpul tidak ditemukan." << endl;

            break;
        }
        case '4':
            cout << "Traversal pre-order: ";
            traversePreOrder(root);
            cout << endl;
            break;
        case '5':
            cout << "Traversal in-order: ";
            traverseInOrder(root);
            cout << endl;
            break;
        case '6':
            cout << "Traversal post-order: ";
            traversePostOrder(root);
            cout << endl;
            break;
        case '7':
            displayData();
            break;
        case '8':
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != '8');

    return 0;
}