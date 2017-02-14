//**************************************
// cParamListNode.h
//
// Defines an AST node for param lists
//
// Inherits from cExprNode
//
// Author: Zachary Wentworth
// zachary.wentworth@oit.edu
//
// Date: Feb. 9, 2017
//
#pragma once

#include "cAstNode.h"
#include "cExprNode.h"
#include "cSymbol.h"

class cParamListNode : public cExprNode
{
    public:
        cParamListNode(cExprNode * multiple) : cExprNode()
        {
            AddChild(multiple);
        }

        void Insert(cExprNode * child){
            AddChild(child);
        }

        virtual string NodeType() { return string("params"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
