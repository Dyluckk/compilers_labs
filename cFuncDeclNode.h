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

#include <string>

class cFuncDeclNode : public cDeclNode
{
    public:
        cFuncDeclNode(cSymbol* type, cSymbol* name) : cDeclNode()
        {
            m_name = name;
            m_returnType = type;
            // m_params = nullptr;
            m_other = nullptr;
            m_isDefined = false;

            //find another symbol in the table with the same name
            //because we want to make sure it doesn't exist within the same scope
            cSymbol* otherSymbol = g_SymbolTable.FindLocal(name->GetName());

            if (otherSymbol != nullptr)
            {
              //check if the found otherSymbol is a FuncDecl
              if(otherSymbol->GetDecl()->IsFunc())
              {
                cFuncDeclNode *otherFunc = dynamic_cast<cFuncDeclNode*>(otherSymbol->GetDecl());
                m_other = otherFunc;

                //check if the type is different
                if(otherFunc->GetType() != this->GetType())
                {
                  SemanticError(name->GetName() + " previously defined with different return type");
                }
                else if(otherFunc->isDefined() == false) // ?
                {
                  name->SetDecl(this);
                }
              }
              else // symbol is found, but is not declared as a function
              {
                SemanticError(name->GetName() + " previously defined as other than a function");
              }
            }
            else
            {
                // symbol is found, but outside of the scope
                if(g_SymbolTable.Find(name->GetName()))
                {
                  name = new cSymbol(name->GetName());
                }

                g_SymbolTable.Insert(name);
                name->SetDecl(this);
            }

            AddChild(type);
            AddChild(name);
        }

        void Insert(cAstNode * astNodeChild)
        {
            AddChild(astNodeChild);
        }

        // Return back whether this declaration includes statements or not
        bool isDefined()
        {
          return m_isDefined;
        }

        //override GetName Virtual function from cDeclNode
        virtual cSymbol* GetName()
        {
          return static_cast<cSymbol* >(GetChild(1));
        }
        //override GetType Virtual function from cDeclNode
        virtual cDeclNode* GetType()
        {
          return m_returnType->GetDecl();
        }

        virtual bool IsFunc()   { return true; }
        virtual string NodeType() { return string("func"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

    private:
      cSymbol* m_name;
      cSymbol* m_returnType;
      // cParamsNode* m_params;
      cFuncDeclNode* m_other;
      bool m_isDefined;
};
