#include "cComputeSize.h"
#include "astnodes.h"

void cComputeSize::VisitAllNodes(cAstNode *node)
{
  VisitAllChildren(node);
}

void cComputeSize::Visit(cBlockNode *node)
{
  int temp = m_offset;

  VisitAllChildren(node);

  m_highwater = temp;
  m_offset    = 0;
}

void cComputeSize::Visit(cVarDeclNode *node)
{
  if (node->GetType()->IsChar())
  {
    node->SetOffset(m_offset);
  }
  else
  {
    m_offset = Align(m_offset);
    node->SetOffset(m_offset);
  }
  m_offset += node->GetType()->GetSize();

  if (m_offset > m_highwater)
  {
    m_highwater = m_offset;
  }
}

int cComputeSize::Align(int size)
{
  int temp = 0;

  if (size % 4 != 0) temp = (size & ~3) + 4;
  else temp = size;

  return temp;
}
