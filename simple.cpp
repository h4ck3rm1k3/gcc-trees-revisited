
namespace Rel //ationships
{
  template <class T> class Pointer {};
  template <class T> class Reference {};
  template <class T> class TemplateVersion {};

  class InverseOf {};
  template <class T> class TInverseOf {
    TemplateVersion<InverseOf> derived_from;// the template version of InverseOf
  };

  class Contains {};


  template <class T> class TContains {
    TemplateVersion<Contains> derived_from;// the template version of contains
  }; 

  class IsContained {
    TInverseOf<Contains> inverse;
  };

  template <class T> class TIsContained {
    TemplateVersion<IsContained> derived_from;// the template version of IsContained
  }; 

};
///

class Scope; // forward

class Decl {
public:
  Rel::TIsContained<Scope> contained_in_scope;
};

class Scope {
  Rel::TContains<Decl> decls;  

};

class Translation_Unit_Decl  : public Scope {};

class Source {
  // Source File,line number and char range
};

class Identifier {
  const char * value;
  // this is a string!
};

class NamespaceDecl : public Decl {

  // a namespace can be in a namespace
  
};

Translation_Unit_Decl translation_unit_decl ();


NamespaceDecl namespace_decl(Identifier name, Scope scope ,/* Decl decls, this is added in later*/ Source source) {}


Identifier id_scope() {
  // :: the global scope
} 


// the global namespace for a given file
NamespaceDecl global_namespace_decl(Source source) {} 

class Type {};
class Align {
public:
};
class Align_8 : public Align {};

class Size {};


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

class LinkType  {
  // extern 
};

class Used {};

class Func {
public:
  class Body {};
  class Params {
  public:
    class Param {

      Identifier name;
      Type type;
      Scope scpe; // points to the function
      Source srcp;
      Type argt;
      Size size;
      Align algn;
      Used used;
    };
  };

  Identifier name;
  Identifier  mngl;
  FuncType type;
  Scope scpe;
  Source  srcp;
  Decl chain;
  Func::Params args;
  LinkType _extern;

};


class Stmt {};
class Expr {};

Identifier id(const char * string) {}
Type type_int(){}
FuncType function_type() {}
Stmt stmt_return() {}
Decl decl_variable() {}
Type type_name() {}
Decl decl_function() {}
Expr expr_constant() {}
Expr expr_plus_operator() {}
Expr expr_expression() {}
Stmt stmt_statement() {}
Func::Body func_body() {}
Func::Params func_parameters() {}

Func::Params::Param  func_parameter() {}


Decl function_decl( 
		   Identifier name, 
		   Identifier  mngl, 
		   FuncType type,  
		   Scope scpe,     
		   Source  srcp,
		   Decl chain,
		   Func::Params args,
		   LinkType _extern  
		    )
{
};

class String {};

Identifier  identifier_node(String strg);
       
FuncType function_type(Size  size,
		       Align algn,
		       FuncType::Return retn,
		       FuncType::Params prms)
{

}



Func::Params::Param      parm_decl(
			   Identifier name,
			   Type type,
			   Scope scpe,
			   Source srcp,
			   Type argt,
			   Size size,
			   Align algn,
			   Used used)
{
}

class IsSigned {
};

class Unsigned  : public IsSigned{
};

class Signed  : public IsSigned{
};

class Integer {
public:

  class Const {
    Type type;
    int low;
    int high;
  };

  class Type {
    Identifier     name;
    Size  size;
    Align algn;
    int prec;
    IsSigned sign;
    Integer::Const min;
    Integer::Const max;
  };

};

Integer::Type     integer_type(Identifier     name,
			       Size  size,
			       Align algn,      
			       int prec,
			       IsSigned sign,
			       Integer::Const min,
			       Integer::Const max );

class TreeList {};

class ParamTypesList  : public TreeList 
{
  Type valu;
  Rel::Pointer<ParamTypesList> chan;
};

ParamTypesList     tree_list_param( Type valu,      ParamTypesList chan     ) {};
ParamTypesList     tree_list_param( Type valu) {}

class VoidType {
  Identifier    name;
  Align      algn;
};

//
VoidType     void_type(Identifier    name, Align      algn) {};

// constructors 
Integer::Const     integer_cst (Type type,   int low);
Integer::Const     integer_cst (Type type,   int low, int high);

int main(int argc, char ** argv){
  
}
