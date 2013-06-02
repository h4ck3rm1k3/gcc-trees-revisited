testparser : testparse
	cat foo.cpp.001t.tu | ./testparse

headers : decl.hpp         integer_type.hpp  node.hpp         translation_unit.hpp function.hpp     link.hpp          record_type.hpp  type_decl.hpp id.hpp           list.hpp          rel.hpp          type.hpp integer_cst.hpp  namespace.hpp     scope.hpp        void_type.hpp
	echo

testparse : treedumpparse.cpp decl.hpp         integer_type.hpp  node.hpp         translation_unit.hpp function.hpp     link.hpp          record_type.hpp  type_decl.hpp id.hpp           list.hpp          rel.hpp          type.hpp integer_cst.hpp  namespace.hpp     scope.hpp        void_type.hpp
	g++ -std=gnu++11 treedumpparse.cpp -o testparse

testtre :
	g++ -std=gnu++11 foo_load.cpp

test1 :
	g++ -std=gnu++11 simple.cpp

dump :
	/usr/lib/gcc/x86_64-linux-gnu/4.7/cc1plus -fdump-translation-unit foo.cpp
