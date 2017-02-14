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

		cArrayDeclNode(cSymbol * type, int count, cSymbol * name) : cDeclNode()
		{
			   name->setType();
			   value = count;
			   AddChild(type);

			   if(g_SymbolTable.Find(name->GetName()))
			   {
				   name = new cSymbol(name->GetName());
			   }

         g_SymbolTable.Insert(name);
			   AddChild(name);
		}

		//output the correct string wanted by output
		virtual string AttributesToString()
		{
			string result(" count='");
			result += std::to_string(value);
			result += "'";
			return result;
		}

		virtual string NodeType() { return string("array_decl"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

	protected:
    int value;
};
