#pragma once
#include "cVisitor.h"

class cComputeSize : public cVisitor
{
public:
    cComputeSize() : cVisitor()
    {
      m_offset = 0;
      m_highwater = 0;
    }

    virtual void VisitAllNodes(cAstNode *node);
    virtual void Visit(cProgramNode *node);
    virtual void Visit(cBlockNode *node);
    virtual void Visit(cDeclsNode *node);
    virtual void Visit(cArrayDeclNode * node);
    virtual void Visit(cVarDeclNode *node);
    virtual void Visit(cFuncDeclNode *node);
    virtual void Visit(cParamsNode *node);
    virtual void Visit(cVarExprNode *node);
    virtual void Visit(cFuncExprNode *node);
    
private:
    int Align(int size);
    int m_offset;
    int m_highwater;
};