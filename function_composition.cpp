#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iostream>



// A function that pass a double argument and return an double value
using  FunctionDefn = std::function<double( double )> ;


// Initializing a vector containing four functions
static std::vector<FunctionDefn> functions = {
  sinh,
  cosh,
  tanh,
  log,
  []( double x )
  {
    return x * x;
  },
  []( double x )
  {
    return ( x - 32.0 ) *  5.0 / 9.0;
  }
};

// Initializing a vector containing four functions
static std::vector<FunctionDefn> inverseFunctions = {
  asinh,
  acosh,
  atanh,
  exp,
  []( double x )
  {
    return exp( log( x ) / 2 );
  },
  []( double x )
  {
    return ( x * 9.0 / 5.0 ) + 32.0;
  }
};


template <typename A, typename B, typename C>
std::function<C( A )> composed( std::function<C( B )> f, std::function<B( A )> g )
{
  return [f, g]( A x ) {
    return f( g( x ) );
  };
}

auto main() -> int
{
  std::vector<FunctionDefn> composedFuncs;
  std::vector<double> nums;

  for ( size_t i = 1; i <= functions.size(); ++i ) {
    nums.push_back( i * 1.50 );
  }

  for ( auto num : nums ) {
    for ( auto func : functions ) {
      std::cout << "num=" << num << "  from functions = " << func( num ) << std::endl;
    }

    std::cout << "---------------" << std::endl;
  }

  for ( auto num : nums ) {
    for ( auto func : inverseFunctions ) {
      std::cout <<  "num=" << num << "  from inverseFunctions = " << func( num ) << std::endl;
    }

    std::cout << "---------------" << std::endl;
  }

  // Transforming the element inside the vector
  transform(
    begin( inverseFunctions ),
    end( inverseFunctions ),
    begin( functions ),
    back_inserter( composedFuncs ),
    composed<double, double, double> );

  for ( auto num : nums ) {
    for ( auto func : composedFuncs ) {
      std::cout << "f(g(" << num << ")) = " << func( num ) << std::endl;
    }

    std::cout << "---------------" << std::endl;
  }

  return 0;
}
