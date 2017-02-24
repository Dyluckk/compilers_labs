#include "cBaseTypeNode.h"
#include "cSymbolTable.h"

cBaseTypeNode::cBaseTypeNode(string name, int size, bool isFloat ) : cDeclNode()
{
    m_name = name;
    m_size = size;
    m_isFloat = isFloat;
}

//override GetName Virtual function from cDeclNode
cSymbol* cBaseTypeNode::GetName()
{
  return g_SymbolTable.Find(m_name);
}
//override GetType Virtual function from cDeclNode
cDeclNode* cBaseTypeNode::GetType()
{
  return g_SymbolTable.Find(m_name)->GetDecl();
}

bool cBaseTypeNode::IsType() { return true; }
string cBaseTypeNode::NodeType() { return string("base_node"); }
void cBaseTypeNode::Visit(cVisitor *visitor) { visitor->Visit(this); }
