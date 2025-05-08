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
        }

}