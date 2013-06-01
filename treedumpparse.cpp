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
    std::string match;    
    bool r = phrase_parse(
			  first,                          /*< start iterator >*/
			  last,                           /*< end iterator >*/
			  * (
			     '@' >> ulong_ >> * (char_)	     			     
			     >> 
			     * (  * (char_) >>		 ':' >>		 * (char_)		 )
			     
			     ),   /*< the parser >*/
			  space,                           /*< the skip-parser >*/
			  match
			  );
    if (first != last) // fail if we did not get a full match
      {
	cout << "fail1:" << match << endl;
	return false;
      }  
    cout << match << endl;
    return r;
  }
  
  template <typename Iterator> bool parse_tree_attr(Iterator first, Iterator last)
  {
    std::string match;
    bool r = phrase_parse(
			  first,                          /*< start iterator >*/
			  last,                           /*< end iterator >*/
			  
			  * (
			     (
			      string("algn") |
			      string("argt") |
			      string("body") |
			      string("chain") |
			      string("dcls") |
			      string("lang") |
			      string("lngt") |
			      string("link") |
			      string("accs") |
			      string("bpos") |
			      string("domn") |
			      string("ptd") |
			      string("min") |
			      string("tag") |
			      string("flds") |
			      string("max") |
			      string("note") |
			      string("prec") |
			      string("retn") |
			      string("prms") |
			      string("scpe") |
			      string("sign") |
			      string("size") |
			      string("srcp") |
			      string("used") |
			      *(char_)
			      ) 
			     >>	':' 
			     >>	
			     (
			      * (char_)		 |
			      string("operator") >> (
						     * (char_)
						     )
			      )
			     )
			  
			  ,   /*< the parser >*/
			  space,                           /*< the skip-parser >*/
			  match
			  );
    if (first != last) // fail if we did not get a full match
      {
	cout << "fail2:" << match << endl;
	return false;
      }
    cout << "match2:" << match << endl;
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
