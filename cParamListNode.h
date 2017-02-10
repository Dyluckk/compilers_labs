#pragma once
//**************************************
// cVarDeclNode.h
//
// Defines an AST node for an variable declerations
//
// Inherits from cDeclsNode
//
// Author: Zachary Wentworth
// zachary.wentworth@oit.edu
//
// Date: Feb. 9, 2017
//

#include "cAstNode.h"
#include "cExprNode.h"
#include "cSymbol.h"

class cParamListNode : public cExprNode
{
    public:
        // param is the value of the integer constant
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
