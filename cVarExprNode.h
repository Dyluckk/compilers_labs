#pragma once
//**************************************
// cVarExprNode.h
//
// Defines AST node for a variable reference
//
// Inherits from cExprNode so variable refs can be used in expressions`
//
// Author: Phil Howard
// zachary.wentworth@oit.edu
//
// Date: Jan. 18, 2016
//

#include "cSymbol.h"
#include "cAstNode.h"
#include "cExprNode.h"

class cVarExprNode : public cExprNode
{
    public:
        // param is the symbol for the variable
        cVarExprNode(cSymbol *name)
            : cExprNode()
        {
            AddChild(name);
        }

        // called for the fields in struct refs
        void AddElement(cSymbol *name)
        {
            AddChild(name);
        }

        void AddElement(cExprNode *index)
        {
            AddChild(index);
        }

        cSymbol* GetName()
        {
            return static_cast<cSymbol*>(GetChild(0));
        }

        // return a string representation of the name of the var
        virtual string GetTextName()
        {
            string name("");
            cSymbol* sym;

            sym = GetName();

            name += sym->GetName();

            for (int ii=0; ii<NumItems(); ii++)
            {
                if (ItemIsIndex(ii))
                {
                    name += "[]";
                }
                else
                {
                    sym = GetElement(ii);
                    name += "." + sym->GetName();
                }
            }

            return name;
        }

        // return the type of the VarExpr. This includes dereferencing arrays
        virtual cDeclNode *GetType()
        {
            cDeclNode* decl = GetName()->GetDecl();
            if (decl == nullptr) return nullptr;

            cDeclNode* type = decl->GetType();

            if (type->IsArray())
            {
                return type->GetType(NumItems());
            }
            else
            {
                return type;
            }
        }

        int NumItems() { return NumChildren() - 1; }

        bool ItemIsIndex(int index)
        {
            // if the dynamic cast fails, this item must be a cSymbol* for
            // a struct member
            return dynamic_cast<cExprNode*>(GetChild(index + 1)) != nullptr;
        }

        void AddRowSize(int size)
        {
            m_row.push_back(size);//for the vector we have
        }

        int GetRowSize(int index)
        {
            return m_row[index];
        }

        cDeclNode * GetTypes(int size)//this function will get the decl type and wil go through all params
        {
            cDeclNode * decl = GetName()->GetDecl();
            for(int i = 0; i < size; i++)//size is the ammount of params in the func
            {
                if(decl != nullptr)//dont access something that isnt being set
                {
                    decl = decl->GetBaseType()->GetName()->GetDecl();//else get the decl of the type of param
                }
                else
                {
                    return nullptr;
                }
            }

            cDeclNode * basetype = decl->GetBaseType();//returns the base type of the decl
            return basetype;
        }

        cSymbol* GetElement(int index)
        {
             return (cSymbol*)GetChild(index + 1);
        }

        cExprNode* GetIndex(int index)
        {
             return (cExprNode*)GetChild(index + 1);
        }

        cDeclNode * GetDecl()
        {
            return GetName()->GetDecl();
        }

        int GetSize()
        {
            return m_size;
        }

        int GetOffset()
        {
            return m_offset;
        }

        void SetSize(int size)
        {
            m_size = size;
        }

        void SetOffset(int offset)
        {
            m_offset = offset;
        }

        virtual string AttributesToString()
        {
            if(m_row.size() == 0)
            {
                if(m_size == 0 && m_offset == 0)
                {
                    return "";
                }
                else
                {
                    return " size=\"" + std::to_string(m_size) + "\" offset=\"" + std::to_string(m_offset) + "\"";
                }
            }
            string rowsizes;
            for(unsigned int i = 0; i < m_row.size(); i++)
            {
                rowsizes += std::to_string(m_row[i]);
                rowsizes += " ";
            }

            rowsizes.pop_back();

            return " size=\"" + std::to_string(m_size) + "\" offset=\"" + std::to_string(m_offset) + "\" rowsizes=\"" + rowsizes + "\"";
        }

        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

    private:
        int m_size;
        int m_offset;
        vector<int> m_row;
};
