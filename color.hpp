#pragma once

#include <cstdint>
#include <tuple>

using std::uint8_t;

struct color_t
{
	color_t() : red(0), green(0), blue(0) {}
	color_t(uint8_t r, uint8_t g, uint8_t b) : red(r), green(g), blue(b) {}
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

inline uint8_t & red_part(color_t &c) { return c.red; }
inline uint8_t & green_part(color_t &c) { return c.green; }
inline uint8_t & blue_part(color_t &c) { return c.blue; }

static const color_t black(0,0,0);
static const color_t white(255,255,255);

template<typename T>
uint8_t colorchop(T x)
{
  if(x<0) return 0;
  else if(x>255) return 255;
  else return (uint8_t) x;
}

