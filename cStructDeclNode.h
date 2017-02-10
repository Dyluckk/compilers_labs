#pragma once
//**************************************
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

#include "cAstNode.h"
#include "cDeclNode.h"
#include "cExprNode.h"

class cStructDeclNode : public cDeclNode
{
    public:
        // param is the value of the integer constant
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
