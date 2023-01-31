#include <iostream>

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
    void traverseTill(int item, Node *&parent, Node *&child, bool insert)
    {
        if (!insert)
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
            traverseTill(item, parent, child, insert);
        }
        else if (parent->right != nullptr)
        {
            parent = parent->right;
            traverseTill(item, parent, child, insert);
        }
    }

public:
    void insert(int item)
    {
        Node *parent(root);
        Node *child(nullptr);
        if (root == nullptr)
        {
            root = new Node;
            root->data = item;
        }
        else
        {
            traverseTill(item, parent, child, true);
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