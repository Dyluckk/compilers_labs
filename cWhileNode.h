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
#include "cStmtsNode.h"
#include "cExprNode.h"

class cWhileNode : public cStmtNode
{
    public:
        cWhileNode(  cExprNode * expr, cStmtNode * stmt ) : cStmtNode()
        {
            AddChild(expr);
            AddChild(stmt);
        }

        virtual string NodeType() { return string("while"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};