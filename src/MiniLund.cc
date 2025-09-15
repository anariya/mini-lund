/*
  An instance of MiniLund is analagous to an instance of Pythia, providing an
  event record and a collection of particle data, and allowing for q-qbar
  hadronisation events to be generated.

  Author: Jade Abidi
*/

using namespace std;

#include "MiniLund.h"
#include "Event.h"
#include <iostream>

// MiniLund class.
  
// Current version number.
const double MiniLund::VERSION = 0.1;

// Constructor.
MiniLund::MiniLund() {
  cout << "Constructing." << endl;
}

int MiniLund::run() {
  Vec4 p(1., 2., 3., 4.);
  cout << p.e() << endl;
  return 1216;
}




