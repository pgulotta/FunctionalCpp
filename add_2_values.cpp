#include <iostream>


template<typename I, typename J>
auto add( I i, J j ) -> decltype( i + j )
{
  return i + j;
}

auto main() -> int
{
  auto s1{"abcdef"};
  auto s2{"ghij"};
  std::cout << "s1=" << s1 << " s2=" << s2 << "  result=" << add<std::string, std::string>( s1, s2 ) << std::endl;

  std::string s3{"abcdef"};
  std::string s4{"ghij"};
  std::cout << "s3=" << s3 << " s4=" << s4 << "  result=" << add<>( s3, s4 ) << std::endl;

  auto i1{555};
  auto i2{444};
  std::cout << "i1=" << i1 << " i2=" << i2 << "  result=" << add<>( i1, i2 ) << std::endl;

  auto i3{555.5};
  auto i4{444.4};
  std::cout << "i3=" << i3 << " i4=" << i4 << "  result=" << add<>( i1, i2 ) << std::endl;
  return 0;
}
