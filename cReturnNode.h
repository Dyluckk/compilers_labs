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
#include "cStmtNode.h"
#include "cExprNode.h"

class cReturnNode : public cStmtNode
{
    public:
        // param is the value of the integer constant
        cReturnNode(cExprNode * expr) : cStmtNode()
        {
            AddChild(expr);
        }

        virtual string NodeType() { return string("return"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
