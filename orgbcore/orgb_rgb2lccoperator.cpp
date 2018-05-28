#include "orgb_rgb2lccoperator.h"

OrgbRGB2LCCAlgorithm orgbRGB2LCCAlgorithm;

OrgbRGB2LCCOperator::OrgbRGB2LCCOperator()
{

}

OrgbRGB2LCCOperator::~OrgbRGB2LCCOperator()
{

}

void OrgbRGB2LCCOperator::cookData(void* data)
{
    setAlgorithm(&orgbRGB2LCCAlgorithm);
    if(m_pAlgorithm)
    {
        m_pAlgorithm->setData(data);
        m_pAlgorithm->operator ()();
    }
}
