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
#include "cDeclNode.h"
#include "cSymbol.h"

class cParamsNode : public cDeclNode
{
    public:
        // param is the value of the integer constant
        cParamsNode(cDeclNode * multiple ) : cDeclNode()
        {
            AddChild(multiple);
        }

        void Insert(cDeclNode * child){
            AddChild(child);
        }

        virtual string NodeType() { return string("args"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
