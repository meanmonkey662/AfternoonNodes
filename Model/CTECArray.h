/*
 * CTECArray.h
 *
 *  Created on: Feb 2, 2016
 *      Author: kkoc6943
 */

#ifndef MODEL_CTECARRAY_H_
#define MODEL_CTECARRAY_H_

#include "ArrayNode.h"

template <class Type>
class CTECArray
{
private:
	int size;
	ArrayNode<Type> * head;
public:
	CTECArray(int size);
	virtual ~CTECArray();
	int getSize();
	void set(int position, const Type& value);
	Type get(int position);
    void swap(int indexOne, int indexTwo);
    void selectionSort();
    
};

#endif /* MODEL_CTECARRAY_H_ */
