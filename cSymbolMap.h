#pragma once

/*
// cSymbolMap.h
// Author: Zachary Wentworth
// Email: zachary.wentworth@oit.edu
// Date: 1.30.17 
*/

#include <iostream>
#include "cSymbol.h"

using namespace std;
#include <map>
#include <string>

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
