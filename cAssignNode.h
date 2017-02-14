//**************************************
// cAssignNode.h
//
// Defines an AST node for assignments
//
// Inherits from cStmtNode
//
// Author: Zachary Wentworth
// zachary.wentworth@oit.edu
//
// Date: Feb. 9, 2017
//
#pragma once

#include "cAstNode.h"
#include "cStmtNode.h"
#include "cVarExprNode.h"

class cAssignNode : public cStmtNode
{
    public:
        cAssignNode( cVarExprNode * varExpr, cExprNode * expr ) : cStmtNode()
        {
            AddChild(varExpr);
            AddChild(expr);
        }

        virtual string NodeType() { return string("assign"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
