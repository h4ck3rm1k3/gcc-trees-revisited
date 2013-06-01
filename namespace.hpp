#pragma once

#include "rel.hpp"
#include "id.hpp"
#include "scope.hpp"
#include "decl.hpp"
#include "list.hpp"
namespace GCC {
class NamespaceDecl : public Decl {
  Identifier name;
  Scope scope;  // a namespace can be in a namespace
  Rel::TContains<Decl> decls;  
public :
  NamespaceDecl & setname(Identifier);
  NamespaceDecl & setscpe(Scope);
  NamespaceDecl & setsrcp(const char * file, int line );
  NamespaceDecl & setdcls(TreeList );
};
NamespaceDecl namespace_decl() {}
}
