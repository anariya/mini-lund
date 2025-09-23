/*
  An instance of MiniLund is analagous to an instance of Pythia, providing an
  event record and a collection of particle data, and allowing for q-qbar
  hadronisation events to be generated.

  Author: Jade Abidi
*/

using namespace std;

#include "MiniLund.h"
#include <iostream>

// MiniLund class.
  
// Current version number.
const double MiniLund::VERSION = 0.1;

// Constructor.
MiniLund::MiniLund() {
  event = Event();
}

// Fragment string using the accordion algorithm.
bool MiniLund::fragment_string_accordion(double cme, int flav) {

  // Set string momentum.
  pRem = Vec4(cme, 0, 0, 0);

  // Set up string ends.
  posEnd = StringEnd(true, flav, 0.0, 0.0);
  negEnd = StringEnd(false, -flav, 0.0, 0.0);

  // Fragmentation loop.
  while (true) {
    // Select end to fragment from.
    
  }
  
}






