#pragma once

#include "type.hpp"

namespace GCC {
namespace Integer {
  class Const {

    Type _type;
    int _low;
    int _high;

  public:
    Const & settype(Type t); // set the type 
    Const & setlow(int low ); // set the type 
    Const & sethigh(int high ); // set the type 


  public :
    Const(   Type type,	      int low);
  };

};

// constructors 
Integer::Const     integer_cst ();
Integer::Const     integer_cst (Type type,   int low);
//Integer::Const     integer_cst (Type type,   int low, int high);
};
