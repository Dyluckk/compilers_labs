#pragma once

class cSemantics : cVisitor {
public:

  cSemantics() : m_numErrors(0)
  {}

  void SemanticError(cAstNode *node, string msg)
  {
    m_numErrors++;

    node->SetHasError();
    std::cout << "ERROR: " << msg << "on line " << node->LineNumber() << "\n";
  }

  void VisitAllNodes(cAstNode *node) {
    node->Visit(this);
  }

  int GetNumErrors() {
    return m_numErrors;
  }

  void Visit(cVarExprNode *node)
  {
    if (node->GetName()->GetDecl() == nullptr)
    {
      SemanticError(node, "Symbol " + node->GetName()->GetName() + " not defined ");
    }
  }

protected:

  int m_numErrors;
};
