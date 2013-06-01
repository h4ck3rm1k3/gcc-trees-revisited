#include "namespace.hpp"
#include "id.hpp"
#include "translation_unit.hpp"
#include "node.hpp"
#include "function.hpp"
#include "integer_cst.hpp"
#include "integer_type.hpp"
#include "type_decl.hpp"
#include "list.hpp"
#include "void_type.hpp"

using namespace GCC;

void foo_load() {
  Node unsigned_integer_type;


  Node var3(translation_unit_decl ());
  Node var2(identifier_node({.strg= "::" } ));
  Node var5( identifier_node  ({.strg= "foo"}) );

  Node var6( identifier_node  ({.strg= "_Z3fooi"}));
  Node var28(  identifier_node({.strg= "bitsizetype"}));
  Node var29(  integer_cst().settype(unsigned_integer_type.type()).setlow(64)  );
  Node var30 (    integer_cst().settype(unsigned_integer_type.type()). setlow(0)       );
  Node var31 (    integer_cst()
		  .settype(unsigned_integer_type.type())
		  .sethigh(-1)
		  .setlow(-1)      );




  Node var18(integer_type()
	     .setname(var28.identifier())
	     .setsize(var29.size())
	     .setalgn(64)
	     .setprec(64)
	     .setsign(Unsigned())
	     .setmin(var30.intcst())
	     .setmax(var31.intcst()));

  unsigned_integer_type=var18; // 


  Node var10( integer_cst().settype( var18.type()).setlow(8));

  Node var32 (identifier_node("int"));
  Node int_integer_type; 
  Node var19     =type_decl()  // int
      .setname(var32.identifier())
    .settype(int_integer_type.type())
   .setsrcp("built-in",0)
   .setnoteartificial (); 


  Node var17     =integer_cst().settype(var18.type()).setlow( 32      );

  Node var20=     integer_cst().settype( int_integer_type.type() )
    .sethigh( -1)
    .setlow(-2147483648 );
  
  Node var21 =    integer_cst().settype( int_integer_type.type()). setlow( 2147483647 );

  Node var11(  integer_type()
	       .setname(var19.identifier())
	       .setsize(var17.size())
	       .setalgn(32)
	       .setprec( 32)
	       .setsign(Signed())
	       .setmin(var20.intcst())     
	       .setmax(var21.intcst()));
  int_integer_type = var11;
  
  Node var37(     identifier_node("void"));
  //  Node voidtype;

  TypeDecl voidtypedecl;
  voidtypedecl.setname(var37.identifier())
    .setsrcp("built-in",0)
    .setnoteartificial ();

  Node var33( voidtypedecl);

  Node var23 =    void_type().  setname(var33.identifier() ).setalgn( 8);

  // set the type later after 23 was defclared
  voidtypedecl.settype(var23.type());

  Node var22  =   tree_list().setvalu(var23.list())     ;

  Node var12    = tree_list()        
    .setvalu(var11.type())
    .setchan(var22.list());

  // function 
  Node var7(   function_type()
	       .setsize(var10.size())
	       .setalgn(8)
	       .setretn(var11.type())
	       .setprms(var12.param_list()));

 Node var16     =identifier_node("x");

 GCC::FuncDecl::Params::Param param9 = parm_decl()
    .setname(var16.identifier())
    .settype(var11.type())
    //    .setscpe(var4) later
    .setsrcp("foo.cpp",1)
    .setargt(var11.type())
    .setsize(var17.size())
    .setalgn(32)
    .setused();
 Node var9(param9);

  Node var4(function_decl()
	    .setname(var5.identifier())
	    .setmngl(var6.identifier())
	    .settype(var7.type())
	    .setscpe(var3.scope())
	    .setsrcp("foo.cpp",1)
	    //.chain=var8
	    .setargs(var9.args())
	    .setlinkextern()
	    );

  param9.setscpe(var4.funcdecl());

  Node var1 = namespace_decl ()  
    .setname( var2.identifier())
    .setscpe(var3.scope())
    .setsrcp("<built-in>",0)
    .setdcls(var4.decl_list());


 
				  





};
