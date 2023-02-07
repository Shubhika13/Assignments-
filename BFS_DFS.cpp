#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};
void preorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// Function to print node
void LevelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node *current = Q.front();
        Q.pop(); // Remove the elements from front
        cout << current->data << " ";
        if (current->left != NULL)
        {
            Q.push(current->left);
        }

        if (current->right != NULL)
        {
            Q.push(current->right);
        }
    }
}

// Function to insert Node
Node *insert(Node *root, char data)
{
    if (root == NULL)
    {
        root = new Node();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }

    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }

    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}



int main()
{
    Node *root = NULL;
    root = insert(root, 'M');
    root = insert(root, 'B');
    root = insert(root, 'Q');
    root = insert(root, 'Z');
    root = insert(root, 'A');
    root = insert(root, 'C');
    LevelOrder(root);
    cout << '\n';
    preorder(root);
    cout << '\n';
    return 0;
}