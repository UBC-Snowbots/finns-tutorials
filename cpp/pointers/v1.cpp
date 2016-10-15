#include <iostream>

class MyDependency{
public:
  void do_thing(){
    std::cout << "thing" << std::endl;
  }
};

class MyClass{
  MyDependency* my_dep;
public:
  MyClass(){
    my_dep = new MyDependency();
  }
  void do_thing(){
    my_dep->do_thing();
  }
  ~MyClass(){
    delete my_dep;
  }
};

int main(){
  MyClass* m = new MyClass();
  m->do_thing();
  delete m;
  return 0;
}
