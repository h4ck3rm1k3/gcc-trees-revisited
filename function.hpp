#pragma once
#include "type.hpp"
#include "link.hpp"
#include "list.hpp"

namespace GCC 
{

class FuncType : public Type 
{
public:

  class Return  : public Type {};

  class Params {
  public:
    class Param {
    };
  };

  Size  size;
  Align algn;
  FuncType::Return retn;
  FuncType::Params prms;

public:
  FuncType & setsize(Size);
  FuncType & setalgn(int);
  FuncType & setretn(Type);
  FuncType & setprms(Params);
};

class FuncDecl;

class FuncDecl : public Scope , public Decl{
public:
  class Body {};
  class Params {
  public:
    class Param : public Decl {

      Identifier name;
      Type type;
      Rel::TIsContained<FuncDecl> scpe; // points to the function that contains the parameter

      Type argt;
      Size size;
      Align algn;
      Used used;
    public:
      Param & setname(Identifier name);
      Param & settype(Type t);
      Param & setargt(Type t);
      Param & setalgn(int i);
      Param & setsize(Size t);
      Param & setused();
      Param & setsrcp(const char * file, int line);
      FuncDecl & setscpe(FuncDecl );
    };
  };

  Identifier name;
  Identifier  mngl;
  FuncType type;

  Rel::TIsContained<Translation_Unit_Decl> scpe; // points to the translation untion that contains the function
  // what about functions inside functions?

  //  Decl chain;
  FuncDecl::Params args;
  LinkType _extern;

public:
  FuncDecl & setname(Identifier );
  FuncDecl & setmngl(Identifier );
  FuncDecl & settype(Type );
  FuncDecl & setscpe(Scope );
  FuncDecl & setargs(FuncDecl::Params );
  FuncDecl & setsrcp(const char * file, int line );
  FuncDecl & setlinkextern();
  
};

  FuncDecl function_decl();
  FuncType function_type() {}

class ParamTypesList  : public TreeList 
{
  Type valu;
  Rel::Pointer<ParamTypesList> chan;
};

ParamTypesList     tree_list_param( Type valu,      ParamTypesList chan     ) {};
ParamTypesList     tree_list_param( Type valu) {}

FuncDecl::Params::Param      parm_decl() {}

FuncDecl::Body func_body() {}
FuncDecl::Params func_parameters() {}
FuncDecl::Params::Param  func_parameter() {}
};
