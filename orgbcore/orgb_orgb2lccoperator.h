#ifndef ORGB_ORGB2LCCOPERATOR_H
#define ORGB_ORGB2LCCOPERATOR_H

#include "orgb_operator.h"

class OrgboRGB2LCCOperator: public OrgbOperator
{
public:
    OrgboRGB2LCCOperator();
    virtual ~OrgboRGB2LCCOperator();

    virtual void cookData(void* data = nullptr);

private:
    OrgboRGB2LCCOperator(const OrgboRGB2LCCOperator&) = delete;
    OrgboRGB2LCCOperator& operator =(const OrgboRGB2LCCOperator&) = delete;
};

extern OrgboRGB2LCCOperator orgboRGB2LCCOperator;

#endif // ORGB_ORGB2LCCOPERATOR_H
