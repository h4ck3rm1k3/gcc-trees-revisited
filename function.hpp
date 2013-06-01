class FuncType : public Type 
{
public:


  class Return {};

  class Params {
  public:
    class Param {
    };
  };

  Size  size;
  Align algn;
  FuncType::Return retn;
  FuncType::Params prms;

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

};

FuncDecl function_decl( 
		   Identifier name, 
		   Identifier  mngl, 
		   FuncType type,  
		   Scope scpe,     
		   Source  srcp,
		   Decl chain,
		   FuncDecl::Params args,
		   LinkType _extern  
		    ) {};

FuncType function_type(Size  size,
		       Align algn,
		       FuncType::Return retn,
		       FuncType::Params prms) {}

class ParamTypesList  : public TreeList 
{
  Type valu;
  Rel::Pointer<ParamTypesList> chan;
};

ParamTypesList     tree_list_param( Type valu,      ParamTypesList chan     ) {};
ParamTypesList     tree_list_param( Type valu) {}

FuncDecl::Params::Param      parm_decl(
			   Identifier name,
			   Type type,
			   Scope scpe,
			   Source srcp,
			   Type argt,
			   Size size,
			   Align algn,
			   Used used) {}

FuncDecl::Body func_body() {}
FuncDecl::Params func_parameters() {}
FuncDecl::Params::Param  func_parameter() {}
