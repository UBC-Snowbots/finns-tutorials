#include <foo.hpp>

namespace foo{
  int my_addition_except_0(int const a, int const b){
    if(a == 0){
      return 6;
    }else{
      return a+b;
    }
  }
}
