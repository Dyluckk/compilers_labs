/*
// cSymbolTable.h
// Author: Zachary Wentworth
// Email: zachary.wentworth@oit.edu
// Date: 1.30.17
*/

#pragma once

#include "cSymbol.h"
#include "cSymbolMap.h"

#include <iostream>
#include <unordered_map>
#include <list>
#include <string>

using std::unordered_map;
using std::list;
using std::string;

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
