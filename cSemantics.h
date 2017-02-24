#pragma once

class cSemantics : cVisitor {
  public:

    void SemanticError(cAstNode *node, string msg)
    {
      m_numErrors++;

      node->SetHasError();
      std::cout << "ERROR: " << msg << "on line " << node->LineNumber() << "\n";
    }

    void VisitAllNodes(cAstNode *node) {
      node->Visit(this);
    }

    int GetNumErrors(){
      return m_numErrors;
    }

  protected:
    int m_numErrors;
};
