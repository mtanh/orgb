#ifndef ORGB_W2COPERATOR_H
#define ORGB_W2COPERATOR_H

#include "orgb_operator.h"

class OrgbW2COperator: public OrgbOperator
{
public:
    OrgbW2COperator();
    virtual ~OrgbW2COperator();

    virtual void cookData(void* data = nullptr);

private:
    OrgbW2COperator(const OrgbW2COperator&) = delete;
    OrgbW2COperator& operator =(const OrgbW2COperator&) = delete;
};

extern OrgbW2COperator orgbW2COperator;

#endif // ORGB_W2COPERATOR_H
