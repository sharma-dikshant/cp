#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

Node *convertArrToDD(vector<int> &v)
{
    Node *head = new Node(v[0]);
    Node *prev = head;

    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i]);
        temp->prev = prev;
        prev->next = temp;
        temp->next = nullptr;
        prev = temp;
    }

    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *deleteHead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *prev = head;
    head = head->next;

    head->prev = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    Node *temp1 = temp->next;
    temp->next = nullptr;
    delete temp1;

    return head;
}

Node *deleteKth(Node *head, int k)
{
    if (head == nullptr or k == 0)
        return head;

    Node *temp = head;
    int i = 1;
    while (i != k and temp != nullptr)
    {
        temp = temp->next;
        i++;
    }

    if (temp != nullptr)
    {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;

        delete temp;
    }

    return head;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    // Node *head = new Node(v[0]);
    // Node *prev = head;

    // for (int i = 1; i < v.size(); i++)
    // {
    //     Node *temp = new Node(v[i]);
    //     temp->prev = prev;
    //     prev->next = temp;
    //     temp->next = nullptr;
    //     prev = temp;
    // }

    Node *head = convertArrToDD(v);

    // printList(head);
    head = deleteKth(head, 3);
    printList(head);

    return 0;
}