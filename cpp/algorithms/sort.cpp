#include <iostream>
#include <algorithm>

int main(){
  std::vector<int> v{5,6,7,9,4,1,3,6};
  std::sort(v.begin(),v.end());
  for(auto const& i: v){
    std::cout << i << std::endl;
  }
  return 0;
}
