#include <bits/stdc++.h>
using namespace std;

// struct Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int data)
//     {
//         this->data = data;
//         this->next = nullptr;
//     }
// };

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void printList(Node *head)
{
    Node *mover = head;
    while (mover != nullptr)
    {
        cout << mover->data << " ";
        mover = mover->next;
    }
    return;
}

int lengthofList(Node *head)
{
    int len = 0;
    Node *mover = head;
    while (mover != nullptr)
    {
        len++;
        mover = mover->next;
    }
    return len;
}

Node *deleteAtHead(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

Node *deleteAtTail(Node *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        free(head);
        return nullptr;
    }

    Node *mover = head;
    while (mover->next->next != nullptr)
    {
        mover = mover->next;
    }

    Node *temp = mover->next;
    mover->next = nullptr;
    free(temp);

    return head;
}

Node *deleteKth(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;

    if (k == 0)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    if (k > lengthofList(head))
        return head;

    int count = 0;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        count++;

        if (count == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *insertAtHead(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;

    return temp;
}

Node *insertAtEnd(Node *head, int val)
{
    Node *mover = head;

    while (mover->next != nullptr)
    {
        mover = mover->next;
    }

    Node *temp = new Node(val);
    mover->next = temp;

    return head;
}

Node *insertAtKth(Node *head, int k, int val)
{
    // TODO
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = new Node(v[0]);
    // cout << head << endl;
    // cout << head->data << endl;

    //? converting the above array into linked list
    Node *mover = head;

    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
    }

    //? printing the linked list
    // mover = head;
    // while (mover != nullptr)
    // {
    //     cout << mover->data << " ";
    //     mover = mover->next;
    // }

    // head = deleteAtHead(head);
    // head = deleteAtTail(head);
    head = insertAtHead(head, 100);
    head = insertAtEnd(head, 100);
    printList(head);

    return 0;
}