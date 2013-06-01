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

    ///////////////////////////////////////////////////////////////////////////
    //  Our number list parser
    ///////////////////////////////////////////////////////////////////////////
    //[tutorial_numlist1
    template <typename Iterator>
    bool parse_tree(Iterator first, Iterator last)
    {
        using qi::ulong_;
        using qi::lit;
        using qi::char_;
        using qi::phrase_parse;
        using ascii::space;

	std::string match;

        bool r = phrase_parse(
            first,                          /*< start iterator >*/
            last,                           /*< end iterator >*/
            *('@' >> ulong_ >> * (char_) >> 
	      
	      /*
		
	       */
	      * (
		 * (char_) >>
		 ':' >>
		 * (char_)
		 )
	      
	      ),   /*< the parser >*/
            space,                           /*< the skip-parser >*/
	    match
        );
        if (first != last) // fail if we did not get a full match
            return false;
	cout << match << endl;
        return r;
    }
    //]
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
            std::cout << "-------------------------\n";
            std::cout << "Parsing failed\n";
            std::cout << "-------------------------\n";
        }
    }

    std::cout << "Bye... :-) \n\n";
    return 0;
}
