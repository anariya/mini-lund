/*
  MiniLund header file.

  Author: Jade Abidi
*/

#include "Particle.h"

class MiniLund {
public:
  
  // Constructor.
  MiniLund();

  // Generate a q-qbar string fragmentation event with a given centre-of-mass
  // energy and quark flavour. Returns false if the event generation failed. Uses the accordion algorithm to join string ends.
  bool fragment_string_accordion(double cme, int flav);

  // Version number.
  static const double VERSION;

  // Probability of fragmenting from positive end.
  static const double PROBFROMPOS;

  // Pre-set sigma for transverse momentum distribution.
  static const double PTSIGMA;

  // Mass of the single and only hadron.
  static const double HADRONMASS;

  // Event record.
  vector<Particle> event;

  // Particle data.
  ParticleData pd;

  // Random number generator.
  Rndm rndm;

private:

  // Remaining string momentum.
  Vec4 pRem;
  double w2Rem;

  // String ends.
  StringEnd posEnd;
  StringEnd negEnd;
  
  // Lund fragmentation parameters.
  double a;
  double b;
  double kappa;

  // Joining parameters.
  double stopMass;
  double stopNewFlav;
  double stopSpread;
  
  // Accordion parameters.
  double probRevertBreak;
  double dy_mean;
  double dy_rms;
  
};
