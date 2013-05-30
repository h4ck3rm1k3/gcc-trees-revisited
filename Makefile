test :
	g++ simple.cpp

dump :
	/usr/lib/gcc/x86_64-linux-gnu/4.7/cc1plus -fdump-translation-unit foo.cpp
