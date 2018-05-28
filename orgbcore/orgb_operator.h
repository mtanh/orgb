#ifndef ORGB_OPERATOR_H
#define ORGB_OPERATOR_H

#include "orgbcore_global.h"
#include "orgb_agorithm_list.h"

class OrgbConveyor;
class OrgbAlgorithm;

class OrgbOperator
{
public:
    OrgbOperator();
    virtual ~OrgbOperator();

    virtual void cookData(void* data = nullptr) = 0;
    inline void setAlgorithm(OrgbAlgorithm* algorithm) { m_pAlgorithm = algorithm; }

protected:
    OrgbAlgorithm* m_pAlgorithm;

private:
    OrgbOperator(const OrgbOperator&) = delete;
    OrgbOperator& operator =(const OrgbOperator&) = delete;
};

#endif // ORGB_OPERATOR_H
