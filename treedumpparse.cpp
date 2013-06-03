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
 
  void handle_strg(utree s) {
    std::cout << "handle strg:"<< s << std::endl;
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
	    lit('<') >>
	    +(char_("-.a-zA-Z0-9"))  >>
	    lit('>') >> 
	    lit(':') >> 
	    +digit ;
 
	  node_type = 
	    string("namespace_decl")[some_node_type] >> name_field >> scope_field >> source_field
	    | 
	    string("identifier_node")[some_node_type] 
						     >>  strg_field 
						     >>  lngt_field 
	    | string("translation_unit_decl")

	    // generic handler for anything else
	    //	    | (+char_("a-zA-Z0-9_")[some_node_type]) >> * field_value;
  
	    | string("function_type")
	    | string("parm_decl")
	    | string("function_decl") >> + field_value
	    
	    ;
	  
	  
	  mngl_field= string("mngl:") >> node_id[handle_ndref] ;
	  lngt_field =  string("lngt:")>> +(digit[handle_lngt]);
	  name_field   =  string("name:") >>   node_id[handle_name] ;
	  scope_field  =  string("scpe:") >>   node_id[handle_scope] ;
	  source_field =  string("srcp:") >>   filespec[handlefile];	  
	  namespace_decls_field =  string("dcls:") >>   node_id[handle_decls];
	  scope_field = string("scpe:") >> node_id[handle_scope];
	  srcp_field = string("srcp:") >> filespec[handlefile];
	  //	  strg_value =  +(char_("-:_a-zA-Z0-9"));	
	  strg_value =  +(
			  char_('-')
			  | char_('_')
			  | char_(':')
			  |  char_("a-zA-Z0-9")
			  );	
	  strg_field = string("strg:")  >> strg_value[handle_strg];	

	  any_field   =  
	    mngl_field 
	    | lngt_field
	    | name_field
	    | namespace_decls_field
	    | scope_field
	    | source_field
	    | srcp_field 
	    //	    | strg_field

	    | string("algn:") >> +(digit[handle_digits])
	    | string("low:")  >> +(digit[handle_digits])
	    | string("high:") >> -lit('-') >> +(digit[handle_digits])
	    | string("accs:")				
	    | string("argt:")>>   node_id[handle_name]			
	    | string("body:")>> string("undefined")				      				
	    | string("bpos:")				
	    | string("chain:") >>   node_id[handle_name]		
	    | string("domn:")>>   node_id[handle_name]			
	    | string("flds:")	>>   node_id[handle_name]		
	    | string("lang:")  >> string("C")				      
	    | string("link:")  >> string("extern")
	    | string("max:")>>   node_id[handle_name]			
	    | string("min:")>>   node_id[handle_name]			
	    | string("note:") >> (string("artificial") )	  		
	    | string("prec:")						
	    | string("prms:") >>   node_id[handle_name]			
	    | string("ptd:")  >>   node_id[handle_name]			
	    | string("retn:") >>   node_id[handle_name]			
	    | string("sign:") >> string("unsigned")						
	    | string("size:")  >>   node_id[handle_name]
	    | string("tag:")   
	    | string("type:") >>   node_id[handle_name]
	    | string("used:")						
	    | string("valu:") 
	    ;

	  field_value= any_field[some_node_field] ;
	  
	  node_id = 
	    lit('@')
	    >> +digit
	  //   //	    >> *space
	  //   //	    >> *char_
	    ;

	  main_rule = 	  
	    node_id >> 
	    node_type 
	    //+print[foo]
	    ;

	  secondary_line = 	  
	    namespace_decls_field 
	    | + field_value
	    // |	    +print[foo]
	    ;

	  either_lines = main_rule | secondary_line;
	  
        }

      // have no spaces in the values
      qi::rule<InputIterator,  spirit::utree()> 
                 filespec,   
		 strg_value,
		 
		 node_id
		 ;
      

      qi::rule<InputIterator, space_type , spirit::utree()> 
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
		 secondary_line ,
		 either_lines 
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
      std::cout << " Parse Failed: " << std::endl;
      std::cout << str << std::endl;
      std::cout << "-------------------------\n";
    }
  }
  std::cout << "Bye... :-) \n\n";
  return 0;
}
