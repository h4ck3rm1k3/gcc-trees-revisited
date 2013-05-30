class Decl {};
class Scope {};
class Translation_Unit_Decl  : /*public Decl,*/ public Scope {};
class Decls {};
class Source {};


class Identifier {};
class Namespace {};
Translation_Unit_Decl translation_unit_decl ();


Namespace namespace_decl(Identifier name, Scope scope ,/* Decl decls, this is added in later*/ Source source) {}
/*
@1      namespace_decl   name: @2       scpe: @3       srcp: <built-in>:0      
                         dcls: @4      
@2      identifier_node  strg: ::       lngt: 2       
@3      translation_unit_decl 
*/

Identifier id_scope() {
  // :: the global scope
} 

Namespace global_namespace_decl(Source source) {}

class Type {};
class Func {
public:
  class Body {};
  class Params {
  public:
    class Param {
    };
  };
};

class FuncType {
public:

  class Return {};

  class Params {
  public:
    class Param {
    };
  };

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
class LinkType  {};

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
class Align {
public:
};
class Align_8 : public Align {};

class Size {};

Identifier  identifier_node(String strg);
       
FuncType function_type(Size  size,
		       Align algn,
		       FuncType::Return retn,
		       FuncType::Params prms)
{

}

class Used {};

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

class Integer {
public:

  class Const {};
  class Type {};

};

Integer::Const     integer_cst (Type type,
			    int low);

class IsSigned {
};

class Unsigned  : public IsSigned{
};

class Signed  : public IsSigned{
};


Integer::Type     integer_type(Identifier     name,
			       Size  size,
			       Align algn,      
			       int prec,
			       IsSigned sign,
			       Integer::Const min,
			       Integer::Const max );

class ParamsList {};
ParamsList     tree_list_param( Type valu,      ParamsList chan     ) {};
ParamsList     tree_list_param( Type valu) {}
class VoidType {};
VoidType     void_type(Identifier    name, Align      algn) {};




int main(int argc, char ** argv){
  
}
