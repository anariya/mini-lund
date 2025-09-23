/*
  Header file for the Particle class, as well as related classes ParticleData,
  Vec4, and StringEnd.

  Author: Jade Abidi
*/

using namespace std;

#include <cmath>

// Vec4 class.
class Vec4{
public:

  // Constructors.
  Vec4() : eSave(0.), pxSave(0.), pySave(0.), pzSave(0.) { }
  Vec4(double eIn, double pxIn, double pyIn, double pzIn) : eSave(eIn),
							    pxSave(pxIn), pySave(pyIn), pzSave(pzIn) { }

  // Member functions for output.
  double e() const { return eSave; }
  double px() const { return pxSave; }
  double py() const { return pySave; }
  double pz() const { return pzSave; }

  // Member functions for input.
  void e(double eIn) { eSave = eIn; }
  void px(double pxIn) { pxSave = pxIn; }
  void py(double pyIn) { pySave = pyIn; }
  void pz(double pzIn) { pzSave = pzIn; }

protected:
  // Components.
  double eSave;
  double pxSave;
  double pySave;
  double pzSave;
};

// Particle class.
class Particle {
public:

  // Constructors.
  Particle() : idSave(0), statusSave(0), pSave(Vec4(0., 0., 0., 0.)), mSave(0.)
  { }

  Particle(int idIn, int statusIn = 0, double pxIn = 0., double pyIn = 0.,
	   double pzIn = 0., double eIn = 0., double mIn = 0.) : idSave(idIn),
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

  // Flavour of the new string end quark, after the hadron is fragmented off.
  int flavNew;

  // Transverse momentum of the new string end quark, after the hadron is fragmented off.
  double pxNew;
  double pyNew;

  // Id of the new hadron.
  int idHadron;
  
}
  


