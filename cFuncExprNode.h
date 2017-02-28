// **************************************

// cFuncExprNode.h
//
// Defines an AST node for function expressions
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
#include "cExprNode.h"
#include "cParamsNode.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cParamListNode.h"

class cFuncExprNode : public cExprNode {
public:

  cFuncExprNode(cSymbol *type, cParamListNode *name) : cExprNode(), m_funcDecl(type->GetDecl())
  {
    // m_funcDecl = type->GetDecl();
    AddChild(type);
    AddChild(name);
  }

  void Insert(cParamListNode *list)
  {
    AddChild(list);
  }

  virtual cDeclNode* GetType() {
    return m_funcDecl->GetType();
  }

  cParamListNode* GetParams()
  {
    return static_cast<cParamListNode*>(GetChild(1));
  }

  cFuncDeclNode* GetFuncDecl()
  {
    return static_cast<cFuncDeclNode*>(GetName()->GetDecl());
  }

  virtual cSymbol* GetName()
  {
    return static_cast<cSymbol *>(GetChild(0));
  }

  virtual string NodeType() {
    return string("funcCall");
  }

  virtual void Visit(cVisitor *visitor) {
    visitor->Visit(this);
  }

protected:

  cDeclNode* m_funcDecl;
};
