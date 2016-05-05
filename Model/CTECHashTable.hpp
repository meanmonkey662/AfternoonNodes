//
//  CTECHashTable.hpp
//  AfternoonNodes
//
//  Created by Koch, Kyle on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECHashTable_hpp
#define CTECHashTable_hpp

namespace CTECData
{
    template <class Type>
    class CTECHashTable
    {
    private:
        int size;
        int capacity;
        Type * internalStorage;
        double efficiencyPercentage;
        
        int findPosition(const Type& value);
        int handleCollision(const Type& value);
        void updateSize();
    public:
        CTECHashTable();
        ~CTECHashTable();
        
        void add(const Type & value);
        bool remove(const Type & value);
        bool contains(const Type & value);
        int getSize();
        
    };
}
#include <stdio.h>

#endif /* CTECHashTable_hpp */
