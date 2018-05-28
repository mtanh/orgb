#include "orgb_lcc2rgboperator.h"

OrgbLCC2RGBAlgorithm orgbLCC2RGBAlgorithm;

OrgbLCC2RGBOperator::OrgbLCC2RGBOperator()
{

}

OrgbLCC2RGBOperator::~OrgbLCC2RGBOperator()
{

}

void OrgbLCC2RGBOperator::cookData(void* data)
{
    setAlgorithm(&orgbLCC2RGBAlgorithm);
    if(m_pAlgorithm)
    {
        m_pAlgorithm->setData(data);
        m_pAlgorithm->operator ()();
    }
}

