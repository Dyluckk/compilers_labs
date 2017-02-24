//**************************************
// cBaseTypeNode.h
//
// Defines an AST node for an binary expressions.
//
// Inherits from cExprNode so that binary expressions can be used in those type of
// expressions
//
// Author: Zachary Wentworth
// zachary.wentworth@oit.edu
//
// Date: Feb. 9, 2017
//
#pragma once

#include "cAstNode.h"
#include "cDeclNode.h"

class cBaseTypeNode : public cDeclNode
{
    public:
      cBaseTypeNode(string name, int size, bool isFloat );
      //override GetName Virtual function from cDeclNode
      virtual cSymbol* GetName();
      //override GetType Virtual function from cDeclNode
      virtual cDeclNode* GetType();
      virtual bool IsType();
      virtual string NodeType();
      virtual void Visit(cVisitor *visitor);
    protected:
      string m_name;
      int m_size;
      bool m_isFloat;
};
