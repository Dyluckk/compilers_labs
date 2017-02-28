// **************************************

// cFloatExprNode.h
//
// Defines an AST node for an float constant (literals).
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

class cFloatExprNode : public cExprNode {
public:

  // param is the value of the integer constant
  cFloatExprNode(double value) : cExprNode()
  {
    m_value = value;
  }

  virtual cDeclNode* GetType()
  {
    return g_SymbolTable.Find("float")->GetDecl();
  }

  virtual string AttributesToString()
  {
    return " value=\"" + std::to_string(m_value) + "\"";
  }

  virtual string NodeType()
  {
    return string("float");
  }

  virtual void Visit(cVisitor *visitor)
  {
    visitor->Visit(this);
  }

  virtual bool IsFloat()
  {
    return true;
  }

protected:

  double m_value; // value of float constant (literal)
};
