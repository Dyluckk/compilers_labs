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

  virtual cSymbol* GetName()
  {
    return static_cast<cSymbol *>(GetChild(0));
  }

  virtual cDeclNode* GetType()
  {
    cDeclNode *decl = GetName()->GetDecl();
    cDeclNode *node = nullptr;

    for (int i = 0; i < (this->NumChildren() - 1); i++)
    {
      if(decl == nullptr)
      {
        return nullptr;
      }
      decl = decl->GetType()->GetName()->GetDecl();
    }
    node = decl->GetType();
    return node;
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
