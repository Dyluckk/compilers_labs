//**************************************
// cParamListNode.h
//
// Defines an AST node for param lists
//
// Inherits from cExprNode
//
// Author: Zachary Wentworth
// zachary.wentworth@oit.edu
//
// Date: Feb. 9, 2017
//
#pragma once

#include "cAstNode.h"
#include "cSymbol.h"

class cParamListNode : public cAstNode
{
    public:
        cParamListNode(cExprNode * multiple) : cAstNode()
        {
            AddChild(multiple);
        }

        void Insert(cExprNode * child){
            AddChild(child);
        }

        cExprNode* GetExpr(int num)
        {
           return static_cast<cExprNode *>(GetChild(num));
        }

        int GetNumParams()
        {
          return this->NumChildren();
        }

        virtual string NodeType() { return string("params"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
