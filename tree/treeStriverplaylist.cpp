#include <bits/stdc++.h>
using namespace std;

//builder code
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d)
    {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};
TreeNode *builtTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return nullptr;
    }
    TreeNode *newNode = new TreeNode(d);

    newNode->left = builtTree();
    newNode->right = builtTree();
}
//builder code ends

void MorrisTraversal(TreeNode* root) {
    if(root == nullptr) return;
    TreeNode* curr = root;

    while(curr != nullptr) {
        if(curr->left == nullptr) {
            cout<<curr->data<<" ";
            curr = curr->right;
        }else {
            TreeNode* leftChild = curr->left;

            while(leftChild->right != nullptr) {
                leftChild = leftChild->right;
            }

            TreeNode* temp = curr;
            leftChild->right = curr;
            curr = curr->left;
            temp->left = nullptr;
        }
    }
}


int main()
{
    TreeNode* root = builtTree();
    MorrisTraversal(root);
    return 0;
}