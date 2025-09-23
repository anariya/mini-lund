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

// Probability of fragmenting from positive end.
const double MiniLund::PROBFROMPOS = 0.5;

// Sigma for pT distribution. TODO: Make this a setting.
const double MiniLund::PTSIGMA = 0.335;

// Constructor.
MiniLund::MiniLund() {
  event = Event();
  rndm = Rndm(Rndm::DEFAULTSEED);
}

// Fragment string using the accordion algorithm.
bool MiniLund::fragment_string_accordion(double cme, int flav) {

  // Set string momentum.
  pRem = Vec4(cme, 0, 0, 0);

  // Set up string ends.
  posEnd = StringEnd(true, flav, 0.0, 0.0);
  negEnd = StringEnd(false, -flav, 0.0, 0.0);

  bool fromPos;
  double m2Had;
  double mT2Had;

  // Fragmentation loop.
  while (true) {
    // Select end to fragment from.
    fromPos = (rndm.flat() < PROBFROMPOS);
    StringEnd& nowEnd = fromPos ? posEnd : negEnd;

    // For now there is only one quark flavour.
    nowEnd.flavNew = fromPos ? 1 : -1;

    // Select px and py for new quark.
    pair<double, double> gauss2 = rndm.gauss2();
    nowEnd.pxNew = gauss2.first;
    nowEnd.pyNew = gauss2.second;

    // For now there is only one hadron.
    nowEnd.idHad = 1;

    // Calculate transverse mass.
    pxHad = nowEnd.pxEnd - nowEnd.pxNew;
    pyHad = nowEnd.pyEnd - nowEnd.pyNew;
    m2Had = pd.mass(idHad);
    mT2Had = m2Had + pxHad ^ 2 + pyHad ^ 2;

    // Check if there is energy left in the string.
    w2Rem = pRem.m2calc();
    if (w2Rem < 0) {
      // Revert the previous string break with probability probRemoveLast
      if (rndm.flat() < probRemoveLast) {
        // Add back hadron energy.
        int iLast = fromPos ? iLastPos : iLastNeg;
	pRem += event[iLast].p();
	event.remove(iLast); // ??

	// Rewind string end.
	nowEnd.flavEnd = nowEnd.flavEndPrev;
	nowEnd.pxEnd = nowEnd.pxEndPrev;
	nowEnd.pyEnd = nowEnd.pyEndPrev;
      }

      // No need to select new hadron species for now because there is only one.
      idHad = 1;

      // For now, rapidity spacing is a constant.
      deltay = 1.0;

      // Determine what must be the two adjacent hadron longitudinal momenta
      // to satisfy this rapidity spacing.
      hadPos = event[iLastPos];
      hadNeg = event[iLastNeg];
      mT2Pos = hadPos.mT2calc();
      mT2Neg = hadNeg.mT2calc();

      pzPos = sqrt(-0.5*mT2Pos + 0.25*exp(-2*deltay)*mT2Pos
		   + 0.25*exp(2*deltay)*mT2Pos);
      ePos = (pzPos + exp(2*deltay)*pzPos) / (exp(2*deltay) - 1);
      pzNeg = -1.0 * sqrt(-0.5*mT2Neg + 0.25*exp(-2*deltay)*mT2Neg
			  + 0.25*exp(2*deltay)*mT2Neg);
      eNeg = (pzNeg + exp(2*deltay)*pzNeg) / (exp(2*deltay) - 1);

      // Set these longitudinal momenta alongside the remaining transverse
      // momenta of both string ends, and determine the four-momenta of
      // both adjacent hadrons.
      pPos = Vec4(ePos, hadPos.px(), hadPos.py(), pzPos);
      pNeg = Vec4(eNeg, hadNeg.px(), hadNeg.py(), pzNeg);

      // Determine boost vectors to bring last hadrons from each string end to
      // align with these four-momenta.
      pBoostPos = -event[i].p() + pPos;
      pBoostNeg = -event[i].p() + pNeg;

      // Boost the positive and negative sets of hadrons into the rest frame
      // of the joining hadron.
      for (int i = 0; i < event.size(); ++i) {
        if (event[i].status() == 0)
	  // Negative end.
	  event[i].p().boost(pBoostNeg);
	else if (event[i].status() == 1)
	  // Positive end.
	  event[i].p().boost(pBoostPos);
      }

      // Add new hadron to event record.
      pxHad = posEnd.pxEnd + negEnd.pxEnd;
      pyHad = posEnd.pyEnd + negEnd.pyEnd;
      pzHad = 0.0;
      mHad = pd.mass(idHad);
      eHad = sqrt(mHad ^ 2 + pxHad ^ 2 + pyHad ^ 2 + pzHad ^ 2);
      pHad = Vec4(eHad, pxHad, pyHad, pzHad);
      event.append(pHad, mHad);

      // Calculate centre-of-mass momentum to boost back to CM frame.      
      Vec4 pCm = Vec4(0.0, 0.0, 0.0, 0.0);
      for (int i = 0; i < event.size(); ++i)
	pCm += event[i].p();

      // Boost back to CM frame.
      for (int i = 0; i < event.size(); ++i)
	event[i].p().boost(-pCm); // Really this should only affect the 3-vector
	
      // Calculate the required change in energy to restore energy-momentum
      // conservation.
      Vec4 pTot = Vec4(0.0, 0.0, 0.0, 0.0);
      for (int i = 0; i < event.size(); ++i) {
	p

      // Rescale all hadron longitudinal momenta to achieve required change in energy.

      // Finished.
    }

    // Select a z fraction. For now it will be constant.
    fragZ = 0.5;

    // Calculate kinematics and add new hadron to event record.
    pPosHad = fragZ * pRem.pPos();
    pNegHad = mT2Had / pPosHad;
    eHad = 0.5 * (pPosHad + pNegHad);
    pzHad = 0.5 * (pPosHad - pNegHad);
    pHad = Vec4(eHad, pxHad, pyHad, pzHad);
    newHad = Particle(pHad, sqrt(m2Had));
    
    if (fromPos)
      iLastPos = event.append(newHad);
    else
      iLastNeg = event.append(newHad);

    // Subtract hadron energy from remaining string energy.
    pRem -= pHad;

    // Update string end.
    nowEnd.flavEndPrev = nowEnd.flavEnd;
    nowEnd.pxEndPrev = nowEnd.pxEnd;
    nowEnd.pyEndPrev = nowEnd.pyEnd;
    nowEnd.flavEnd = nowEnd.flavNew;
    nowEnd.pxEnd = nowEnd.pxNew;
    nowEnd.pyEnd = nowEnd.pyNew;
  }
  
}






