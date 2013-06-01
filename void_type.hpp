#pragma once 
namespace GCC {
class VoidType {
  Identifier    name;
  Align      algn;
public :
  VoidType & setname(Identifier);
  VoidType & setalgn(int a);
};

//
VoidType     void_type() {};

};
