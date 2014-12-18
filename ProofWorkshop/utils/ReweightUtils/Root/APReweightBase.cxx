#define APReweightBase_cxx
#include "ReweightUtils/APReweightBase.h"

unsigned int APReweightBase::_NID = 0;

APReweightBase::APReweightBase() {
  _ID = _NID;
  _empty_weight = 0;
  ++_NID;
}

APReweightBase::~APReweightBase() { }

unsigned int APReweightBase::GetID() const {
  return _ID;
}
