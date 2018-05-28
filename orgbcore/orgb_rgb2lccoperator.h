#ifndef ORGB_RGB2LCCOPERATOR_H
#define ORGB_RGB2LCCOPERATOR_H

#include "orgb_operator.h"

class OrgbRGB2LCCOperator: public OrgbOperator
{
public:
    OrgbRGB2LCCOperator();
    virtual ~OrgbRGB2LCCOperator();

    virtual void cookData(void* data = nullptr);

private:
    OrgbRGB2LCCOperator(const OrgbRGB2LCCOperator&) = delete;
    OrgbRGB2LCCOperator& operator =(const OrgbRGB2LCCOperator&) = delete;
};

extern OrgbRGB2LCCOperator orgbRGB2LCCOperator;

#endif // ORGB_RGB2LCCOPERATOR_H
