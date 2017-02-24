// **************************************

// cBinaryExprNode.h
//
// Defines an AST node for an binary expressions.
//
// Inherits from cExprNode so that binary expressions can be used in those type
// of
// expressions
//
// Author: Zachary Wentworth
// zachary.wentworth@oit.edu
//
// Date: Feb. 9, 2017
//
#pragma once

#include "cAstNode.h"
#include "cExprNode.h"

class cBinaryExprNode : public cExprNode {
public:

  // param is the value of the integer constant
  cBinaryExprNode(cExprNode *Left, cOpNode *operation, cExprNode *Right) : cExprNode()
  {
    AddChild(Left);
    AddChild(operation);
    AddChild(Right);
  }

  virtual cDeclNode* GetType()
  {
    return nullptr;
  }

  virtual string NodeType() {
    return string("expr");
  }

  virtual void Visit(cVisitor *visitor) {
    visitor->Visit(this);
  }
};
