/************************************************************************
 * \file MiniBallTripleAlphaSource.hh
 *
 * \class MiniBallTripleAlphaSource
 * \brief  simulation of a triple alpha source
 *
 * \author vinzenz.bildstein@ph.tum.de
 *
 ************************************************************************/

#ifndef MiniBallTripleAlphaSource_H
#define MiniBallTripleAlphaSource_H

#include "MiniBallSource.hh"

class MiniBallTripleAlphaSource : public MiniBallSource
{

public:
  MiniBallTripleAlphaSource();
  ~MiniBallTripleAlphaSource();

public:
  MiniBallSourceLevel* ground;
  MiniBallSourceLevel* l1332;
  MiniBallSourceLevel* l2505;
};

#endif
