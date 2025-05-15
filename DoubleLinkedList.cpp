#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *previous;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }
    void addNode()
    {
        int nim;
        string nim;
        cout << "\nEnter the roll number of the student";
        cin >> nim;

        // Step 1: Allocate memory for new node
        Node *newNode = new Node();

        // Step 2: Assign value to the data fields
        newNode->noMhs = nim;

        // Step 3: Insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
        }

        // Step 4: newNode.next = START
        newNode->next = START;

        // Step 5: start.prev = newNode (if start exist)
        if (START != NULL)
            START->previous = newNode;

        // Step 6: newNode.previous = NULL
        newNode->previous = NULL;

        // Step 7: START =newNode
        START = newNode;
        return;

        // Step 8: locate pottion for insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        // Step 9: insert between current and current->next
        newNode->next = current->next; // Step 9a
        newNode->previous = current;   // Step 9b

        // Insert last node
        if (current->next != NULL)             // Step 9c
            current->next->previous = newNode; // Step 9d
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        // Step 1: Traverse the list to find the node
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "Record not found" << endl;
        }

        // Step 2: If node is at the beginning
        if (current == START)
        {
            START = current->next;
            if (START != NULL)
                START->next = NULL;
        }
        else
    }
};