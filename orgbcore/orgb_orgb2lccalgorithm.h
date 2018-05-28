#ifndef ORGB_ORGB2LCCALGORITHM_H
#define ORGB_ORGB2LCCALGORITHM_H

#include "orgb_algorithm.h"

class OrgboRGB2LCCAlgorithm: public OrgbAlgorithm
{
public:
    OrgboRGB2LCCAlgorithm(void* data = nullptr);
    virtual ~OrgboRGB2LCCAlgorithm();

    virtual void operator()();

private:
    OrgboRGB2LCCAlgorithm(const OrgboRGB2LCCAlgorithm&) = delete;
    OrgboRGB2LCCAlgorithm& operator=(const OrgboRGB2LCCAlgorithm&) = delete;
};

extern OrgboRGB2LCCAlgorithm orgboRGB2LCCAlgorithm;

#endif // ORGB_ORGB2LCCALGORITHM_H
