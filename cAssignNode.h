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

        //get LHS
        cVarExprNode * GetLHS()
        {
          return static_cast<cVarExprNode*>(GetChild(0));
        }

        //get RHS
        cExprNode * GetRHS()
        {
          return static_cast<cExprNode*>(GetChild(1));
        }

        virtual cSymbol* GetName()
        {
          return static_cast<cSymbol *>(GetChild(0));
        }

        virtual string NodeType() { return string("assign"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

};
