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
