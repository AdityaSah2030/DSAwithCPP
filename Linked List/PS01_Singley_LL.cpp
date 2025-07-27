#include<iostream>
using namespace std;

// Defines the structure of a single node in the linked list.
class node
{
public:
    int data;
    node *next;

    node()
    {
        next = NULL;
    }
};

// Defines the linked list class, which manages all the nodes.
class LinkedList
{
    node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Prints the entire list.
    void print()
    {
        cout << "Current List: ";
        if(head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        
        node *temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // --- INSERTION LOGIC ---

    // Inserts a new node at the beginning. O(1)
    void insert_at_beg(int value)
    {
        node *newNode = new node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Inserts a new node at the end. O(N)
    void insert_at_end(int value)
    {
        node *newNode = new node();
        newNode->data = value;

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Inserts a new node at a specific position (1-based index). O(N)
    void insert_in_middle(int value, int position)
    {
        if (position < 1) 
        {
            cout << "Invalid position. Position must be 1 or greater." << endl;
            return;
        }
        
        if (position == 1)
        {
            insert_at_beg(value);
            return;
        }

        node *temp = head;
        // Traverse to the node JUST BEFORE the insertion point.
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid position. Position " << position << " is out of bounds." << endl;
            return;
        }

        node *newNode = new node();
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // --- DELETION LOGIC ---

    // Deletes the first node in the list. O(1)
    void delete_from_beg()
    {
        if (head == NULL) {
            cout << "Cannot delete, list is empty." << endl;
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
    }

    // Deletes the last node in the list. O(N)
    void delete_from_end()
    {
        if (head == NULL) {
            cout << "Cannot delete, list is empty." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        node *second_last = head;
        while (second_last->next->next != NULL) {
            second_last = second_last->next;
        }
        delete second_last->next;
        second_last->next = NULL;
    }

    // Deletes a node from a specific position (1-based index). O(N)
    void delete_from_pos(int position)
    {
        if (head == NULL || position < 1) {
            cout << "Cannot delete, list is empty or position is invalid." << endl;
            return;
        }
        if (position == 1) {
            delete_from_beg();
            return;
        }
        node *prev = head;
        for (int i = 1; i < position - 1 && prev != NULL; i++) {
            prev = prev->next;
        }
        if (prev == NULL || prev->next == NULL) {
            cout << "Position " << position << " is out of bounds." << endl;
            return;
        }
        node *node_to_delete = prev->next;
        prev->next = node_to_delete->next;
        delete node_to_delete;
    }
};

int main()
{
    LinkedList ll;
    ll.insert_at_end(10);
    ll.insert_at_end(20);
    ll.insert_at_end(40);
    ll.insert_at_end(50);
    ll.print();

    cout << "\n--- Testing Insertion in Middle ---" << endl;
    ll.insert_in_middle(30, 3);
    ll.print();

    cout << "\n--- Testing Deletion ---" << endl;
    ll.delete_from_beg();
    ll.print();

    ll.delete_from_end();
    ll.print();

    ll.delete_from_pos(2);
    ll.print();

    return 0;
}