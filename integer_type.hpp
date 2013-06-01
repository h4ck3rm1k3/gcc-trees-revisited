#pragma once 
namespace GCC {
namespace Integer 
{
  class Type {
    Identifier     name;
    Size  size;
    Align algn;
    int prec;
    IsSigned sign;
    Integer::Const min;
    Integer::Const max;

  public:

    Type & setname (Identifier     name);
    Type & setsize(Size  size);
    Type & setalgn(  int  algn);
    Type & setprec(    int prec);
    Type & setsign(    IsSigned sign);
    Type & setmin(    Integer::Const min);
    Type & setmax(    Integer::Const max);

  };
};

Integer::Type     integer_type();

};
