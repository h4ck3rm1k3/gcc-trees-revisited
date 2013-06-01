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
  };
};

Integer::Type     integer_type(Identifier     name,
			       Size  size,
			       Align algn,      
			       int prec,
			       IsSigned sign,
			       Integer::Const min,
			       Integer::Const max );

