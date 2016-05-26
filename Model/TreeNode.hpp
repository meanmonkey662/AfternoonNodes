//
//  TreeNode.hpp
//  AfternoonNodes
//
//  Created by Koch, Kyle on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//


#ifndef MODEL_TREENODE_H_
#define MODEL_TREENODE_H_
#include "Node.h"

namespace CTECData
{
    template<class Type>
    class TreeNode: public Node<Type>
    {
    public:
        TreeNode();
        TreeNode(const Type& value);
        TreeNode(const Type& value, TreeNode<Type> * parent);
        
        void setLeftChild(TreeNode<Type> * leftChild);
        void setRightChild(TreeNode<Type> * rightChild);
        void setParent(TreeNode<Type> * parent);
        
        TreeNode<Type> * getLeftChild();
        TreeNode<Type> * getRightChild();
        TreeNode<Type> * getParent();
        
    private:
        TreeNode<Type> * leftChild;
        TreeNode<Type> * rightChild;
        TreeNode<Type> * parent;
    };
}
#endif /* MODEL_TREENODE_H_ */