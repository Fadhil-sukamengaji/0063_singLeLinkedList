#include <iostream>
using namespace std;

class Node
{
    public:
        int noMhs;
        Node *next;
};

class LinkedList
{
    Node *START;

    public:
        LinkedList()
        {
            START = NULL;
        }

        void addNode()
        {
            int nim;
            cout << "\nmasukkan nomor mahasiswa : ";
            cin >> nim;

            Node *nodeBaru = new Node;
            nodeBaru->noMhs = nim;

            if (START == NULL || nim <= START->noMhs)
            {
                if ((START != NULL) && (nim == START->noMhs))
                {
                    cout << "\nduplikasi noMhs tidak diijinkan\n";
                    return;
                }
                nodeBaru->next = START;
                START = nodeBaru;
                return;
            }

            Node *previous = START;
            Node *current = START;

            while ((current != NULL) && (nim >= current->noMhs))
            {
                if (nim == current->noMhs)
                {
                    cout << "\nduplikasi noMhs tidak diijinkan\n";
                    return;
                }
                previous = current;
                current = current->next;
            }

            nodeBaru->next = current;
            previous->next = nodeBaru;
        }

        bool listEmpety()
        {
            return (START == NULL);
        }

        bool Search(int nim, Node **previous, Node **current)
        {
            *previous = START;
            *current = START;

            while ((*current != NULL) && (nim != (*current)->noMhs))
            {
                *previous = *current;
                *current = (*current)->next;
            }
            return (*current != NULL);
        }

        bool delNode(int nim)
        {
            Node *current, *previous;
            if (!Search(nim, &previous, &current))
                return false;

            if (current == START)
                START = START->next;
            else    previous->next = current->next;

            delete current;
            return true;
        }

        void traverse()
        {
            if (listEmpety())
            {
                cout << "\nlist kosong\n";
            }
            else
            {
                cout << "\ndata didalam list adalah :\n";
                Node *currentNode = START;
                while (currentNode != NULL)
                {
                    cout << currentNode->noMhs << endl;
                    currentNode = currentNode->next;
                }
                cout << endl;
            }
        }

};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << "menu" << endl;
        cout << "1. menambah data kedalam list" << endl;
        cout << "2. menghapus data dari dalam list" << endl;
        cout << "3. menampilkan semua data didalam list" << endl;
        cout << "4. mencari data dalam list" << endl;
        cout << "5. keluar" << endl;
        cout << endl
            << "masukkan pilihan (1-5) : ";
        cin >> ch;
        switch (ch)
        {
            case '1':
            {
                mhs.addNode();
                break;
            }
            case '2':
            {
                if (mhs. listEmpety())
                {
                    cout << endl
                        << "list kosong" << endl;
                    break;
                }
                cout << endl
                    << "\nmasukkan no mahasiswa yang akan dihapus : ";
                cin >> nim;
                if (mhs.delNode(nim) == false)
                    cout << endl
                        << "data tidak ditemukan" << endl;
                else
                    cout << endl
                        << "data dengan nomor mahasiswa " << nim << " berhasil dihapus " << endl;
            }
            break;
            case '3':
            {
                mhs.traverse();
            }
            break;

            case '4':
            {
                if (mhs.listEmpety() == true)
                {
                    cout << "\nlist kosong\n";
                    break;
                }
                Node *previous, *current;
                cout << endl
                    << "masukkan no mahasiswa yang dicari : ";
                cin >> nim;
                if (mhs.Search(nim, &previous, &current) == false)
                    cout << endl
                        << "data tidak ditemukan" << endl;
                else
                {
                    cout << endl
                        << "data ditemukan" << endl;
                    cout << "\nno mahasiswa : " << current->noMhs << endl;
                    cout << "\n";
                }
            }
            break;
            case '5':
            {

            }
            break;
            default:
            {
                cout << "pilihan salah !." << endl;
            }
            break;
        }
    }while (ch != '5');
}