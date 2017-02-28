//**************************************
// cArrayDeclNode.h
//
// Defines an AST node for array declerations
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

class cArrayDeclNode : public cDeclNode
{
	public:

		cArrayDeclNode(cSymbol* type, int count, cSymbol* name) : cDeclNode()
		{
         if(g_SymbolTable.Find(name->GetName()))
			   {
				   name = new cSymbol(name->GetName());
           g_SymbolTable.Insert(name);
           name->SetDecl(this);
			   }
         else
         {
           g_SymbolTable.Insert(name);
           name->SetDecl(this);
         }

         m_count = count;
			   AddChild(type);
			   AddChild(name);
		}

		//output the correct string wanted by output
		virtual string AttributesToString()
		{
			string result(" count='");
			result += std::to_string(m_count);
			result += "'";
			return result;
		}

    int GetSize()
    {
      return m_count;
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

		virtual string NodeType() { return string("array_decl"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

    virtual bool IsType()  { return true; }
    virtual bool IsArray() { return true; }
	protected:
    int m_count;
};
