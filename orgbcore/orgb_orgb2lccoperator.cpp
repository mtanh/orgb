#include "orgb_orgb2lccoperator.h"

OrgboRGB2LCCAlgorithm orgboRGB2LCCAlgorithm;

OrgboRGB2LCCOperator::OrgboRGB2LCCOperator()
{

}

OrgboRGB2LCCOperator::~OrgboRGB2LCCOperator()
{

}

void OrgboRGB2LCCOperator::cookData(void* data)
{
    setAlgorithm(&orgboRGB2LCCAlgorithm);
    if(m_pAlgorithm)
    {
        m_pAlgorithm->setData(data);
        m_pAlgorithm->operator ()();
    }
}
