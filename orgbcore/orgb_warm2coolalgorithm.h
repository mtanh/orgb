#ifndef ORGB_WARM2COOLALGORITHM_H
#define ORGB_WARM2COOLALGORITHM_H

#include <opencv2\core\core.hpp>
#include "orgb_algorithm.h"
#include "orgbcore_global.h"

class OrgbWarm2CoolAlgorithm: public OrgbAlgorithm
{
public:
    OrgbWarm2CoolAlgorithm(void* data = nullptr);
    virtual ~OrgbWarm2CoolAlgorithm();

    virtual void operator()();

private:
    OrgbWarm2CoolAlgorithm(const OrgbWarm2CoolAlgorithm&) = delete;
    OrgbWarm2CoolAlgorithm& operator=(const OrgbWarm2CoolAlgorithm&) = delete;
};

extern OrgbWarm2CoolAlgorithm orgbWarm2CoolAlgorithm;

#endif // ORGB_WARM2COOLALGORITHM_H
