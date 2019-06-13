#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iostream>


typedef std::function<double( double )> HyperbolicFunc;


std::vector<HyperbolicFunc> funcs = {
  sinh,
  cosh,
  tanh,
  []( double x )
  {
    return x * x;
  }
};

std::vector<HyperbolicFunc> inverseFuncs = {
  asinh,
  acosh,
  atanh,
  []( double x )
  {
    return exp( log( x ) / 2 );
  }
};


template <typename A, typename B, typename C>
std::function<C( A )> compose(
  std::function<C( B )> f,
  std::function<B( A )> g )
{
  return [f, g]( A x ) {
    return f( g( x ) );
  };
}

auto main() -> int
{
  std::vector<HyperbolicFunc> composedFuncs;
  std::vector<double> nums;

  for ( int i = 1; i <= 5; ++i ) {
    nums.push_back( i * 0.2 );
  }


  transform(
    begin( inverseFuncs ),
    end( inverseFuncs ),
    begin( funcs ),
    back_inserter( composedFuncs ),
    compose<double, double, double> );

  for ( auto num : nums ) {
    for ( auto func : composedFuncs ) {
      std::cout << "f(g(" << num << ")) = " << func( num ) << std::endl;
    }

    std::cout << "---------------" << std::endl;
  }

  return 0;
}
