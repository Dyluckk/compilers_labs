//**************************************
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

class cStructDeclNode : public cDeclNode
{
    public:
        cStructDeclNode(cDeclsNode * declsNode, cSymbol  * name) : cDeclNode()
        {
          AddChild(declsNode);

          if (g_SymbolTable.Find(name->GetName())){
              name = new cSymbol(name->GetName());
          }

          g_SymbolTable.Insert(name);
          name->setType();
          AddChild(name);
        }

        virtual string NodeType() { return string("struct_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

        void Insert(cSymbol * var)
        {
            AddChild(var);
        }
};
