/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: kkoc6943
 */

#include "CTECList.h"

template<class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;

}

template<class Type>
CTECList<Type>::~CTECList()
{
	// TODO Auto-generated destructor stub
}

template<class Type>
Type CTECList<Type> :: removeFromFront()
{
	assert(this->size > 0);

	Type thingToRemove;
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = this->head->getNext();
	thingToRemove = this->head->getValue();
	this->head = newHead;

	size--;

	return thingToRemove;
}

template<class Type>
Type CTECList<Type> :: removeFromEnd()
{
	/**
	 * check size is valid
	 * create a return variable
	 * loop until the next to last Node
	 * grab the value from the last node
	 * delete the last node
	 * set new last node as the end
	 */
	assert(size>0);

	Type returnValue;

	if(size ==1)
	{
		ArrayNode * toRemove = end;
		returnValue = removeFromFront();
		end = nullptr;
		head = nullptr;
		delete toRemove;
	}
	else
	{
		ArrayNode<Type> * current = head;
		for(int index = 0; index < size - 1; index++)
		{
			current = current->getNext();
		}
		returnValue = end->getValue();
		delete end;
		current = end;
		current->setNext(nullptr);
	}

	calculatedSize();

	return returnValue;
}

template<class Type>
Type CTECList<Type> :: removeFromIndex(int index)
{
	assert(this->size > 0);
	assert(index >= 0 && index < size);

	Type thingToRemove;

	//Array<Type> * previous, deleteMe, newNext;

	if(index == 0)
	{
		thingToRemove = removeFromFront();
	}
	else if(index == size-1)
	{
		thingToRemove = removeFromEnd();
	}
	else
	{
		for(int spot =0; spot < index+1; spot++)
		{

		}
	}

}

template<class Type>
	void CTECList<Type> :: calculateSize()
	{
		assert(size >= 0);

		int count = 0;
		if(head == nullptr)
		{
			size = count;
		}
		else
		{
			count++;
			ArrayNode<Type> * current = head;
			while(current->getNext() !=nullptr)
			{
				count++;
				current = current->getNext();
			}
			size = count;
		}

	}
/*
 1. check that the array exists
 2. point to head.
 3. loop over nodes until value is found
 4. return index or -1 if not found.
 */
template<class Type>
int CTECArray<Type> :: indexOff(Type searchValue)
{
    assert(this->size > 0)
    
    ArrayNode<Type> * current = head;
    int indexNotFound = -1;
    
    for(int index = 0; index < this->size; index++)
    {
        if(current->getValue() == searchValue)
        {
            return index;
        }
        else
        {
            current = current->getValue();
        }
    }
    return indexNotFound;
}

template <class Type>
int CTECList<Type> :: indexOf(Type searchValue)
{
    assert(this->size >0);
    
    int index;
    
    ArrayNode<Type> * searchPointer;
    
    for(searchPointer = head; searchPointer != nullptr; searchPointer = searchPointer->getNext())
    {
        if(searchValue == searchPointer->getValue())
        {
            return index;
        }
        index++;
    }
    index = -1;
    return index;
}

template <class Type>
void CTECList<Type> :: swap(int indexOne, int indexTwo)
{
    assert(indexOne < size && indexTwo < size);
    
    Type temp = get(indexOne);
    set(indexOne, get(indexTwo));
    set(indexTwo, temp);
}

template <class Type>
void CTECList<Type> :: selectionSort()
{
    for(int outerLoop = 0; outerLoop < size -1; outerLoop++)
    {
        int selectedMinimum = outerLoop;
        
        for(int innerLoop = outerLoop +1; innerLoop < size; innerLoop++)
        {
            if(getFromIndex(innerLoop) < getFromIndex(selectedMinimum))
            {
                selectedMinimum = innerLoop;
            }
        }
        
        if(selectedMinimum != outerLoop)
        {
            swap(selectedMinimum, outerLoop);
        }
    }
}



