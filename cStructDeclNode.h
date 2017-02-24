// **************************************

// cStructDeclNode.h
//
// Defines an AST node for an struct declerations
//
// Inherits from cDeclNode
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

class cStructDeclNode : public cDeclNode {
public:

  cStructDeclNode(cDeclsNode *declsNode, cSymbol  *name) : cDeclNode()
  {
    // TODO AUTO SEMANTIC ERROR

    AddChild(declsNode);

    if (g_SymbolTable.Find(name->GetName())) {
      name = new cSymbol(name->GetName());
      g_SymbolTable.Insert(name);
      name->SetDecl(this);
    }
    else
    {
      g_SymbolTable.Insert(name);
      name->SetDecl(this);
    }

    AddChild(name);
  }

  void Insert(cSymbol *var)
  {
    AddChild(var);
  }

  // override GetName Virtual function from cDeclNode
  virtual cSymbol* GetName()
  {
    return static_cast<cSymbol *>(GetChild(1));
  }

  // override GetType Virtual function from cDeclNode
  virtual cDeclNode* GetType()
  {
    return (static_cast<cSymbol *>(GetChild(0)))->GetDecl();
  }

  virtual string NodeType() {
    return string("struct_decl");
  }

  virtual void Visit(cVisitor *visitor) {
    visitor->Visit(this);
  }

  virtual bool IsStruct() {
    return true;
  }

  virtual bool IsType() {
    return true;
  }
};
