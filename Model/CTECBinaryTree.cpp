//
//  CTECBinaryTree.cpp
//  AfternoonNodes
//
//  Created by Koch, Kyle on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECBinaryTree.hpp"
using namespace CTECData;
using namespace std;

namespace CTECData
{
    
template <class Type>
CTECBinaryTree<Type> :: CTECBinaryTree()
    {
        this->root = nullptr;
        this->size = 0;
        this->height = 0;
        this->balanced = true;
    }
    
template <class Type>
int CTECBinaryTree<Type> :: getSize()
    {
        size = 0;
        calculatedSize(root);
        return size;
    }
    
template <class Type>
void CTECBinaryTree<Type> :: preorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        cout << currentNode->getValue() << " " ;
        preorderTransversal(currentNode->getLeftChild());
        preorderTransversal(currentNode->getRightChild());
    }
}

template <class Type>
void CTECBinaryTree<Type> :: inorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        inorderTransversal(currentNode->getLeftChild());
        cout << currentNode->getValue() << " " ;
        inorderTransversal(currentNode->getRightChild());
    }
}

template <class Type>
void CTECBinaryTree<Type> :: postorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        postorderTransversal(currentNode->getLeftChild());
        postorderTransversal(currentNode->getRightChild());
        cout << currentNode->getValue() << " " ;
    }
}
}

template <class Type>
bool CTECBinaryTree<Type> :: contains(Type value)
{
    bool isInTree = false;
    
    if(root != nullptr)
    {
        if(root->getValue() == value)
        {
            isInTree = true;
        }
        else
        {
            if(value < root->getValue())
            {
                isInTree = contains(value, root->getLeftChild());
            }
            else
            {
                isInTree = contains(value, root->getRightChild());
            }
        }
    }
    
    return isInTree;
}

template <class Type>
bool CTECBinaryTree<Type> :: contains(Type value, CTECBinaryTree<Type> * currentTree)
{
    bool isInTree = false;
    
    if(currentTree != nullptr)
    {
        if(currentTree->getRoot()->getValue() == value)
        {
            isInTree = contains(value, currentTree->getRoot()->getLeftChild());
        }
        else
        {
            isInTree = contains(value, currentTree->getRoot()->getRightChild());
        }
    }
    
    return isInTree;
}

template <class Type>
void CTECBinaryTree<Type> :: remove(const Type& value)
{
    TreeNode<Type> * current;
    TreeNode<Type> * trailing;
    
    if(!contains(value))
    {
        return;
    }
    else
    {
        current = root;
        trailing = root;
        
        while(current != nullptr && current->getValue() != value)
        {
            trailing = current;
            if(current->getValue() > value)
            {
                current = current->getLeftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
        if(current == root)
        {
            remove(root);
        }
        else if(trailing->getValue() > value)
        {
            remove(trailing->getLeftChild());
        }
        else
        {
            remove(trailing->getRightChild());
        }
    }
}

template <class Type>
void CTECBinaryTree<Type> :: remove(TreeNode<Type> * nodeToBeRemoved)
{
    TreeNode<Type> * current;
    TreeNode<Type> * trailing;
    TreeNode<Type> * temp;
    
    if(nodeToBeRemoved == nullptr)
    {
        cerr << "OOps! Cant remove something that isnt there." << endl;
    }
    else if(nodeToBeRemoved->getLeftChild() == nullptr &&
            nodeToBeRemoved->getRightChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = nullptr;
        delete temp;
    }
    else if (nodeToBeRemoved->getLeftChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = temp->getRightChild();
        delete temp;
    }
    else if (nodeToBeRemoved->getRightChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = temp->getLeftChild();
        delete temp;
    }
    else
    {
        current = nodeToBeRemoved->getLeftChild();
        trailing = nullptr;
        
        while(current->getRightChild() != nullptr)
        {
            trailing = current;
            current = current->getRightChild();
        }
        
        nodeToBeRemoved->setValue(current->getValue());
        
        if(trailing == nullptr)
        {
            nodeToBeRemoved->setLeftChild(getLeftChild());
        }
        else
        {
            trailing->setRightChild(current->getLeftChild());
        }
        delete current;
    }

}
