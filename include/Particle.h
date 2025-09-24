/*
  Header file for the Particle class, as well as related classes ParticleData,
  Vec4, and StringEnd.

  Author: Jade Abidi
*/

#include "Basics.h"

// Particle class.
class Particle {
public:

  // Constructors.
  Particle() : idSave(0), statusSave(0), pSave(Vec4(0., 0., 0., 0.)), mSave(0.)
  { }

  Particle(int idIn, int statusIn = 0, double eIn = 0., double pxIn = 0.,
    double pyIn = 0., double pzIn = 0., double mIn = 0.) : idSave(idIn),
      statusSave(statusIn), pSave(Vec4(eIn, pxIn, pyIn, pzIn)), mSave(mIn) { }

  // Member functions for output.
  int id() const { return idSave; }
  int status() const { return statusSave; }
  Vec4 p() const { return pSave; }
  double px() const { return pSave.px(); }
  double py() const { return pSave.py(); }
  double pz() const { return pSave.pz(); }
  double e() const { return pSave.e(); }
  double m() const { return mSave; }

  // Calculated member functions for output.
  double y() const {
    return 0.5 * log((pSave.e() + pSave.pz()) / (pSave.e() - pSave.pz()));
  }

  // Member functions for input.
  void id(int idIn) { idSave = idIn; }
  void status(int statusIn) { statusSave = statusIn; }
  void p(Vec4 pIn) { pSave = pIn; }
  void px(double pxIn) { pSave.px(pxIn); }
  void py(double pyIn) { pSave.py(pyIn); }
  void pz(double pzIn) { pSave.pz(pzIn); }
  void e(double eIn) { pSave.e(eIn); }
  void m(double mIn) { mSave = mIn; }

protected:
  // Particle properties.
  int idSave, statusSave;
  Vec4 pSave;
  double mSave;
  
};

// StringEnd class.
class StringEnd {

public:
  // Constructor.
  StringEnd(bool posIn, int flavEndIn, double pxEndIn, double pyEndIn) {
    flavEnd = flavEndIn;
    pos = posIn;
    pxEnd = pxEndIn;
    pyEnd = pyEndIn;
  }
  
  // Whether the string end is positive in pz or negative.
  bool pos;

  // Flavour of the string end.
  int flavEnd;
  
  // Transverse momentum of the string end quark.
  double pxEnd;
  double pyEnd;

  // Flavour and transverse momentum of previous string end quark.
  // Allows for string breaks to be undone.
  int flavEndPrev;
  double pxEndPrev;
  double pyEndPrev;

  // Flavour of the new string end quark, after the hadron is fragmented off.
  int flavNew;

  // Transverse momentum of the new string end quark, after the hadron is fragmented off.
  double pxNew;
  double pyNew;

  // Id of the new hadron.
  int idHadron;
  
};



