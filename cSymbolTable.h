#pragma once

#include <iostream>
#include "cSymbol.h"
#include "cSymbolMap.h"

using namespace std;
#include <map>
#include <list>
#include <string>

/*
// cSymbolTable.h
// Author: Zachary Wentworth
// Email: zachary.wentworth@oit.edu
// Date: 1.30.17
*/

class cSymbolTable
{
    public:
        void IncreaseScope();
        void DecreaseScope();
        cSymbol * Insert(string symbol);
        cSymbol * lookup(string symbol);
    protected:
        list<cSymbolMap> mapList;
};
