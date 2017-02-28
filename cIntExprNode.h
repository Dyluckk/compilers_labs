// **************************************

// cIntExprNode.h
//
// Defines an AST node for an integer constant (literals).
//
// Inherits from cExprNode so that integer constants can be used anywhere
// expressions are used.
//
// Author: Zachary Wentworth
// zachary.wentworth@oit.edu
//
// Date: Feb. 9, 2017
//
#pragma once

#include "cAstNode.h"
#include "cExprNode.h"

class cIntExprNode : public cExprNode {
public:

  cIntExprNode(int value) : cExprNode()
  {
    m_value = value;
  }

  virtual cDeclNode* GetType()
  {
    return g_SymbolTable.Find("int")->GetDecl();
  }

  virtual string AttributesToString()
  {
    return " value=\"" + std::to_string(m_value) + "\"";
  }

  virtual string NodeType()
  {
    return string("int");
  }

  virtual void Visit(cVisitor *visitor)
  {
    visitor->Visit(this);
  }

  virtual bool IsInt()
  {
    return true;
  }

protected:

  int m_value; // value of integer constant (literal)
};
