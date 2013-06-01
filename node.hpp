#pragma once
#include "type.hpp"
#include "integer_cst.hpp"
#include "integer_type.hpp"
#include "type_decl.hpp"
#include "void_type.hpp"
#include "list.hpp"
#include "function.hpp"

namespace GCC {
  // graph node
  class Node {
  public:
    Node (Translation_Unit_Decl  n);
    Node (Integer::Type  & t);
    Node (Identifier  n);
    Node (Integer::Const c);
    Node (VoidType c);
    Node (TreeList c);
    Node (TypeDecl c);
    Node (FuncType c);
    Node (FuncDecl::Params::Param c);
    Node (FuncDecl d);
    Node (NamespaceDecl d);
    Node (); // forward decl

    GCC::Integer::Const intcst();
    FuncType::Params param_list();
    Size size();    
    Align align();
    Type type ();
    Scope scope ();
    TreeList list (); // a list of decls
    TreeList decl_list (); // a list of decls
    FuncDecl::Params args();
    FuncDecl funcdecl();

    Identifier identifier ();
  };
  
};
