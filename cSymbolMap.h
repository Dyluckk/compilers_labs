/*
// cSymbolMap.h
// Author: Zachary Wentworth
// Email: zachary.wentworth@oit.edu
// Date: 1.30.17
*/

#pragma once

#include "cSymbol.h"

#include <iostream>
#include <map>
#include <string>

using std::map;
using std::string;

class cSymbolMap
{
    public:
        cSymbolMap();
        cSymbol * Insert(string symbol);
        cSymbol * lookup(string symbol);
        cSymbolMap(const map<string, cSymbol*> & copy);
    protected:
        map<string, cSymbol*> mapSymbol;
};
