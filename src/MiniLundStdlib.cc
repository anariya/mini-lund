// Function definitions for MiniLund utilities not found in the header.
// Adapted from PYTHIA 8.3.

#include "MiniLundStdlib.h"

//==========================================================================

// Convert a double to string using reasonable formatting.

ofstream makeFile(string name, ios::openmode modeFile, mode_t modeDir) {

  // Determine the file name and path.
  vector<string> path = splitString(name, "/");
  path.pop_back();

  // Create the directory, if needed, and file.
  if (path.size() > 0) makeDir(path, modeDir);
  return ofstream(name.c_str(), modeFile);
  
}

//==========================================================================
