#include<iostream>
#include <queue>
using namespace std;
// Following is the Binary Tree Node class structure

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{
    // Define the data members
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        // Implement the Constructor
        root = NULL;
    }

    /*----------------- Public Functions of BST -----------------*/

    BinaryTreeNode<int> *remove(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data < data)
        {
            root->right = remove(data, root->right);
            return root;
        }
        else if (root->data > data)
        {
            root->left = remove(data, root->left);
            return root;
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                return NULL;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                BinaryTreeNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                BinaryTreeNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = root->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                root->data = minNode->data;
                root->right = remove(minNode->data, root->right);
                return root;
            }
        }
    }

    void remove(int data)
    {
        // Implement the remove() function
        this->root = remove(data, root);
    }
    void print(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return;
        }

        cout << root->data << ":";
        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << ",";
        }
        if (root->right != NULL)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        print(root->left);
        print(root->right);
    }
    void print()
    {
        // Implement the print() function
        print(root);
    }

    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
            return node;
        }
        if (root->data < data)
        {
            root->right = insert(data, root->right);
        }
        else
        {
            root->left = insert(data, root->left);
        }

        return root;
    }
    void insert(int data)
    {
        // Implement the insert() function
        this->root = insert(data, root);
    }
    bool search(int data, BinaryTreeNode<int> *root)
    {
        // Implement the search() function
        if (root == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        else if (root->data < data)
        {
            return search(data, root->right);
        }
        else
        {
            return search(data, root->left);
        }
    }
    bool search(int data)
    {
        // Implement the search() function
        return search(data, root);
    }
};