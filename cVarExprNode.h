#pragma once
//**************************************
// cVarExprNode.h
//
// Defines AST node for a variable reference
//
// Inherits from cExprNode so variable refs can be used in expressions`
//
// Author: Phil Howard
// phil.howard@oit.edu
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

        cDeclNode* GetDecl()
        {
          return GetName()->GetDecl();
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

        cSymbol* GetElement(int index)
        {
             return (cSymbol*)GetChild(index + 1);
        }

        cExprNode* GetIndex(int index)
        {
             return (cExprNode*)GetChild(index + 1);
        }

        virtual int GetSize() { return m_size; }
        virtual void SetSize(int size) { m_size = size; }
        virtual int GetOffset() { return m_offset; }
        virtual void SetOffset(int offset) { m_offset = offset; }

        cDeclNode* GetDereferencedType(int index)
        {
          cDeclNode *decl = GetName()->GetDecl();
          cDeclNode *type = nullptr;

          for (int i = 0; i < index; i++)
          {
            if (decl == nullptr)
            {
              return nullptr;
            }
            else
            {
              decl = decl->GetBaseType()->GetName()->GetDecl();
            }

          }

          type = decl->GetBaseType();
          return type;
        }

        void AddRowSize(int size)
        {
            m_rowSizes.push_back(size);
        }

        virtual string AttributesToString()
        {
          string rowSizes;

          //check if rowsize
          if (m_rowSizes.size() == 0)
          {
            if ((m_size == 0) && (m_offset == 0))
            {
              return "";
            }
            else
            {
              return " size=\"" + std::to_string(m_size) + "\" offset=\""
                     + std::to_string(m_offset) + "\"";
            }
          }

          for (unsigned int i = 0; i < m_rowSizes.size(); i++)
          {
            rowSizes += std::to_string(m_rowSizes[i]);
            rowSizes += " ";
          }

          return " size=\"" + std::to_string(m_size) + "\" offset=\""
                 + std::to_string(m_offset) + "\" rowsizes=\"" + rowSizes + "\"";
        }

        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

  private:
        int m_size;
        int m_offset;
        vector<int> m_rowSizes;

};
