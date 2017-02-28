#include "cSymbolTable.h"

// Increasing the scope must create a symbol table, so we call
// that function to do the actual work of creating the object
cSymbolTable::cSymbolTable()
{
  IncreaseScope();

  cSymbol *char_type = new cSymbol("char");
  char_type->SetDecl(new cBaseTypeNode("char", 1, false));
  Insert(char_type);

  cSymbol *int_type = new cSymbol("int");
  int_type->SetDecl(new cBaseTypeNode("int", 4, false));
  Insert(int_type);

  cSymbol *float_type = new cSymbol("float");
  float_type->SetDecl(new cBaseTypeNode("float", 8, true));
  Insert(float_type);
}
