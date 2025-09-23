// Header file for Random class, which handles random number generation.
// Adapted from the Rndm class of PYTHIA 8.3.

// This class describes the configuration of a Rndm object.

struct RndmState {
  int    i97{}, j97{}, seed{0};
  long   sequence{0};
  double u[97]{}, c{}, cd{}, cm{};

  // Test whether two random states would generate the same random sequence.
  bool operator==(const RndmState& other) const;
};

//==============================================================================
// Rndm class, adapted from PYTHIA 8.3. Uses the Marsaglia-Zaman-Tsang algorithm
// to provide random number generation.

class Rndm {

public:

  // Constructors.
  Rndm() : initRndm(false), stateSave() { }
  Rndm(int seedIn) : initRndm(false), stateSave() {
    init(seedIn);
  }

  // Initialise.
  void init(int seedIn = 0);

  // Generate next random number uniformly between 0 and 1.
  double flat();

  // Generate random numbers according to exp(-x^2 / 2).
  double gauss() {
    return sqrt(-2. * log(flat())) * cos(M_PI * flat());
  }

  // Get or set the state of the random number generator.
  RndmState getState() const { return stateSave; }
  void setState(const RndmState& state) { stateSave = state; }

  // The default seed.
  static constexpr int DEFAULTSEED = 19780503;

private:

  // State of the random number generator.
  bool initRndm;
  RndmState stateSave;
  
};


