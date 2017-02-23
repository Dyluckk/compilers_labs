//**************************************
// cVarDeclNode.h
//
// Defines cParamasNode
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
#include "cSymbol.h"

class cParamsNode : public cDeclNode
{
    public:
        // param is the value of the integer constant
        cParamsNode(cDeclNode * multiple ) : cDeclNode()
        {
            AddChild(multiple);
        }

        void Insert(cDeclNode * child){
            AddChild(child);
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

        virtual string NodeType() { return string("args"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
