#pragma once
namespace GCC 
{

class String {
public:
  String(const char *) ;
};
class Identifier {
  String strg;
  // this is a string!
public:
  Identifier(String & strg);
  Identifier(String strg);
  Identifier(const char * strg);
};
Identifier  identifier_node(String strg);
};
