#include <range/v3/all.hpp>
#include <numeric>
#include <iostream>

using namespace ranges;

int main()
{
  std::cout << std::endl;

  auto oddSquareNumbers = view::ints( 1, ranges::unreachable )
  | view::transform( []( int i ) { return i * i;} )
  | view::remove_if( []( int i ) { return i % 2 == 0; } )
  | view::take_while( []( int i ) { return i < 10000;} );

  ranges::for_each( oddSquareNumbers, []( int i ) { std::cout << i << " "; } );
  std::cout << "\n\n";

  // total= sum $ take 100 $ map (\x -> x*x) [100..1000] -- 2318350
  auto total = ranges::accumulate( view::ints( 100, 100000 )
  | view::transform( []( int x ) { return x * x; } )
  | view::take( 1000 ), 0 );

  std::cout << "total: " << total << std::endl << std::endl;

}



