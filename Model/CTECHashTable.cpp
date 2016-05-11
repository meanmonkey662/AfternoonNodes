//
//  CTECHashTable.cpp
//  AfternoonNodes
//
//  Created by Koch, Kyle on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include <iostream>
#include "CTECHashTable.hpp"
#include <cmath>

using namespace CTECData;
using namespace std;

template <class Type>
CTECHashTable<Type> :: CTECHashTable()
{
    this->size = 0;
    this->capacity = 101;
    this->efficiencyPercentage = .677;
    this->internalStorage = new HashNode<Type>[capacity];
    
    this->chainedSize = 0;
    this->chainedCapacity = 101;
    this->chainedStorage = new CTECList<HashNode <Type>>[chainedCapacity];
}

template <class Type>
CTECHashTable<Type> :: ~CTECHashTable()
{
    delete [] internalStorage;
    delete [] chainedStorage;
}

template <class Type>
int CTECHashTable<Type> :: getSize()
{
    return this->size;
}

template <class Type>
void CTECHashTable<Type> :: addChained(HashNode<Type> currentNode)
{
    if((chainedSize/chainedCapacity) >= efficiencyPercentage)
    {
        updateChainedCapacity();
    }
    int insertionIndex = findPosition(currentNode);
    
    if(chainedStorage[insertionIndex] != nullptr)
    {
        CTECList<HashNode<Type>> temp = chainedStorage[insertionIndex];
        temp.addEnd(currentNode);
    }
    else
    {
        CTECList<HashNode<Type>> tempList;
        tempList.addEnd(currentNode);
        chainedStorage[insertionIndex] = tempList;
    }
       
    chainedSize++;
}

template <class Type>
void CTECHashTable<Type> :: add(HashNode<Type> currentNode)
{
    if(!contains(currentNode))
    {
        if(size/capacity >= this->efficiencyPercentage)
        {
            updateCapacity();
        }
        int insertionIndex = findPosition(currentNode);
        
        if(internalStorage[insertionIndex] != nullptr)
        {
            while (internalStorage[insertionIndex] != nullptr)
            {
                insertionIndex = insertionIndex + 1 % capacity;
            }
        }
        
        internalStorage[insertionIndex] = currentNode;
    }
}

template <class Type>
int CTECHashTable<Type> :: findPosition(HashNode<Type> currentNode)
{
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
}

template <class Type>
int CTECHashTable<Type> :: getNextPrime()
{
    int nextPrime = capacity;
    
    nextPrime *= 2;
    nextPrime++;
    
    while(!isPrime(nextPrime))
    {
        nextPrime += 2;
    }
    
    return nextPrime;
}

template <class Type>
bool CTECHashTable<Type> :: isPrime(int canidateNumber)
{
    bool isPrime = true;
    
    if(canidateNumber <=1)
    {
        isPrime = false;
    }
    else if(canidateNumber == 2 || canidateNumber == 3)
    {
        isPrime = true;
    }
    else if(canidateNumber % 2 == 0)
    {
        isPrime = false;
    }
    else
    {
        for(int spot = 3; spot < sqrt(canidateNumber) +1; spot += 2)
        {
            if(canidateNumber % spot == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
}

template<class Type>
void CTECHashTable<Type> :: updateCapacity()
{
    int updateCapacity = getNextPrime();
    int oldCapacity = capacity;
    capacity = updateCapacity;
    
    HashNode<Type> * largerStorage = new HashNode<Type>[capacity];
    
    for(int index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updateIndex = findPosition(internalStorage[index]);
            largerStorage[updateIndex] = internalStorage[index];
        }
    }
    
    internalStorage = largerStorage;
}


template <class Type>
bool CTECHashTable<Type> :: contains(HashNode<Type> currentNode)
{
    bool isInTable = false;
    int possibleLocation = findPosition(currentNode);
    
    while(internalStorage[possibleLocation] != nullptr && !isInTable)
    {
        if(internalStorage[possibleLocation].getValue() == currentNode.getValue())
        {
            isInTable = true;
        }
        possibleLocation = (possibleLocation + 1) % capacity;
    }
    
    return isInTable;
}


template <class Type>
int CTECHashTable<Type> :: handleCollision(HashNode<Type> currentNode)
    {
        int updatedPosition = findPosition(currentNode);
        
        updatedPosition = ( + ( updatedPosition * updatedPosition)) % capacity;
        
        return updatedPosition;
    }








