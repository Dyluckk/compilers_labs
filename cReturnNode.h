#pragma once
//**************************************
// cReturnNode.h
//
// Defines AST node for a lang return statement
//
// Author: Phil Howard
// zachary.wentworth@oit.edu
//
// Date: Feb. 18, 2017
//


#include "cAstNode.h"
#include "cStmtNode.h"
#include "cExprNode.h"

class cReturnNode : public cStmtNode
{
    public:
        cReturnNode(cExprNode *expr)
        {
            AddChild(expr);
        }
        cExprNode * GetExpr() { return static_cast<cExprNode *>(GetChild(0)); }
        virtual string NodeType() { return string("return"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
