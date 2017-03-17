#pragma once
// **************************************
//  cBinaryExprNode.h
//
//  Defines AST node for binary expressions.
//  Inherits from cExprNode
//
//  Author: Zachary Wentworth
//  zachary.wentworth@oit.edu
//
//  Date: Jan. 18, 2016
//

#include "cVisitor.h"
#include "emit.h"
#include "lex.h"
#include "astnodes.h"

class cCodeGen : public cVisitor
{
    public:
        cCodeGen(string name) : cVisitor()
        {
            InitOutput(name.c_str());
        }

        ~cCodeGen()
        {
            FinalizeOutput();
        }

        void VisitAllNodes(cAstNode* node) { node->Visit(this); }

        void Visit(cProgramNode* node)
        {
            // program start
            EmitString("ADJSP ");
            // size of program
            EmitInt(node->GetBlock()->GetSize());
            EmitString("\n");
            node->GetBlock()->Visit(this);
        }

        void Visit(cPrintNode* node)
        {
            node->GetExpr()->Visit(this);
            EmitString("CALL @print\n");
            EmitString("POP\n");
            EmitString("POP\n");
        }

        void Visit(cAssignNode* node)
        {
            node->GetExpr()->Visit(this);
            // check int or char
            if(node->GetLVal()->GetName()->GetDecl()->GetType()->IsInt())
            {
                EmitString("POPVAR");
                EmitInt(node->GetLVal()->GetOffset());
                EmitString("\n");
            }
            else if(node->GetLVal()->GetName()->GetDecl()->GetType()->IsChar())
            {
                EmitString("POPCVAR");
                EmitInt(node->GetLVal()->GetOffset());
                EmitString("\n");
            }
            else if(node->GetLVal()->GetName()->GetDecl()->GetType()->IsArray())
            {
                ArrayFunction(node->GetLVal());
                if(node->GetLVal()->GetType()->GetBaseType()->IsInt())
                    EmitString("POPVARIND\n");
                else
                    EmitString("POPCVARIND\n");
            }
        }

        void Visit(cVarExprNode* node)
        {
            // type check
            if(node->GetName()->GetDecl()->GetType()->IsInt())
            {
                EmitString("PUSHVAR");
                EmitInt(node->GetOffset());
                EmitString("\n");
            }
            else if(node->GetName()->GetDecl()->GetType()->IsChar())
            {
                EmitString("PUSHCVAR");
                EmitInt(node->GetOffset());
                EmitString("\n");
            }
            else if(node->GetName()->GetDecl()->GetType()->IsArray())
            {
                ArrayFunction(node);
                if(node->GetType()->GetBaseType()->IsInt())
                    EmitString("PUSHVARIND\n");
                else
                    EmitString("PUSHCVARIND\n");
            }
        }

        void ArrayFunction(cVarExprNode* node)
        {
            EmitString("PUSHFP\n");
            for(int i = 0; i < node->NumItems(); i++)
            {
                EmitString("PUSH");
                EmitInt(node->GetOffset());
                EmitString("\n");
                EmitString("PLUS\n");
                node->GetIndex(i)->Visit(this);
                EmitString("PUSH");
                EmitInt(node->GetRowSize(i));
                EmitString("\n");
                EmitString("TIMES\n");
                EmitString("PLUS\n");
            }
        }

        void Visit(cBinaryExprNode* node)
        {
            // get lhs and rhs of the binary expr
            node->GetLeft()->Visit(this);
            node->GetRight()->Visit(this);

            // get correct OP
            // cast needed to get the symbol
            if(static_cast<char>(node->GetOp()->GetOp()) == '+')
                EmitString("PLUS\n");
            else if(static_cast<char>(node->GetOp()->GetOp()) == '-')
                EmitString("MINUS\n");
            else if(static_cast<char>(node->GetOp()->GetOp()) == '*')
                EmitString("TIMES\n");
            else if(static_cast<char>(node->GetOp()->GetOp()) == '/')
                EmitString("DIVIDE\n");
            else if(static_cast<char>(node->GetOp()->GetOp()) == '%')
                EmitString("MOD\n");
            else if(node->GetOp()->GetOp() == EQUALS)
                EmitString("EQ\n");
            else if(node->GetOp()->GetOp() == OR)
                EmitString("OR\n");
            else if(node->GetOp()->GetOp() == AND)
                EmitString("AND\n");
            else if(node->GetOp()->GetOp() == NOT_EQUALS)
                EmitString("NE\n");
        }

        void Visit(cIntExprNode* node)
        {
            EmitString("PUSH");
            EmitInt(node->GetValue());
            EmitString("\n");
        }

        void Visit(cIfNode* node)
        {
            // condition has to be visited first
            node->GetCond()->Visit(this);
            // generate the label from provided function
            string firstLabel = GenerateLabel();
            string secondLabel = GenerateLabel();
            EmitString("JUMPE @");
            EmitString(firstLabel);
            EmitString("\n");
            // get the if stmt
            node->GetIf()->Visit(this);
            EmitString("JUMP @");
            EmitString(secondLabel);
            EmitString("\n");
            // show where the else stmts are
            EmitString(firstLabel);
            EmitString(":\n");
            // if else exists
            if(node->GetElse() != nullptr)
                node->GetElse()->Visit(this);
            // show where end if stmt is
            EmitString(secondLabel);
            EmitString(":\n");
        }

        void Visit(cWhileNode* node)
        {
            // while stmt
            string firstLabel = GenerateLabel();
            // end of while loop
            string secondLabel = GenerateLabel();
            // while starts
            EmitString(firstLabel);
            EmitString(":\n");
            // visit the condition
            node->GetCond()->Visit(this);
            // jump to end of while
            EmitString("JUMPE @");
            EmitString(secondLabel);
            EmitString("\n");
            // visit stmt of while loop
            node->GetStmt()->Visit(this);
            // jump to while
            EmitString("JUMPE @");
            EmitString(firstLabel);
            EmitString("\n");
            // set end of loop
            EmitString(secondLabel);
            EmitString(":\n");
        }

        void Visit(cFuncDeclNode* node)
        {
            //  check if the function is defined
            if (node->IsFullyDefined())
            {
                StartFunctionOutput(node->GetName()->GetName());

                EmitString("ADJSP");
                EmitInt(node->GetSize());
                EmitString("\n");

                if(node->GetStmts() != nullptr)
                    node->GetStmts()->Visit(this);

                EndFunctionOutput();
            }
        }

        void Visit(cFuncExprNode* node)
        {
            // if params exist
            if(node->GetParams() != nullptr)
                node->GetParams()->Visit(this);

            EmitString("CALL @");
            EmitString(node->GetName()->GetName());
            EmitString("\n");

            if(node->GetParams() != nullptr)
            {
              EmitString("POPARGS");
              EmitInt(node->GetParams()->GetSize());
              EmitString("\n");
            }
        }

        void Visit(cParamListNode* node)
        {
            // get the params
            for(int i = node->GetNumParams() - 1; i >= 0; i--)
                node->GetParam(i)->Visit(this);
        }

        void Visit(cReturnNode* node)
        {
            node->GetExpr()->Visit(this);
            EmitString("RETURNV\n");
        }
};
