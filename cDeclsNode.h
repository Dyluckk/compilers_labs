#pragma once
//**************************************
// cDeclsNode.h
//
// Defines a class to represent a list of declarations.
//
// Author: Phil Howard
// zachary.wentworth@oit.edu
//
// Date: Jan. 18, 2016
//

#include "cAstNode.h"
#include "cDeclNode.h"

class cDeclsNode : public cAstNode
{
    public:
        // param is the first decl in this decls
        cDeclsNode(cDeclNode *decl) : cAstNode(), m_size(decl->GetSize())
        {
            AddChild(decl);
        }

        // Add a decl to the list
        void Insert(cDeclNode *decl)
        {
            AddChild(decl);
            m_size += decl->GetSize();
        }

        // return a particular decl from the list
        cDeclNode* GetDecl(int index)
        {
            return static_cast<cDeclNode*>(GetChild(index));
        }

        virtual string NodeType() { return string("decls"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

        int GetSize() { return m_size; }
        void SetSize(int size) { m_size = size; }

        virtual string AttributesToString()
        {
            if(m_size)
            {
              return " size=\"" + std::to_string(m_size) + "\"";
            }
            else
            {
              return "";
            }
        }

    private:
        int m_size;
};
