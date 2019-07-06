#include <range/v3/all.hpp>
#include <iostream>
#include <tuple>

using namespace ranges;

int main()
{
  std::cout << std::endl;

  auto odds = view::ints( 1, ranges::unreachable ) | view::for_each( []( int i ) { return yield_if( i % 2 == 1, i * i ); } );

  ranges::for_each( odds | view::take_while( []( int i ) { return i < 1000000; } ), []( int i ) {
    std::cout << i << " ";
  } );

  std::cout << "\n\n";

  auto triples =
  view::for_each( view::ints( 1, ranges::unreachable ), []( int z ) {
    return view::for_each( view::ints( 1, z ), [ = ]( int x ) {
      return view::for_each( view::ints( x, z ), [ = ]( int y ) {
        return yield_if( x * x + y * y == z * z, std::make_tuple( x, y, z ) );
      } );
    } );
  } );

  auto resultVector = triples | view::take_exactly( 7 ) | to_vector;

  std::cout << "triples size = " << resultVector.size() << "\n\n";
}



