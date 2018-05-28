#include <opencv2\core\core.hpp>
#include "orgbcore_global.h"
#include "orgb_conveyor.h"
#include "orgb_operator.h"

OrgbConveyor::OrgbConveyor()
    : m_pData(nullptr)
{
    m_container.reserve(CONVEYOR_OPERATOR_MAX);
}

OrgbConveyor::~OrgbConveyor()
{

}

void OrgbConveyor::process(void* optional)
{
    std::for_each(m_container.begin(), m_container.end(),
                  [this](OrgbOperator *oper) { return oper->cookData(getData()); });
    return;
}

void OrgbConveyor::registerOperator(OrgbOperator* oper)
{
    if(oper != nullptr)
        m_container.push_back(oper);
}
