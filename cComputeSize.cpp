#include "cComputeSize.h"
#include "astnodes.h"

#define STACK_FRAME_SIZE 8

void cComputeSize::VisitAllNodes(cAstNode *node)
{
  VisitAllChildren(node);
}

void cComputeSize::Visit(cProgramNode *node)
{
  VisitAllChildren(node);
  cBlockNode *block = node->GetBlock();
  block->SetSize(Align(block->GetSize()));
}

void cComputeSize::Visit(cBlockNode *node)
{
  int old_offset    = m_offset;
  int old_highwater = m_highwater;

  m_highwater = old_offset;

  VisitAllChildren(node);

  node->SetSize(m_highwater - old_offset);
  m_offset = old_offset;

  // check if highwater needs to be set
  if (old_highwater > m_highwater)
  {
    m_highwater = old_highwater;
  }
}

void cComputeSize::Visit(cDeclsNode *node)
{
  int old_offset = m_offset;

  VisitAllChildren(node);
  node->SetSize(m_offset - old_offset);
}

void cComputeSize::Visit(cArrayDeclNode *node)
{
  VisitAllChildren(node);
  int size = node->GetCount();
  size = size * node->GetBaseType()->GetSize();
  node->SetSize(size);
}

void cComputeSize::Visit(cVarDeclNode *node)
{
  if (m_offset < 0)
  {
    node->SetSize(node->GetType()->GetSize());

    if (node->GetSize() != 1)
    {
      m_offset = ((-1) * Align(m_offset * (-1)));
    }
    m_offset -= Align(node->GetSize());
    node->SetOffset(m_offset);
  }
  else
  {
    VisitAllChildren(node);
    node->SetSize(node->GetType()->GetSize());

    if (!node->GetType()->IsChar())
    {
      m_offset = Align(m_offset);
    }
    node->SetOffset(m_offset);
    m_offset += node->GetType()->GetSize();

    if (m_offset > m_highwater)
    {
      m_highwater = m_offset;
    }
  }
}

void cComputeSize::Visit(cFuncDeclNode *node)
{
  int start_offset    = m_offset;
  int start_highwater = m_highwater;

  m_offset    = -STACK_FRAME_SIZE;
  m_highwater = 0;

  if (node->GetParams() != nullptr) node->GetParams()->Visit(this);
  m_offset    = 0;
  m_highwater = 0;

  if (node->GetLocals() != nullptr) node->GetLocals()->Visit(this);

  if (node->GetStmts() != nullptr) node->GetStmts()->Visit(this);

  node->SetSize(Align(m_highwater));

  m_highwater = start_highwater;
  m_offset    = start_offset;
}

void cComputeSize::Visit(cParamListNode *node)
{
  int size = 0;

  // need to explicitly visit the children because expressions don't
  // update a size so we can't use VisitAllChildren
  for (int ii = 0; ii < node->NumChildren(); ii++)
  {
    cExprNode *expr = node->GetParam(ii);

    if (expr != nullptr)
    {
      expr->Visit(this);
      size += Align(expr->GetType()->GetSize());
    }
  }

  node->SetSize(size);
}

void cComputeSize::Visit(cParamsNode *node)
{
  VisitAllChildren(node);

  node->SetSize(-m_offset - STACK_FRAME_SIZE);

  if (m_offset > m_highwater) m_highwater = m_offset;
}

void cComputeSize::Visit(cVarExprNode *node)
{
  node->SetOffset(node->GetName()->GetDecl()->GetOffset());
  node->SetSize(node->GetName()->GetDecl()->GetSize());

  // if array
  if (node->NumItems() > 0)
  {
    // set row size for each based on dereference type at the specified index
    for (int i = 1; i <= node->NumItems(); i++)
    {
      node->AddRowSize(node->GetDereferencedType(i)->GetSize());
    }
  }
}

void cComputeSize::Visit(cFuncExprNode *node)
{
  VisitAllChildren(node);

  if (node->GetParams() != nullptr)
  {
    int paramsSize = 0;

    // get total size based on all parameters
    for (int i = 0; i < node->GetParams()->NumChildren(); i++)
    {
      paramsSize += node->GetParams()->GetParam(i)->GetType()->GetSize();
    }
    node->GetParams()->SetSize(paramsSize);
  }
}

int cComputeSize::Align(int size)
{
  if (size % 4 != 0)
  {
    size += 4 - size % 4;
  }
  return size;
}
