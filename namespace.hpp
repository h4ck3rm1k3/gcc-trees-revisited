class NamespaceDecl : public Decl {
  Identifier name;
  Scope scope;  // a namespace can be in a namespace
  Rel::TContains<Decl> decls;  
};
NamespaceDecl namespace_decl(Identifier name, Scope scope ,/* Decl decls, this is added in later*/ Source source) {}
