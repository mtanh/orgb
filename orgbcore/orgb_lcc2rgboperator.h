#ifndef ORGB_LCC2RGBOPERATOR_H
#define ORGB_LCC2RGBOPERATOR_H

#include "orgb_operator.h"

class OrgbLCC2RGBOperator: public OrgbOperator
{
public:
    OrgbLCC2RGBOperator();
    virtual ~OrgbLCC2RGBOperator();

    virtual void cookData(void* data = nullptr);

private:
    OrgbLCC2RGBOperator(const OrgbLCC2RGBOperator&) = delete;
    OrgbLCC2RGBOperator& operator =(const OrgbLCC2RGBOperator&) = delete;
};

extern OrgbLCC2RGBOperator orgbLCC2RGBOperator;

#endif // ORGB_LCC2RGBOPERATOR_H
