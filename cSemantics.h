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

    void Visit(cVarExprNode* node)
    {
      if(node->GetName()->GetDecl() == nullptr)
      {
        SemanticError(node, "Symbol " + node->GetName()->GetName() + " is not defined");
      }
    }


  protected:
    int m_numErrors;
};
