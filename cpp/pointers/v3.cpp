#include <iostream>
#include <memory>

class MyDependency{
public:
  void do_thing(){
    std::cout << "thing" << std::endl;
  }
};

class MyClass{
  MyDependency my_dep;
public:
  void do_thing(){
    my_dep.do_thing();
  }
};

int main(){
  MyClass m ;
  m.do_thing();
  return 0;
}
