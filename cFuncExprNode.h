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
#include "cParamsNode.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cParamListNode.h"

class cFuncExprNode : public cExprNode
{
    public:
        // param is the value of the integer constant
        cFuncExprNode(cSymbol * type, cParamListNode * name) : cExprNode()
        {
            AddChild(type);
            AddChild(name);
        }

        //inserts any param list for any function
    		void Insert(cParamListNode * list)
    		{
    			AddChild(list);
    		}

        virtual string NodeType() { return string("funcCall"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
