// **************************************

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
#pragma once

#include "cAstNode.h"
#include "cDeclNode.h"
#include "cExprNode.h"

class cVarExprNode : public cExprNode {
public:

  cVarExprNode(cSymbol *val) : cExprNode()
  {
    AddChild(val);
  }

  virtual string NodeType()
  {
    return string("varref");
  }

  virtual void Visit(cVisitor *visitor)
  {
    visitor->Visit(this);
  }

  void Insert(cSymbol *var)
  {
    AddChild(var);
  }
};
