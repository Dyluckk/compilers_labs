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
      return;
    }
  }

  void Visit(cAssignNode *node)
  {

    VisitAllChildren(node);

    if (!node->GetLHS()->HasError() && !node->GetRHS()->HasError())
    {
      if (node->GetLHS()->GetType()->IsInt() != node->GetRHS()->GetType()->IsInt())
      {
        SemanticError(node, "Cannot assign " + node->GetLHS()->GetName()->GetName() + " to " + node->GetRHS()->GetName()->GetName());
        return;
      }

      if (node->GetLHS()->GetType()->IsFloat() != node->GetRHS()->GetType()->IsFloat())
      {
        SemanticError(node, "Cannot assign " + node->GetLHS()->GetName()->GetName() + " to ");
        return;
      }

      if (node->GetLHS()->GetType()->IsChar() != !node->GetRHS()->GetType()->IsChar())
      {
        SemanticError(node, "Cannot assign " + node->GetLHS()->GetName()->GetName() + " to ");
        return;
      }
    }
  }

  void Visit(cFuncExprNode *node)
  {
    // check if declared, if true check if fully defined
    if (node->GetName()->GetDecl() == nullptr)
    {
      SemanticError(node, "function " + node->GetName()->GetName() + " is not declared ");
      return;
    }

    // check if the FuncExprNode is a cFuncDeclNode
    else if (!node->GetName()->GetDecl()->IsFunc())
    {
      SemanticError(node, node->GetName()->GetName() + " is not a function ");
      return;
    }
    else if (node->GetFuncDecl()->isDefined() == false)
    {
      SemanticError(node, "function " + node->GetName()->GetName() + " is not fully defined ");
      return;
    }

    // check arguments passed
    int numParamsDeclared        = 0;
    int numParamsPassed          = 0;
    cParamsNode *paramsDeclared  = node->GetFuncDecl()->GetParams();
    cParamListNode *paramsPassed = node->GetParams();

    if (paramsDeclared != nullptr)
    {
      numParamsDeclared = paramsDeclared->GetNumParams();
    }

    if (paramsPassed != nullptr)
    {
      numParamsPassed = paramsPassed->GetNumParams();
    }

    if (numParamsPassed != numParamsDeclared)
    {
      SemanticError(node, "function " + node->GetName()->GetName() + " called with wrong number of arguments ");
      return;
    }

    for (int i = 0; i < numParamsDeclared; i++)
    {
      if (!paramsPassed->GetExpr(i)->HasError())
      {
        if (paramsPassed->GetExpr(i)->GetType() != paramsDeclared->GetParam(i)->GetType())
        {
          SemanticError(node, "function " + node->GetName()->GetName() + " called with incompatible argument ");
          return;
        }
      }
    }
  }

  // 1+ 5+ 6+ 7+ 8+ 4 3 2

protected:

  int m_numErrors;
};
