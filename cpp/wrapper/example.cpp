#include <iostream>
#include <memory>


struct data_t{
  int a,b;
};

data_t* make_data(int a, int b){
  return new data_t{a,b};
}

void data_do_thing(data_t* d){
  std::cout << d->b << std::endl;
}

void free_data(data_t* d){
  delete d;
}

/// end C-style interface

// begin C++ wrapper

class data{
  std::unique_ptr<data_t,void(*)(data_t*)> ptr;
public:
  data(int a, int b):
    ptr{make_data(a,b),free_data}
  {}
  void do_thing(){
    data_do_thing(ptr.get());
  }
};

int main(){
  data d{1,2};
  d.do_thing();
  return 0;
}
