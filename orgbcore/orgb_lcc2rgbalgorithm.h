#ifndef ORGB_LCC2RGBALGORITHM_H
#define ORGB_LCC2RGBALGORITHM_H

#include "orgb_algorithm.h"

class OrgbLCC2RGBAlgorithm: public OrgbAlgorithm
{
public:
    OrgbLCC2RGBAlgorithm(void* data = nullptr);
    virtual ~OrgbLCC2RGBAlgorithm();

    virtual void operator()();

private:
    OrgbLCC2RGBAlgorithm(const OrgbLCC2RGBAlgorithm&) = delete;
    OrgbLCC2RGBAlgorithm& operator=(const OrgbLCC2RGBAlgorithm&) = delete;
};

extern OrgbLCC2RGBAlgorithm orgbLCC2RGBAlgorithm;

#endif // ORGB_LCC2RGBALGORITHM_H
