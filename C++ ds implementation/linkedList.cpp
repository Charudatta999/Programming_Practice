#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
    Node *head;

public:
    void insert_at_begining(int data);
    void insert_at_end(int data);
    void insert_at_pos(int pos, int data);
    void delete_at_begining();
    void delete_at_end();
    void delete_at_pos(int pos);
    void print();
    void last_node();
    void deleteNode();
    void traverseToIndex(int pos);
};

void LinkedList::traverseToIndex(int pos)
{
    while (pos - 1 > 1)
    {
        head = head->next;
        pos--;
    }
    return;
}
void LinkedList::last_node()
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    return;
}
void LinkedList ::insert_at_begining(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
    return;
}

void LinkedList::insert_at_end(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;

    if (head->next == NULL)
    {
        head->next = temp;
        return;
    }
    last_node();
    head->next = temp;
    return;
}

void LinkedList::insert_at_pos(int pos, int data)
{
    Node *temp = new Node();
    temp->data = data;

    if (pos == 0)
    {
        insert_at_begining(data);
        return;
    }

    traverseToIndex(pos);
    temp->next = head->next;
    head->next = temp;
}

void LinkedList::deleteNode()
{
    delete (head);
}

void LinkedList::delete_at_end()
{
    Node *temp;
    if (head = NULL)
    {
        cout << "List is Empty";
        return;
    }
    if (head->next == NULL)
    {
        deleteNode();
        return;
    }
    temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    cout << "Element to Be Deleted: " << temp->next->data << endl;
    delete (temp->next);
    temp->next = NULL;
}
void LinkedList::delete_at_pos(int pos)
{
    if (head == NULL)
    {
        cout << "List is Empty";
        return;
    }
    Node *temp, *ptr;
    temp = head;
    if (pos == 0)
    {
        cout << "Element Deleted: " << head->data << endl;
        ptr = head;
        head = head->next;
        delete (ptr);
        return;
    }
    while (pos-2>1)
    {
        head = head->next;
        pos--;
    }
    temp= head->next;
    head->next = temp->next;
    delete (temp);
}