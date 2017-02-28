// **************************************

// cBaseTypeNode.h
//
// Defines the base type node
//
// Inherits from cDeclNode
//
// Author: Zachary Wentworth
// zachary.wentworth@oit.edu
//
// Date: Feb. 25, 2017
//
#pragma once

#include "cAstNode.h"
#include "cDeclNode.h"

class cBaseTypeNode : public cDeclNode {
public:

  cBaseTypeNode(string name,
                int    size,
                bool   isFloat);

  // override GetName Virtual function from cDeclNode
  virtual cSymbol  * GetName();

  // override GetType Virtual function from cDeclNode
  virtual cDeclNode* GetType();
  virtual bool       IsType();
  virtual bool       IsInt();
  virtual bool       IsChar();
  virtual bool       IsFloat();

  virtual string     NodeType();
  virtual void       Visit(cVisitor *visitor);

protected:

  string m_name;
  int m_size;
  bool m_isFloat;
};
