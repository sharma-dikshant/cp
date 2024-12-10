#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *buildTree()
{
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *n = new Node(data);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

void printPreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void printPostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

void printLevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        if (temp == NULL)
        {
            cout << endl;
            q.pop();

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return;
}

Node *buildLevelOrderTree()
{
    int data;
    cin >> data;
    Node *root = new Node(data);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        int d1, d2;
        cin >> d1 >> d2;

        if (d1 != -1)
        {
            curr->left = new Node(d1);
            q.push(curr->left);
        }
        if (d2 != -1)
        {
            curr->right = new Node(d2);
            q.push(curr->right);
        }
    }

    return root;
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}
int main()
{
    // Node *root = buildTree();
    // printPreOrder(root);
    // cout << endl;
    // printInOrder(root);
    // cout << endl;
    // printPostOrder(root);

    Node *root = buildLevelOrderTree();
    printLevelOrder(root);
    return 0;
}