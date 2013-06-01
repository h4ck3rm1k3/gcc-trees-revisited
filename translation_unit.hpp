#include "scope.hpp"

namespace GCC { 

class Translation_Unit_Decl  : public Scope {};
Translation_Unit_Decl translation_unit_decl ();

Identifier id_scope() {
  // :: the global scope
} 


// the global namespace for a given file
NamespaceDecl global_namespace_decl(Source source) {} 

} ;
