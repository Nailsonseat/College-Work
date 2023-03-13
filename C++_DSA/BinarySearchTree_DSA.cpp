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
    int countChild(Node const *node) const
    {
        if (node->left != nullptr && node->right != nullptr)
            return 2;
        else if (node->left == nullptr && node->right == nullptr)
            return 0;
        else
            return 1;
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
    void deleteNode(int item)
    {
        Node *parent(root);
        Node *node(nullptr);
        if (parent->data == item)
        {
            node = parent;
            parent = nullptr;
        }
        traverse(item, parent, node, true);
        if (node == nullptr)
            return;
        if (countChild(node) == 0)
        {
            if (parent != nullptr)
            {
                if (parent->left != nullptr && parent->left->data == node->data)
                    parent->left = nullptr;
                else if (parent->right != nullptr && parent->right->data == node->data)
                    parent->right = nullptr;
            }
            delete node;
        }
        else if (countChild(node) == 1)
        {
            if (node->left != nullptr)
            {
                node->data = node->left->data;
                delete node->left;
                node->left = nullptr;
            }
            else
            {
                node->data = node->right->data;
                delete node->right;
                node->right = nullptr;
            }
        }
        else
        {
            int inOrderSucessor(-1);
            for (int i(0); i < inOrder.size(); i++)
                if (inOrder[i] == item)
                    inOrderSucessor = inOrder[i + 1];
            Node *inOrderSucessorNode(nullptr);
            traverse(inOrderSucessor, parent, inOrderSucessorNode, true);
            if (parent->left->data == inOrderSucessorNode->data)
            {
                parent->left = nullptr;
                node->data = inOrderSucessor;
                delete inOrderSucessorNode;
            }
            else
            {
                parent->right = nullptr;
                node->data = inOrderSucessor;
                delete inOrderSucessorNode;
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
    b.insert(8);
    b.insert(9);
    b.deleteNode(4);
    return 0;
}