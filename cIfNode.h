//**************************************
// cIfNode.h
//
// Defines an AST node for an  if node
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
#include "cStmtsNode.h"
#include "cExprNode.h"

class cIfNode : public cStmtNode
{
    public:
        cIfNode(  cExprNode * expr, cStmtsNode * ifStmt, cStmtsNode * elseStmt ) : cStmtNode()
        {
            AddChild(expr);
            AddChild(ifStmt);
            AddChild(elseStmt);
        }

        cIfNode( cExprNode * expr, cStmtsNode * ifStmt ) : cStmtNode()
        {
            AddChild(expr);
            AddChild(ifStmt);
        }

        virtual string NodeType() { return string("if"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
