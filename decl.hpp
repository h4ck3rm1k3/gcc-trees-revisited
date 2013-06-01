#include "rel.hpp"

namespace GCC { 
class Used {};

class Decl {
public:
  Rel::TIsContained<Scope> contained_in_scope;
  Source source;
};

};
