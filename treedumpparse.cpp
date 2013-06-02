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
using boost::spirit::ascii::digit;

using boost::spirit::qi::lit;
namespace qi = boost::spirit::qi;
namespace spirit = boost::spirit;
using boost::spirit::utree;

namespace client
{

  void some_node_type(utree s) {
    std::cout << "node_type:"<< s << std::endl;
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

  void foo(char c) {
    std::cout << "char 1:"<< c << std::endl;
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
	  name_field   =  string("name") >>  lit(':')>> node_id[handle_name] ;
	  scope_field  =  string("scpe") >>  lit(':')>> node_id[handle_scope] ;
	  source_field =  string("srcp") >>  lit(':')>> filespec[handlefile];
	  namespace_decls_field =  string("dcls") >>  lit(':')>> node_id[handle_decls];


	  filespec     =  
	    lit('<') >>
	    +(char_("-.a-zA-Z0-9"))  >>
	    lit('>') >> 
	    lit(':') >> 
	    +digit ;
 
	  node_type = 
	    string("namespace_decl")[some_node_type] >> name_field >> scope_field >> source_field
	    //        srcp: <built-in>:0      

	    | string("identifier_node")
	    | string("function_type")
	    | string("parm_decl")
	    | string("function_decl")
	    | string("translation_unit_decl")
	    | (*alnum);
	    
	  node_id = 
	    lit('@')
	    >> +digit
	  //   //	    >> *space
	  //   //	    >> *char_
	    ;

	  main_rule = 	  
		 node_id >> 
		 node_type >>
	         *char_[foo];

	  secondary_line = 	  
	    namespace_decls_field |
	    *char_[foo];

	  either_lines = main_rule | secondary_line;
	  
        }

      qi::rule<InputIterator, space_type , spirit::utree()> main_rule;
      qi::rule<InputIterator, space_type , spirit::utree()> node_id;
      qi::rule<InputIterator, space_type , spirit::utree()> node_type;
      qi::rule<InputIterator, space_type , spirit::utree()> name_field;
      qi::rule<InputIterator, space_type , spirit::utree()> scope_field;
      qi::rule<InputIterator, space_type , spirit::utree()> source_field;
      qi::rule<InputIterator, spirit::utree()> filespec;
      qi::rule<InputIterator, space_type , spirit::utree()>  namespace_decls_field;
      qi::rule<InputIterator, space_type , spirit::utree()>  secondary_line ;
      qi::rule<InputIterator, space_type , spirit::utree()>  either_lines ;

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
