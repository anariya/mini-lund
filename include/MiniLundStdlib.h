// Defines functionality taken from stdlib and basic utilities.

// Mathematics.
#include <cmath>

// Strings and containers.
#include <string>
#include <vector>
#include <functional>

// Input and output.
#include <iostream>
#include <fstream>
#include <iomanip>

// Define pi.
#ifndef M_PI
#define M_PI 3.1415926535
#endif

// Utilities and mathematical functions.
using std::max;
using std::min;
using std::abs;
using std::isnan;
using std::isinf;
using std::isfinite;
using std::function;
using std::numeric_limits;

// Strings and containers.
using std::string;
using std::to_string;
using std::vector;
using std::pair;
using std::make_pair;

// Input/output.
using std::cin;
using std::cout;
using std::cerr;
using std::fstream;
using std::endl;
using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;
using std::setprecision;
using std::scientific;
using std::ios;
using std::setw;
using std::fixed;
using std::stringstream;
using std::istringstream;
using std::left;
using std::right;

// Powers of small integers - for balance speed/code clarity.
constexpr double pow2(const double& x) {return x*x;}
constexpr double pow3(const double& x) {return x*x*x;}
constexpr double pow4(const double& x) {return x*x*x*x;}
constexpr double pow5(const double& x) {return x*x*x*x*x;}
constexpr double pow6(const double& x) {return x*x*x*x*x*x;}
constexpr double pow7(const double& x) {return x*x*x*x*x*x*x;}
constexpr double pow8(const double& x) {return x*x*x*x*x*x*x*x;}

// Avoid problem with negative square root argument (from roundoff).
inline double sqrtpos(const double& x) {return sqrt( max( 0., x));}

// Create a file, with directory nesting.
ofstream makeFile(string name, ios::openmode modeFile = ios::out,
  mode_t modeDir = 0777);


