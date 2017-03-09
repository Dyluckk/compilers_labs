#include "cComputeSize.h"
#include "astnodes.h"

void cComputeSize::VisitAllNodes(cAstNode *node)
{
  VisitAllChildren(node);
}

void cComputeSize::Visit(cProgramNode *node)
{
  VisitAllChildren(node);
  cBlockNode *block = node->GetBlock();
  int blockSize     = block->GetSize();

  while (blockSize % 4 != 0)
  {
    blockSize++;
  }

  block->SetSize(blockSize);
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
  int old_offset    = m_offset;
  int old_highwater = m_highwater;

  m_offset    = 0;
  m_highwater = 0;

  VisitAllChildren(node);

  m_offset = Align(4);
  node->SetSize(Align(m_highwater));
  m_offset    = old_offset;
  m_highwater = old_highwater;
}

void cComputeSize::Visit(cParamsNode *node)
{
  int old_offset = m_offset;
  m_offset = -8;
  VisitAllChildren(node);
  node->SetSize(-(m_offset + 8));
  m_offset = old_offset;
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
