#pragma once
//**************************************
// cStmtNode.h
//
// Defines abstract class for a single statment
//
// NOTE: all statement types must inherit from this class
//
// Author: Phil Howard 
// zachary.wentworth@oit.edu
//
// Date: Jan. 18, 2016
//

#include "cAstNode.h"

class cStmtNode : public cAstNode
{
    public:
        cStmtNode() : cAstNode() {}
};
