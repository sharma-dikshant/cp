# Tree 

## Basic Tree Traversal

### Recusive Tree Traversal

- Preorder
- Inorder
- Postorder

### Iterative Tree Traversal

- [Preorder](#preorder-traversal-iterative-using-stack)
- [Inorder (using stack)](#inorder-traversal-using-stack)
- [Morris Traversal](#morris-traversal)
- Postorder
- Level Order

________________________________________________________

## Binary Tree Concepts  

- ### Height of Binary Tree or Depth of Binary Tree:  
    - Height of a binary tree is the number of edges on the longest path from the root node to the leaf node.  
    - Height of a binary tree with a single node is 0.  

- ### Balanced Binary Tree:  
    - A binary tree is balanced if the height of the left and right subtree of any node in the tree differ by not more than 1.
    `leftHeight - rightHeight <= 1`.  

- ### Diameter of Binary Tree:  
    - Number of edges in the longest path between two any nodes in a tree.

________________________________________________________

## Other Binary Tree Traversal: 

- Zigzag Level Order Traversal
- Vertical Order Traversal


## Conceptual Questions of Binary Tree: 
- [Check for balanced binary tree.](./balanceBinaryTree.cpp)
- Maximum Path Sum in Binary Tree.
- Check if two trees are identical.


# Codes:

## Preorder Traversal (Iterative using stack)
```cpp
void preOrder(TreeNode* root) {
    if(root == nullptr) return;

    stack<TreeNode* >st;
    auto curr = root;
    st.push(curr);

    while(!st.empty()) {
        auto t = st.top();

        cout<<t->data<<" ";
        if(t->right) st.push(t->right);
        if(t->left) st.push(t->left);
    }
}

```
## Inorder Traversal (using stack)
```cpp
void inOrder(TreeNode* root) {
    if(root == nullptr) return;

    stack<TreeNode*> st;
    TreeNode* curr = root;

    while(!st.empty() or curr != nullptr) {
        //traversing to left node and push into st
        while(curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        //if curr become null then print and pop the top elment and set curr to top's right
        cout<<st.top()->data<<" ";
        curr = st.top()->right;
        st.pop();
    }
}

```

## Morris Traversal
**Time Complexity** - O(n)  
**Space Complexity** - O(1)  
This traversal is based on the concept of **threaded binary tree**.

**Inorder Traversal:**
```cpp
TreeNode* curr = root;

while(curr != nullptr) {
    if(curr->left == nullptr) {
        cout<<curr->data<<" ";
        curr = curr->rightt;
    }else {
        TreeNode* leftChild = curr->left;

        while(leftChild->right != nullptr) {
            leftChild = leftChild->right;
        }

        leftChild->right = curr;
        TreeNode* temp = curr;

        curr = curr->left;
        temp->left = nullptr;
    }
}
```