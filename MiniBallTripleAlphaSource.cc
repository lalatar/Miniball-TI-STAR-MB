/************************************************************************
 * \file MiniBallTripleAlphaSource.hh
 *
 * \class MiniBallTripleAlphaSource
 * \brief  simulation of a triple alpha source
 *
 * \author vinzenz.bildstein@ph.tum.de
 *
 ************************************************************************/

#include "MiniBallTripleAlphaSource.hh"
#include "Randomize.hh"

MiniBallTripleAlphaSource::MiniBallTripleAlphaSource()
  : MiniBallSource()
{
  fType = kAlphaSource;

  // generate level structure
  ground = new MiniBallSourceLevel(0.*keV, 0, PLUS);
  level_structure.push_back(ground);

  l1332 = new MiniBallSourceLevel(1332.516*keV, 2, PLUS);
  level_structure.push_back(l1332);

  l2505 = new MiniBallSourceLevel(2505.765*keV, 4, PLUS);
  level_structure.push_back(l2505);

  feeding = new MiniBallSourceLevel();
  feeding->decay.push_back(2);
  feeding->prob.push_back(0.99925);
  feeding->decay.push_back(1);
  feeding->prob.push_back(0.00057);

  l2505->AddDecay(1,0.9990,E2);

  l1332->AddDecay(0,0.999820,E2);

  SimulateAngularDistribution();
}

MiniBallTripleAlphaSource::~MiniBallTripleAlphaSource()
{
  delete ground;
  delete l1332;
  delete l2505;
}



