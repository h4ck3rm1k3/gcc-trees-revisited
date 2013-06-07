/*=============================================================================
    Copyright (c) 2013 James Michael DuPont
    
=============================================================================*/

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_utree.hpp>
#include <iostream>
#include <ostream>
#include <string>

using boost::spirit::ascii::space;
using boost::spirit::ascii::space_type; 
using boost::spirit::ascii::char_;
using boost::spirit::ascii::digit;
using boost::spirit::ascii::string;
using boost::spirit::ascii::alnum;
using boost::spirit::ascii::print;
using boost::spirit::ascii::graph;


using boost::spirit::qi::lit;
namespace qi = boost::spirit::qi;
namespace spirit = boost::spirit;
using boost::spirit::utree;

namespace client
{

  void some_node_type(utree s) {
    std::cout << "node_type:"<< s << std::endl;
  }

  void some_node_field(utree s) {
    std::cout << "field:"<< s << std::endl;
  }

  void handle_ndref(utree s) {
    std::cout << "node ref:"<< s << std::endl;
  }

  void handle_nddecl(utree s) {
    std::cout << "node decl:"<< s << std::endl;
  }

  void handlefile(utree s) {
    std::cout << "handle file:"<< s << std::endl;
  }

  void handle_name(utree s) {
    std::cout << "handle name:"<< s << std::endl;
  }

  void handle_scope(utree s) {
    std::cout << "handle scope:"<< s << std::endl;
  }

  void handle_decls(utree s) {
    std::cout << "handle decls:"<< s << std::endl;
  }

  
  void handle_lngt(utree s) {
    std::cout << "handle lngt:"<< s << std::endl;
  }

  void handle_digits(utree s) {
    std::cout << "handle digits:"<< s << std::endl;
  }

  void handle_new_field(utree s) {
    std::cout << "handle_new_field:"<< s << std::endl;
  }

  void handle_strg(utree s) {
    std::cout << "handle strg:"<< s << std::endl;
  }

  void handle_any(utree s) {
    std::cout << "handle any:"<< s << std::endl;
  }

  void foo(char c) {
    std::cout << "char 1:"<< c << std::endl;
  }

  void foo2(char c) {
    std::cout << "char 2:"<< c << std::endl;
  }

    template <typename InputIterator>
    struct tree_dump_file
        : qi::grammar<
      InputIterator, 
      space_type, 
      utree()    
      >
    {
        tree_dump_file()   : tree_dump_file::base_type(either_lines)
        {  
	  
	  filespec     =  
	     (string("<built-in>:0") |
	      (
	       +(char_("-.a-zA-Z0-9"))  >>
	       lit(':') >> 
	       +digit
	       )
	      )
	    ;
 
	  identifier_node =(
			    ( 
			     strg_field
			     >>  -lngt_field 
			      )
			    |    note_field
			    );
	  

	  node_type = 
	     string("namespace_decl")[some_node_type] >> name_field >> scope_field >> source_field
	    | string("array_type")
	    | string("boolean_type")
	    | string("complex_type")
	    | string("constructor") // for C++
	    | string("field_decl")

	    | string("nop_expr")
	    | string("addr_expr")
| string("array_ref") |
string("arrow_expr") |
string("baselink") |
string("bind_expr") |
string("binfo") |
string("bit_and_expr") |
string("bit_ior_expr") |
string("bit_not_expr") |
string("bound_template_template_parm") |
string("break_stmt") |
string("call_expr") |
string("cast_expr") |
string("component_ref") |
string("compound_expr") |
string("cond_expr") |
string("const_cast_expr") |
string("const_decl") |
string("ctor_initializer") |
string("decl_expr") |
string("dl_expr") |
string("dotstar_expr") |
string("enumeral_type") |
string("eq_expr") |
string("error_mark") |
string("expr_stmt") |
string("for_stmt") |
string("ge_expr") |
string("gt_expr") |
string("handler") |
string("identifier_node") |
string("if_stmt") |
string("indirect_ref") |
string("le_expr") |
string("lshift_expr") |
string("lt_expr") |
string("member_ref") |
string("method_type") |
string("minus_expr") |
string("modop_expr") |
string("mult_expr") |
string("namespace_decl") |
string("ne_expr") |
string("negate_expr") |
string("nw_expr") |
string("offset_type") |
string("overload") |
string("Parse") |
string("plus_expr") |
string("postdecrement_expr") |
string("postincrement_expr") |
string("predecrement_expr") |
string("preincrement_expr") |
string("real_cst") |
string("reinterpret_cast_expr") |
string("return_expr") |
string("rshift_expr") |
string("scope_ref") |
string("sizeof_expr") |
string("statement_list") |
string("static_cast_expr") |
string("string_cst") |
string("switch_stmt") |
string("tag_defn") |
string("template_decl") |
string("template_id_expr") |
string("template_parm_index") |
string("template_template_parm") |
string("template_type_parm") |
string("throw_expr") |
string("trait_expr") |
string("tree_vec") |
string("trunc_div_expr") |
string("trunc_mod_expr") |
string("truth_andif_expr") |
string("truth_not_expr") |
string("truth_orif_expr") |
string("try_block") |
string("typeid_expr") |
string("typename_type") |
string("typeof_type") |
string("union_type") |
string("using_decl") |
string("using_stmt") |
string("while_stmt") 

	    // more 
	    | 
	    string("alignof_expr") |
	    string("case_label_expr") |
	    string("do_stmt") |
	    string("label_decl") 

| 
	    // more
	    string("bit_xor_expr") |
	    string("continue_stmt") |
	    string("decltype_type") |
	    string("unary_plus_expr") 
	    
	    | string("function_decl") >> + field_value
	    | string("function_type")
	    | string("integer_cst")
	    | string("integer_type")
	    | string("lang_type")
	    | string("parm_decl")
	    | string("pointer_type")
	    | string("real_type")
	    | string("record_type")
	    | string("reference_type")
	    | string("string_cst") >> 	      type_field >> strg_field	     >>  -lngt_field 	    
	    | string("translation_unit_decl")
	    | string("tree_list")
	    | string("type_decl")
	    | string("vector_type")
	    | string("void_type")
	    | string("var_decl")
	    | string("identifier_node")   >> identifier_node
	    ;
	  
	  
	  mngl_field= string("mngl:") >> node_id[handle_ndref] ;
	  lngt_field =  string("lngt:")>> +(digit[handle_lngt]);
	  name_field   =  string("name:") >>   node_id[handle_name] ;
	  scope_field  =  string("scpe:") >>   node_id[handle_scope] ;
	  source_field =  string("srcp:")[handle_any] >>   filespec[handlefile];	  
	  namespace_decls_field =  string("dcls:") >>   node_id[handle_decls];
	  srcp_field = string("srcp:") >> filespec[handlefile];
	  strg_value = (+(
	     		  char_('-')
	     		  | char_('_')
	     		  | char_(':')
	     		  |  char_("a-zA-Z0-9")
			  ))
	    | (
string("global type") 
| string("complex") >> string("double")
| string("complex") >> string("float") 
| string("__int128")>> string("unsigned")
| string("complex") >> string("int") 
| string("complex") >> string("long") >> string("double")
| string("init") >> string("list")
| string("long") >> string("double")
| string("long") >> string("int")
| string("long") >> string("unsigned") >> string("int") 
| string("unsigned") >> string("int")
| string("unsigned") >> string("char")
| string("signed") >> string("char")
| string("short") >> string("int")
| string("short") >> string("unsigned") >> string("int")
| string("undeduced") >> string ("lambda") >> string ("return") >> string ("type")
| string("unknown") >>  string("type") 

	       )
	    ;
	
	  strg_field = 
	    string("strg:")  >> strg_value[handle_strg]
	    ;	

	   bits= (	   	 
		  string("1")
		 | string("256")
		 | string("128")
	   	 | string("64")
	   	 | string("32")
	   	 | string("16")
	   	 | string("8")
	   	 );

	  note_field = 
	    string("note:") >> (
				string("artificial")  |
				string("operator")   |
				string("member")   |
				string("pseudo") >>   string("tmpl") 
				)
	    ;


	  any_field   =  
	    mngl_field 
	    | lngt_field
	    | name_field
	    | namespace_decls_field
	    | scope_field
	    | source_field
	    | srcp_field 
	    | strg_field	    
	    | string("algn:") >> bits
	    | string("init:")>>   node_id[handle_ndref]			
	    | string("low :")  >> +(digit[handle_digits])
	    | string("high:") >> -lit('-') >> +(digit[handle_digits])
	    | string("accs:") >> (
				  string("pub")	 |
				  string("priv")	 |
				  string("prot")	 
				  )
	    | string("argt:")>>   node_id[handle_ndref]			

	    | string("cnst:")>>   node_id[handle_ndref]			
	    | string("rslt:")>>   node_id[handle_ndref]			
	    | string("init:")>>   node_id[handle_ndref]			
	    | string("base:")>>   node_id[handle_ndref]			

	    | string("spec:") >> string("virt")

	    ///array 
	    | +(digit[handle_digits]) >> string("    :")>>   node_id[handle_ndref]			

	    
	    | string("vfld:")>>   node_id[handle_ndref]

	    | string("body:")>> string("undefined")   
	    | string("bpos:")  >>   node_id[handle_ndref]
	    | string("chain:") >>   node_id[handle_ndref]
	    | string("domn:")>>   node_id[handle_ndref]			
	    | string("elts:")	>>   node_id[handle_ndref]		
	    | string("binf:")	>>   node_id[handle_ndref]		
	    | string("flds:")	>>   node_id[handle_ndref]		
	    | string("lang:")  >> string("C")	       
   	    | string("link:")  >> string("extern")
	    | string("max :")>>   node_id[handle_ndref]			
	    | string("min:")>>   node_id[handle_ndref]			
	    | note_field
	    | string("prec:") >>  bits   
	    | string("prms:") >>   node_id[handle_ndref]			
	    | string("ptd :")  >>   node_id[handle_ndref]			
	    | string("retn:") >>   node_id[handle_ndref]			
	    | string("sign:") >> (
				  string("signed")   |
				  string("unsigned")	      
				  )
	    | string("size:")  >>   node_id[handle_ndref]
	    | string("tag :")   >> string("struct")
	    | type_field
	    | string("used:") >> +(digit[handle_digits])     
	    | string("valu:") >>   node_id[handle_ndref]
	    | string("idx :") >>   node_id[handle_ndref] // for constructor
	    | string("op") >> string("0:") >>   node_id[handle_ndref] // for constructor
	    | string("op") >> string("1:") >>   node_id[handle_ndref] // for constructor
	    | string("val :") >>   node_id[handle_ndref] // for constructor

	    | new_field_name[handle_new_field] >>   node_id[handle_ndref] // for constructor
	    ;

	  new_field_name = (+char_("a-z_"));

	  type_field= string("type:") >>   node_id[handle_ndref];

	  field_value= 
	    any_field[some_node_field] 
	    ;
	  
	  node_id = 
	    lit('@')
	    >> +digit
	    ;

	  main_rule = 	  
	    node_id[handle_nddecl] >> 
	    node_type 
	    ;

	  secondary_line = 
	    namespace_decls_field 
	    | + field_value
	    ;

	  either_lines = 
	    main_rule | secondary_line
	    ;
	  
        }

      // have no spaces in the values
      qi::rule<InputIterator,  spirit::utree()> 	  
      filespec,   
	  node_id,
	  bits,
	  strg_value	  
      ;
      
      
      // more complex space separated rules
      qi::rule<InputIterator, space_type , spirit::utree()> 
		 ////////////////////////////

      main_rule,
	any_field,
	node_type,	 
	field_value,
	lngt_field,
	mngl_field,
	name_field,
	namespace_decls_field,
	scope_field,
	source_field,
	srcp_field,
	strg_field, 
	note_field,
	secondary_line ,
	either_lines ,
	identifier_node,
	type_field,
	new_field_name
	;
      
    };

}

///////////////////////////////////////////////////////////////////////////////
//  Main program
///////////////////////////////////////////////////////////////////////////////


int
main()
{
  typedef std::string::const_iterator iterator_type;
  std::string parsed;
  std::cout << "GCC tree parser for Spirit...\n\n";
  std::string str;
  client::tree_dump_file<iterator_type> p;
  utree ut;
  while (getline(std::cin, str))    {     
    std::string::const_iterator iter = str.begin();
    std::string::const_iterator end = str.end();
    if (phrase_parse (
			iter, 
			end, 
			p,
			space,
			ut
			)
	)
      {
	std::cout << "-------------------------\n";
	std::cout << "Parsing succeeded\n";
	std::cout << str << " Parses OK: " << std::endl;
      } else  {
      std::cout << "\n-------------------------\n";
      std::cout << " Parse Failed: " << str << std::endl;
      std::cout << "-------------------------\n";
    }
  }
  std::cout << "Bye... :-) \n\n";
  return 0;
}
