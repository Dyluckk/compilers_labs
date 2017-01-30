/*
// cSymbolMap.cpp
// Author: Zachary Wentworth
// Email: zachary.wentworth@oit.edu
// Date: 1.30.17
*/

#include "cSymbolMap.h"

//ctor
cSymbolMap::cSymbolMap() {
}

//copy ctor
cSymbolMap::cSymbolMap(const map<string, cSymbol*> & copy) {
    mapSymbol = copy;
}

//function used to look up symbols in within the table
cSymbol * cSymbolMap::lookup(string symbol) {
    //attempt to find the symbol in table
    map<string, cSymbol*>::iterator it = mapSymbol.find(symbol);

    // if not found, return nullptr
    if(it == mapSymbol.end()) {
        return nullptr;
    }
    // if found, return loaction
    else {
        return it->second;
    }
}

//function used to insert symbols into the table
cSymbol * cSymbolMap::Insert(string symbol) {
    cSymbol * insert = new cSymbol(symbol);

    //make a pair out of the string and cSymbol location
    std::pair<string,cSymbol*> mapSymbols (symbol, insert);

    //insert the pair
    mapSymbol.insert(mapSymbols);
    return insert;
}
