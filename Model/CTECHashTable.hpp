//
//  CTECHashTable.hpp
//  AfternoonNodes
//
//  Created by Koch, Kyle on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECHashTable_hpp
#define CTECHashTable_hpp
#include <set>
#include <stdio.h>
#include "HashNode.cpp"
#include "CTECList.cpp"


namespace CTECData {

    

    template <class Type>
    
    class CTECHashTable
    
    {
        
    private:
        int size;
        int capacity;
        int chainedCapacity;
        int chainedSize;
        CTECList <HashNode<Type>> * chainedStorage;
        void updateChainedCapacity();
        HashNode<Type> * internalStorage;
        double efficiencyPercentage;
        int findPosition(HashNode<Type> currentNode);
        int handleCollision(HashNode<Type> currentNode);
        void updateSize();
        int getNextPrime();
        bool isPrime(int candidateNumber);
        void updateCapacity();
        
    public:
        CTECHashTable();
        ~CTECHashTable();
        void addChained(HashNode<Type> currentNode);
        void add(HashNode<Type> currentNode);
        bool remove(HashNode<Type> currentNode);
        bool contains(HashNode<Type> currentNode);
        int getSize();
    };
}
#endif /* CTECHashTable_hpp */