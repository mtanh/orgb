#ifndef ORGB_RGB2LCCALGORITHM_H
#define ORGB_RGB2LCCALGORITHM_H

#include "orgb_algorithm.h"

class OrgbRGB2LCCAlgorithm: public OrgbAlgorithm
{
public:
    OrgbRGB2LCCAlgorithm(void* data = nullptr);
    virtual ~OrgbRGB2LCCAlgorithm();

    virtual void operator()();

private:
    OrgbRGB2LCCAlgorithm(const OrgbRGB2LCCAlgorithm&) = delete;
    OrgbRGB2LCCAlgorithm& operator=(const OrgbRGB2LCCAlgorithm&) = delete;
};

extern OrgbRGB2LCCAlgorithm orgbRGB2LCCAlgorithm;

#endif // ORGB_RGB2LCCALGORITHM_H
