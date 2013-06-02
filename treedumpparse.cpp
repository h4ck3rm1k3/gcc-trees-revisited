/*=============================================================================
    Copyright (c) 2013 James Michael DuPont
Derived from 
http://www.boost.org/doc/libs/1_41_0/libs/spirit/doc/html/spirit/qi/reference/basics.html#spirit.qi.reference.basics.examples
=============================================================================*/

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace client
{
  namespace qi = boost::spirit::qi;
  namespace ascii = boost::spirit::ascii;
  using qi::ulong_;
  using qi::lit;
  using qi::char_;
  using qi::phrase_parse;
  using ascii::space;
  using boost::spirit::qi::repeat;
  using boost::spirit::qi::lit;
  using boost::spirit::ascii::string;

  template <typename Iterator>  bool parse_tree(Iterator first, Iterator last)
  {
    std::vector<std::string> match;    
    bool r = phrase_parse(
			  first,                          /*< start iterator >*/
			  last,                           /*< end iterator >*/
			  * (
			     '@' >>  char_("0-9")    >> * (char_) 
			     >> 
			     * (  
			      string("algn") 
			      | string("accs") 
			      | string("argt") 
			      | string("body") 
			      | string("bpos") 
			      | string("chain")
			      | string("dcls") 
			      | string("domn") 
			      | string("flds") 
			      | string("lang") 
			      | string("link")
			      | string("lngt") 
			      | string("max") 
			      | string("min") 
			      | string("mngl") 
			      | string("note") 
			      | string("name") 
			      | string("prec") 
			      | string("prms") 
			      | string("ptd") 
			      | string("retn") 
			      | string("scpe")
			      | string("sign")
			      | string("size")
			      | string("srcp") 
			      | string("strg") 
			      | string("tag") 
			      | string("type") 
			      | string("used") 
			      | string("valu") 

			      //* (char_) 
			      >>		 ':' >>		 * (char_)		 )
			     
			     ),   /*< the parser >*/
			  space,                           /*< the skip-parser >*/
			  match
			  );
    cout << "Match out:" << endl;   
    for (std::vector<std::string>::iterator it = match.begin() ; it != match.end(); ++it)   {
      std::cout << *it << endl;
    }

    if (first != last) // fail if we did not get a full match
      {
	//	cout << "failed1:" << endl;   
	return false;
      }  
    cout << "match1:" << endl;   
    return r;
  }
  
  template <typename Iterator> bool parse_tree_attr(Iterator first, Iterator last)
  {
    std::vector<std::string> match;    
    bool r = phrase_parse(
			  first,                          /*< start iterator >*/
			  last,                           /*< end iterator >*/			  
			  * (
			     (
			      string("algn") 
			      | string("accs") 
			      | string("argt") 
			      | string("body") 
			      | string("bpos") 
			      | string("chain")
			      | string("dcls") 
			      | string("domn") 
			      | string("flds") 
			      | string("lang") 
			      | string("link")
			      | string("lngt") 
			      | string("max") 
			      | string("min") 
			      | string("note") 
			      | string("prec") 
			      | string("prms") 
			      | string("ptd") 
			      | string("retn") 
			      | string("scpe")
			      | string("sign")
			      | string("size")
			      | string("srcp") 
			      | string("tag") 
			      | string("type") 
			      | string("used") 
			      | string("valu") 
			      //			      |  			      *(char_)
			      ) 
			     >>	':' 
			     >>	
			     (
			      //string("artificial") 
			      string("operator") >> (   * (char_)     )
			      | * (char_)		
			      		      
			      )
			     )
			  
			  ,   /*< the parser >*/
			  space,                           /*< the skip-parser >*/
			  match
			  );

    cout << "Match2:" << endl;    
    for (std::vector<std::string>::iterator it = match.begin() ; it != match.end(); ++it)      {
	std::cout << *it << endl;
      }

    if (first != last)       {
	cout << "fail2:" << endl;    
	return false;
      }
    cout << "match2:" << endl;

    return r;
  }
  
}

////////////////////////////////////////////////////////////////////////////
//  Main program
////////////////////////////////////////////////////////////////////////////
int
main()
{
    std::cout << "GCC tree parser for Spirit...\n\n";

    std::string str;
    while (getline(std::cin, str))
    {
        if (client::parse_tree(str.begin(), str.end()))
        {
            std::cout << "-------------------------\n";
            std::cout << "Parsing succeeded\n";
            std::cout << str << " Parses OK: " << std::endl;
        }
        else 
	  {
	    if (client::parse_tree_attr(str.begin(), str.end()))
	      {
	     	std::cout << "-------------------------\n";
	     	std::cout << "Continue Parsing succeeded\n";
	     	std::cout << str << " Parses OK with second function: " << std::endl;
	      }
	    else
	      {
		std::cout << "\n-------------------------\n";
		std::cout << " Parse Failed: " << std::endl;
		std::cout << str << std::endl;
		std::cout << "-------------------------\n";
	      }
	  }
    }	
    std::cout << "Bye... :-) \n\n";
    return 0;
}
