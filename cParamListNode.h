#pragma once
//**************************************
// cParamListNode.h
//
// Defines AST node for actual params passed to a function
//
// Author: Phil Howard
// zachary.wentworth@oit.edu
//
// Date: Jan. 18, 2016
//

#include "cAstNode.h"
#include "cExprNode.h"

class cParamListNode : public cAstNode
{
    public:
        // param is first actual param passed to function
        cParamListNode(cExprNode *param)
            : cAstNode()
        {
            AddChild(param);
        }

        // add the next actual param
        void Insert(cExprNode *param)
        {
            AddChild(param);
        }

        cExprNode* GetParam(int index)
        {
            return static_cast<cExprNode*>(GetChild(index));
        }

        int GetNumParams() { return this->NumChildren(); }
        virtual int GetSize() { return m_size; }
        virtual void SetSize(int size) { m_size = size; }

        virtual string AttributesToString()
        {
          if (m_size == 0){
            return "";
          }
          else
          {
            return " size=\"" + std::to_string(m_size) + "\"";
          }
        }

        virtual string NodeType() { return string("params"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

    private:
        int m_size;
};
