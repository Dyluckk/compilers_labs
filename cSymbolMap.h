/*
// cSymbolMap.h
// Author: Zachary Wentworth
// Email: zachary.wentworth@oit.edu
// Date: 1.30.17
*/

#pragma once

#include "cSymbol.h"

#include <iostream>
#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

class cSymbolMap
{
    public:
        cSymbolMap();
        cSymbolMap(const unordered_map<string, cSymbol*> & copy);
        cSymbol * Insert(string symbol);
        cSymbol * lookup(string symbol);
    protected:
        unordered_map<string, cSymbol*> mapSymbol;
};
