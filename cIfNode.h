#pragma once
//**************************************
// cIfNode.h
//
// Defines AST node for an if statement
//
// Inherits from cStmtNode so that if statements can be included in lists of
// statements
//
// Author: Phil Howard
// zachary.wentworth@oit.edu
//
// Date: Jan. 18, 2016
//

#include "cAstNode.h"
#include "cStmtNode.h"
#include "cExprNode.h"

class cIfNode : public cStmtNode
{
    public:
        // params are the condition, the list of statments for the if part,
        // and the list of statements for the else part. The else part can
        // be nullptr
        cIfNode(cExprNode *cond, cStmtsNode *ifStmt, cStmtsNode *elseStmt)
        {
            AddChild(cond);
            AddChild(ifStmt);
            AddChild(elseStmt);
        }

        cExprNode * GetCond()
        {
            return static_cast<cExprNode *>(GetChild(0));
        }

        cStmtsNode * GetIf()
        {
            return static_cast<cStmtsNode *>(GetChild(1));
        }

        cStmtsNode * GetElse()
        {
            return static_cast<cStmtsNode *>(GetChild(2));
        }
        virtual string NodeType() { return string("if"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
