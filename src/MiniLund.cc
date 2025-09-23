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
bool MiniLund::fragment_string_accordion(double cme, Flavour flav) {

}






