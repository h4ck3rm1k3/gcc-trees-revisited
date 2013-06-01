#pragma once
namespace GCC {
  class TypeDecl : public Decl {
  public:
    TypeDecl(); // empty
    TypeDecl & setname (Identifier     name);
    TypeDecl & settype (Type  type);
    TypeDecl & setsrcp (const char * file, int line);
    TypeDecl & setnoteartificial();
  };
  TypeDecl type_decl();
};
