#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

class Queue
{
private:
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }

    void enqueueAntrian(string data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        cout << "Antrian " << data << " ditambahkan" << endl;
    }

    void dequeueAntrian()
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            cout << "Antrian " << temp->data << " dihapus" << endl;
            delete temp;

            if (head == nullptr)
            {
                tail = nullptr;
            }
        }
    }

    void viewQueue()
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
        }
        else
        {
            cout << "Data antrian teller: " << endl;
            Node *current = head;
            int i = 1;

            while (current != nullptr)
            {
                cout << i << ". " << current->data << endl;
                current = current->next;
                i++;
            }
        }
    }

    int countQueue()
    {
        int count = 0;
        Node *current = head;

        while (current != nullptr)
        {
            count++;
            current = current->next;
        }

        return count;
    }

    void clearQueue()
    {
        while (!isEmpty())
        {
            dequeueAntrian();
        }
    }
};

int main()
{
    Queue queue;

    queue.enqueueAntrian("Andi");
    queue.enqueueAntrian("Maya");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}
