#ifndef ORGB_LCC2ORGBOPERATOR_H
#define ORGB_LCC2ORGBOPERATOR_H

#include "orgb_operator.h"

class OrgbLCC2oRGBOperator: public OrgbOperator
{
public:
    OrgbLCC2oRGBOperator();
    virtual ~OrgbLCC2oRGBOperator();

    virtual void cookData(void* data = nullptr);

private:
    OrgbLCC2oRGBOperator(const OrgbLCC2oRGBOperator&) = delete;
    OrgbLCC2oRGBOperator& operator =(const OrgbLCC2oRGBOperator&) = delete;
};

extern OrgbLCC2oRGBOperator orgbLCC2oRGBOperator;

#endif // ORGB_LCC2ORGBOPERATOR_H
