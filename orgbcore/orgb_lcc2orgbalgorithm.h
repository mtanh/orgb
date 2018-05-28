#ifndef ORGB_LCC2ORGBALGORITHM_H
#define ORGB_LCC2ORGBALGORITHM_H

#include "orgb_algorithm.h"

class OrgbLCC2oRGBAlgorithm: public OrgbAlgorithm
{
public:
    OrgbLCC2oRGBAlgorithm(void* data = nullptr);
    virtual ~OrgbLCC2oRGBAlgorithm();

    virtual void operator()();

private:
    OrgbLCC2oRGBAlgorithm(const OrgbLCC2oRGBAlgorithm&) = delete;
    OrgbLCC2oRGBAlgorithm& operator=(const OrgbLCC2oRGBAlgorithm&) = delete;
};

extern OrgbLCC2oRGBAlgorithm orgbLCC2oRGBAlgorithm;

#endif // ORGB_LCC2ORGBALGORITHM_H
