#include <iostream>

class MyContainer{
public:
  class interface{
    MyContainer& c;
  protected:
    interface(MyContainer& c): c{c}{}
  public:
    void thing(){
      c.thing();
    }
    friend class MyContainer;
  };
  interface make_interface(){
    return interface{*this};
  }
  void thing(){
    std::cout << "thing" << std::endl;
  }
};

int main(){
  MyContainer().make_interface().thing();
  return 0;
}
