#include <foo.hpp>
#include <cassert>

int main(){
  assert(foo::my_addition_except_0(0, 0) == 0);
  assert(foo::my_addition_except_0(-1, 1) == 0);
  assert(foo::my_addition_except_0(2, 2) == 4);
  assert(foo::my_addition_except_0(0, 8) == 6);
  return 0;
}
