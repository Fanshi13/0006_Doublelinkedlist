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
        {
            // Step 3: Link previous node to next of current
            current->previous->next != NULL;

            // Step 4: If current is not the last node
            if (current->next != NULL)
                current->next->previous = current->previous;
        }

        // Step 5: Deleted the node
        delete current;
        cout << "Record with roll number" << rollNo << "deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: Mark first node as currentNode
        Node *currentNode = START;

        // Step 2: Repeat until currentNode != NULL
        cout << "\nRecord is ascending order of roll number are:\n";
        int i = 0;
        while (currentNode != NULL)
        {

            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            // Step 3: Move to next node
            currentNode = currentNode->next;
            i++;
        }
    }

    void revtraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: Move to last node
        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            i++;
        }
        // Step 2: Traverse backward
        cout << "\nRecord is descending order of roll number are:\n";
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->next << " " << endl;

            // Step 3: Move to previous node
            currentNode = currentNode->previous;
            i--;
        }
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        // Step 1: Traverse to find matching roll number
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        // Step 2: Output result
        if (current != NULL)
        {
            cout << "Record not found\n";
        }
        else
        {
            cout << "Record found\n";
            cout << "Roll Number: " << current->noMhs << endl;
        }
    }
};

int main()
{
    DoubleLinkedList list;
    char choice;

    do
    {
        cout << "nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Delete Record\n";
        cout << "3. View Ascending";
        cout << "4. View Descending";
        cout << "5. Search Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case '1':
            list.addNode();
            break;
        case '2':
            list.hapus();
            break;
        case '3':
            list.traverse();
        case '4':
            list.revtraverse();
            break;
        case '5':
            list.searchData();
        case '6':
            return 0;
        default:
            cout << "Invalid option\n";
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
    } while (choice != '6');
}