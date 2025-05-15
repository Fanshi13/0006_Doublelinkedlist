#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int nodeMhs;
    node *next;
    node *previous;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()(
        START = NULL;)

        void addNode()(
            int nim;
            string nim;
            cout << "\nEnter the roll number of the student";
            cin >> nim;

            // Step 1: Allocate memory for new node
            Node *newNode = new Node();

            // Step 2: Assign value to the data fields
            newNode->noMhs = nim;

        )
}