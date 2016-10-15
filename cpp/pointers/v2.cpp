#include <iostream>
#include <memory>

class MyDependency{
public:
  void do_thing(){
    std::cout << "thing" << std::endl;
  }
};

class MyClass{
  std::unique_ptr<MyDependency> my_dep;
public:
  MyClass(){
    my_dep = std::make_unique<MyDependency>();
  }
  void do_thing(){
    my_dep->do_thing();
  }
};

int main(){
  MyClass m ;
  m.do_thing();
  return 0;
}
