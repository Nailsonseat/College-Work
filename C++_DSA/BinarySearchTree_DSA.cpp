#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
};

class BST
{
    Node *root = nullptr;
    vector<int> inOrder;
    void traverse(int item, Node *&parent, Node *&child, bool toDelete)
    {
        if (toDelete)
        {
            if (parent->left != nullptr && parent->left->data == item)
                child = parent->left;
            else if (parent->right != nullptr && parent->right->data == item)
                child = parent->right;
            if (child != nullptr)
                return;
        }
        if (item < parent->data && parent->left != nullptr)
        {
            parent = parent->left;
            traverse(item, parent, child, toDelete);
        }
        else if (item >= parent->data && parent->right != nullptr)
        {
            parent = parent->right;
            traverse(item, parent, child, toDelete);
        }
    }

public:
    void getInOrder(Node *node)
    {
        if (node->left != nullptr)
            getInOrder(node->left);
        inOrder.push_back(node->data);
        if (node->right != nullptr)
            getInOrder(node->right);
    }
    void insert(int item)
    {
        inOrder.clear();
        Node *parent(root);
        Node *child(nullptr);
        if (root == nullptr)
        {
            root = new Node;
            root->data = item;
        }
        else
        {
            traverse(item, parent, child, false);
            if (item < parent->data)
            {
                parent->left = new Node;
                parent->left->data = item;
            }
            else
            {
                parent->right = new Node;
                parent->right->data = item;
            }
        }
        getInOrder(root);
    }
};

int main()
{
    BST b;
    b.insert(6);
    b.insert(4);
    b.insert(6);
    b.insert(1);
    b.insert(2);
    b.insert(5);
    return 0;
}