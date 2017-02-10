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
#include "cSymbol.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cParamsNode.h"

class cFuncDeclNode : public cDeclNode
{
    public:
        // param is the value of the integer constant
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

        virtual string NodeType() { return string("func"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
