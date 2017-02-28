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

  void Visit(cFuncExprNode *node)
  {
    // check if declared, if true check if fully defined
    if (node->GetName()->GetDecl() == nullptr)
    {
      SemanticError(node, "function " + node->GetName()->GetName() + " is not declared ");
    }

    // check if the FuncExprNode is a cFuncDeclNode
    else if (!node->GetName()->GetDecl()->IsFunc())
    {
      SemanticError(node, node->GetName()->GetName() + " is not a function ");
    }
    else if (node->GetFuncDecl()->isDefined() == false)
    {
      SemanticError(node, "function " + node->GetName()->GetName() + " is not fully defined ");
    }

    // check arguements passed
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
    }

    for (int i = 0; i < numParamsDeclared; i++)
    {
      if (!paramsPassed->GetExpr(i)->HasError())
      {
        if (paramsPassed->GetExpr(i)->GetType() != paramsDeclared->GetParam(i)->GetType())
        {
          bool incompatibleArgs = false;

          if (paramsDeclared->GetParam(i)->GetType()->IsInt())
          {
            if (paramsPassed->GetExpr(i)->GetType()->IsInt() == false)
            {
              incompatibleArgs = true;
            }
          }
          else if (paramsDeclared->GetParam(i)->GetType()->IsChar())
          {
            if (paramsPassed->GetExpr(i)->GetType()->IsChar() == false)
            {
              incompatibleArgs = true;
            }
          }
          else if (paramsDeclared->GetParam(i)->GetType()->IsFloat())
          {
            if (paramsPassed->GetExpr(i)->GetType()->IsFloat() == false)
            {
              incompatibleArgs = true;
            }
          }

          if (incompatibleArgs)
          {
            SemanticError(node, "function " + node->GetName()->GetName() + " called with incompatible argument ");
          }

        }
      }
    }
  }

  // 1+ 5+ 6+ 7+ 4 3 8 2

protected:

  int m_numErrors;
};
