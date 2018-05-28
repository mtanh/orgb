#include "orgb_w2coperator.h"

OrgbWarm2CoolAlgorithm orgbWarm2CoolAlgorithm;

OrgbW2COperator::OrgbW2COperator()
{

}

OrgbW2COperator::~OrgbW2COperator()
{

}

void OrgbW2COperator::cookData(void* data)
{
    setAlgorithm(&orgbWarm2CoolAlgorithm);
    if(m_pAlgorithm)
    {
        m_pAlgorithm->setData(data);
        m_pAlgorithm->operator ()();
    }
}
