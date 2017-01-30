/*
// cSymbolTable.cpp
// Author: Zachary Wentworth
// Email: zachary.wentworth@oit.edu
// Date: 1.30.17
*/

#include "cSymbolTable.h"
#include "cSymbolMap.h"

//function used to create an new empty symbol table and push it onto the map list on scope change
void cSymbolTable::IncreaseScope() {
    cSymbolMap map;
    mapList.push_front(map);
}

//function used to change the default table on scope change
void cSymbolTable::DecreaseScope() {
    mapList.pop_front();
}

cSymbol* cSymbolTable::Insert(string symbol) {
    // check if the symbol exists in the current table
    cSymbol* var = mapList.front().lookup(symbol);

    // inser symbol, if it does not exist
    if(var == nullptr) {
        return mapList.front().Insert(symbol);
    }
    // return the symbol, if it does exist
    else {
        return var;
    }
}
