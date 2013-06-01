
namespace Integer {
  class Const {
    Type type;
    int low;
    int high;
  };

};

// constructors 
Integer::Const     integer_cst (Type type,   int low);
Integer::Const     integer_cst (Type type,   int low, int high);
