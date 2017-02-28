// **************************************

// cProgramNode.h
//
// Defines AST node for a lang program
//
// Author: Phil Howard
// phil.howard@oit.edu
//
// Date: Jan. 18, 2015
//
#pragma once

#include "cAstNode.h"
#include "cBlockNode.h"

class cProgramNode : public cAstNode {
public:

  cProgramNode(cBlockNode *block) : cAstNode()
  {
    AddChild(block);
  }

  virtual string NodeType()
  {
    return string("program");
  }

  virtual void Visit(cVisitor *visitor)
  {
    visitor->Visit(this);
  }
};
