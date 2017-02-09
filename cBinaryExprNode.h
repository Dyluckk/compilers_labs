#pragma once
//**************************************
// cFloatExprNode.h
//
// Defines an AST node for an float constant (literals).
//
// Inherits from cExprNode so that integer constants can be used anywhere
// expressions are used.
//
// Author: Zachary Wentworth
// zachary.wentworth@oit.edu
//
// Date: Feb. 9, 2017
//

#include "cAstNode.h"
#include "cExprNode.h"

class cBinaryExprNode : public cExprNode
{
    public:
        // param is the value of the integer constant
        cBinaryExprNode(cExprNode * Left, cOpNode * operation, cExprNode * Right) : cExprNode()
        {
            AddChild(Left);
            AddChild(operation);
            AddChild(Right);
        }

        virtual string NodeType() { return string("expr"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
