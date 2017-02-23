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
      cBaseTypeNode(string name, int size, bool isFloat ) : cDeclNode()
      {
          m_name = name;
          m_size = size;
          m_isFloat = isFloat;
      }

      //override GetName Virtual function from cDeclNode
      virtual cSymbol* GetName()
      {
        return static_cast<cSymbol* >(GetChild(1));
      }
      //override GetType Virtual function from cDeclNode
      virtual cDeclNode* GetType()
      {
        return (static_cast<cSymbol* >(GetChild(0)))->GetDecl();
      }

      virtual bool IsType() { return true; }
      virtual string NodeType() { return string("base_node"); }
      virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    protected:
      string m_name;
      int m_size;
      bool m_isFloat;

};
