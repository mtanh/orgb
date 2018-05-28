#include "orgb_lcc2orgboperator.h"

OrgbLCC2oRGBAlgorithm orgbLCC2oRGBAlgorithm;

OrgbLCC2oRGBOperator::OrgbLCC2oRGBOperator()
{

}

OrgbLCC2oRGBOperator::~OrgbLCC2oRGBOperator()
{

}

void OrgbLCC2oRGBOperator::cookData(void* data)
{
    setAlgorithm(&orgbLCC2oRGBAlgorithm);
    if(m_pAlgorithm)
    {
        m_pAlgorithm->setData(data);
        m_pAlgorithm->operator ()();
    }
}
