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
#pragma once

#include "cAstNode.h"
#include "cDeclNode.h"
#include "cSymbol.h"

class cVarDeclNode : public cDeclNode
{
    public:
        cVarDeclNode(cSymbol * type, cSymbol * name) : cDeclNode()
        {
            AddChild(type);

            if (g_SymbolTable.Find(name->GetName())){
                name = new cSymbol(name->GetName());
            }

            g_SymbolTable.Insert(name);
            AddChild(name);
        }

        void Insert(cSymbol * var)
        {
            AddChild(var);
        }

        //override GetName Virtual function from cDeclNode
        virtual cSymbol* GetName()
        {
          return static_cast<cSymbol* >(GetChild(1));
        }
        //override GetType Virtual function from cDeclNode
        virtual cDeclNode* GetType()
        {
          return (static_cast<cSymbol* >(GetChild(0)))->GetDecl();
        }

        virtual string NodeType() { return string("var_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
