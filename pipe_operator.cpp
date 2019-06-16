#include <type_traits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iterator>

template <typename T>
struct ContainsProxy { const T& value_; };

template <typename Range, typename T>
auto operator|( const Range& r, const ContainsProxy<T>& proxy )
{
  const auto& v = proxy.value_;
  return std::find( r.begin(), r.end(), v ) != r.end();
}

template <typename T>
auto contains( const T& v ) { return ContainsProxy<T> {v}; }


int main( int, char* [] )
{
  auto numbers = std::vector<int> {1, 3, 5, 7, 9};
  auto seven = 7;
  auto proxy = ContainsProxy<decltype( seven )> {seven};
  bool result7 = numbers | proxy;
  std::cout << "result7 = " << result7 << std::endl;

  auto penguins = std::vector<std::string> {"Ping", "Roy", "Silo"};
  bool resultSilo = penguins | contains( "Silo" );
  std::cout << "resultSilo = " << resultSilo << std::endl;


  return 0;
}
