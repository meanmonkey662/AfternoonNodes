//
//  CTECBinaryTree.cpp
//  AfternoonNodes
//
//  Created by Koch, Kyle on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "TreeNode.hpp"
namespace CTECData
{
    template<class Type>
    class CTECBindaryTree
    {
    private:
        int size;
        TreeNode<Type> * root;
        int height;
        bool balanced;
        bool contains(Type value, CTECBindaryTree<Type> * currentTree);
    public:
        CTECBindaryTree();
        ~CTECBindaryTree();
        bool insert(const Type& value);
        Type remove(const Type& value);
        bool contains(Type value);
        int getSize();
        int getHeight();
        bool isBalanced();
        TreeNode<Type> * getRoot();
        
    };
}