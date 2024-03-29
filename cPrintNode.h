#pragma once
//**************************************
// cPrintNode.h
//
// Defines AST node for print statements
//
// Inherits from cStmtNode so print statments can go in statement lists, and be
// used anywhere a statement is legal.
//
// Author: Phil Howard
// zachary.wentworth@oit.edu
//
// Date: Jan. 18, 2016
//

#include "cAstNode.h"
#include "cStmtNode.h"
#include "cExprNode.h"

class cPrintNode : public cStmtNode
{
    public:
        // param is the value to be printed
        cPrintNode(cExprNode *expr) : cStmtNode()
        {
            AddChild(expr);
        }
        cExprNode * GetExpr() { return static_cast<cExprNode *>(GetChild(0)); }
        virtual string NodeType() { return string("print"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
