#include <opencv2\core\core.hpp>
#include "orgbcore.h"
#include "orgb_conveyor.h"
#include "orgb_operator_list.h"

// Global conveyor
OrgbConveyor orgbRGB2LCCConveyor;
OrgbConveyor orgbRGB2oRGBConveyor;
OrgbConveyor orgbRGB2WTCConveyor;
OrgbConveyor orgbRGB2oRGB2LCCConveyor;
OrgbConveyor orgbRGB2oRGB2LCC2RGBConveyor;

// Global operator
OrgbRGB2LCCOperator orgbRGB2LCCOperator;
OrgbLCC2oRGBOperator orgbLCC2oRGBOperator;
OrgbW2COperator orgbW2COperator;
OrgboRGB2LCCOperator orgboRGB2LCCOperator;
OrgbLCC2RGBOperator orgbLCC2RGBOperator;

OrgbCore* OrgbCore::m_pGlobalInstance = nullptr;

OrgbCore::OrgbCore()
    : m_pConveyor(nullptr)
{

}

OrgbCore::~OrgbCore()
{

}

OrgbCore &OrgbCore::getGlobalInstance()
{
    if (nullptr == m_pGlobalInstance)
        initialize();

    return *m_pGlobalInstance;
}

bool OrgbCore::initialize()
{
    if (m_pGlobalInstance)
        return false;

    m_pGlobalInstance = new OrgbCore();

    /* Operator registernation */
    orgbRGB2LCCConveyor.registerOperator(&orgbRGB2LCCOperator);

    orgbRGB2oRGBConveyor.registerOperator(&orgbRGB2LCCOperator);
    orgbRGB2oRGBConveyor.registerOperator(&orgbLCC2oRGBOperator);

    orgbRGB2WTCConveyor.registerOperator(&orgbRGB2LCCOperator);
    orgbRGB2WTCConveyor.registerOperator(&orgbLCC2oRGBOperator);
    orgbRGB2WTCConveyor.registerOperator(&orgbW2COperator);

    orgbRGB2oRGB2LCCConveyor.registerOperator(&orgbRGB2LCCOperator);
    orgbRGB2oRGB2LCCConveyor.registerOperator(&orgbLCC2oRGBOperator);
    orgbRGB2oRGB2LCCConveyor.registerOperator(&orgbW2COperator);
    orgbRGB2oRGB2LCCConveyor.registerOperator(&orgboRGB2LCCOperator);

    orgbRGB2oRGB2LCC2RGBConveyor.registerOperator(&orgbRGB2LCCOperator);
    orgbRGB2oRGB2LCC2RGBConveyor.registerOperator(&orgbLCC2oRGBOperator);
    orgbRGB2oRGB2LCC2RGBConveyor.registerOperator(&orgbW2COperator);
    orgbRGB2oRGB2LCC2RGBConveyor.registerOperator(&orgboRGB2LCCOperator);
    orgbRGB2oRGB2LCC2RGBConveyor.registerOperator(&orgbLCC2RGBOperator);

    return true;
}

void OrgbCore::terminate()
{
    if(m_pGlobalInstance)
    {
        delete m_pGlobalInstance;
        m_pGlobalInstance = nullptr;
    }
}

void OrgbCore::pushData(void* data, ORGB_CONVEYOR_CODE code)
{
    do
    {
        st_processing_data* dt = (st_processing_data*)data;
        if(nullptr == dt)
            break;

        switch (code)
        {
        case ORGB_CODE_RGB2LCC:
            m_pConveyor = &orgbRGB2LCCConveyor;
            break;
        case ORGB_CODE_RGB2oRGB:
            m_pConveyor = &orgbRGB2oRGBConveyor;
            break;
        case ORGB_CODE_RGB2oRGBCOOLINGDOWN:
            m_pConveyor = &orgbRGB2WTCConveyor;
            break;
        case ORGB_CODE_RGB2oRGB2LCC:
            m_pConveyor = &orgbRGB2oRGB2LCCConveyor;
            break;
        case ORGB_CODE_RGB2oRGB2LCC2RGB:
            m_pConveyor = &orgbRGB2oRGB2LCC2RGBConveyor;
            break;
        default:
            break;
        }

        if(m_pConveyor)
            m_pConveyor->setData(dt);

    } while(false);
}

void *OrgbCore::popData()
{
    if(m_pConveyor)
    {
        m_pConveyor->process();
        return m_pConveyor->getData();
    }
    return nullptr;
}
