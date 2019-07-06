#include <range/v3/all.hpp>
#include <iostream>

using namespace ranges;

int main()
{
  std::cout << std::endl;

  auto odds = view::ints( 1, ranges::unreachable ) | view::for_each( []( int i ) { return yield_if( i % 2 == 1, i * i ); } );

  ranges::for_each( odds | view::take_while( []( int i ) { return i < 1000; } ), []( int i ) {
    std::cout << i << " ";
  } );

  std::cout << "\n\n";

}
