//**************************************
// cFuncDeclNode.h
//
// Defines an AST node for function declerations
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
#include "cSymbol.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cParamsNode.h"

class cFuncDeclNode : public cDeclNode
{
    public:
        cFuncDeclNode(cSymbol * type, cSymbol * name)
        {
            if(g_SymbolTable.Find(name->GetName()))
            {
                name = new cSymbol(name->GetName());
            }

            g_SymbolTable.Insert(name);

            AddChild(type);
            AddChild(name);
        }

        void Insert(cAstNode * astNodeChild){
            AddChild(astNodeChild);
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

        virtual string NodeType() { return string("func"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
