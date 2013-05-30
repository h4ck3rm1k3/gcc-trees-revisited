#include <iostream>
using namespace std;


int foo(int x) {
  return x + 1;
}

int main (int argc, char ** argv)
{
  cout << "hello world" << endl;
  cout << "foo" << foo(1) << endl;
}
