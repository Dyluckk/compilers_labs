#pragma once
//**************************************
// cDeclNode
//
// Defines virtual base class for all declarations.
//
// Author: Phil Howard
// zachary.wentworth@oit.edu
//
// Date: Nov. 28, 2015
//

#include "cAstNode.h"

class cDeclNode : public cAstNode
{
    public:
        cDeclNode(int size = 0) : cAstNode()
        {
          m_size = size;
          m_offset = 0;
        }

        // return the decl for the type of the thing this node represents
        virtual cDeclNode *GetType() = 0;

        // note: should probably generate an error if depth != 0
        virtual cDeclNode *GetType(int depth) { return GetType(); }
        virtual cDeclNode *GetBaseType() { return GetType(); }

        // return the name of the item that is declared
        virtual cSymbol* GetName() = 0;

        // virtual functions to define what kind of decl this is.
        // subclasses should override the appropriate functions.
        virtual bool IsArray()  { return false; }
        virtual bool IsStruct() { return false; }
        virtual bool IsType()   { return false; }
        virtual bool IsFunc()   { return false; }
        virtual bool IsVar()    { return false; }
        virtual bool IsFloat()  { return false; }
        virtual bool IsInt()    { return false; }
        virtual bool IsChar()   { return false; }
        virtual bool IsNumeric()
        { return IsInt() || IsChar() || IsFloat(); }
        virtual bool IsIntegral()
        { return IsInt() || IsChar(); }
        //virtual int  Sizeof()   = 0;

        virtual string NodeType() { return string("decl"); }
        bool IsCompatibleWith(cDeclNode *decl)
        {
            if (decl == nullptr) return false;
            if (IsFunc()) return false;
            if (this == decl) return true;
            if (IsStruct() || decl->IsStruct()) return false;
            if (IsArray() || decl->IsArray()) return false;
            if (IsFloat() && ! decl->IsStruct()) return true;
            if (IsInt() && decl->IsChar()) return true;
            //if (Sizeof() >= decl->Sizeof()) return true;
            return false;
        }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

        virtual int GetSize() { return m_size; }
        virtual void SetSize(int size) { m_size = size; }
        virtual int GetOffset() { return m_offset; }
        virtual void SetOffset(int offset) { m_offset = offset; }

        virtual string AttributesToString()
        {
          if (m_size == 0 && m_offset == 0){
              return "";
          }
          else
          {
            return " size=\"" + std::to_string(m_size) + "\" offset=\"" + std::to_string(m_offset) + "\"";
          }
        }

    private:
        int m_size;
        int m_offset;

};
