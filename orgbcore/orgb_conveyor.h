#ifndef ORGB_CONVEYOR_H
#define ORGB_CONVEYOR_H

#include <vector>
#include "orgbcore_global.h"

class cv::Mat;
class OrgbOperator;

class OrgbConveyor
{
public:
    OrgbConveyor();
    virtual ~OrgbConveyor();

    void process(void* optional = nullptr);
    void registerOperator(OrgbOperator* oper);
    inline void setData(void* data) { m_pData = data; } // shadow copy
    inline void* getData() const { return m_pData; }

private:
    void* m_pData;
    typedef std::vector<OrgbOperator*> ORGB_CONVEYOR_CONTAINER;
    typedef std::vector<OrgbOperator*>::iterator ORGB_CONVEYOR_CONTAINER_ITER;
    ORGB_CONVEYOR_CONTAINER m_container;

    OrgbConveyor(const OrgbConveyor&) = delete;
    OrgbConveyor& operator =(const OrgbConveyor&) = delete;
};

// forward conveyor
extern OrgbConveyor orgbRGB2LCCConveyor;
extern OrgbConveyor orgbRGB2oRGBConveyor;
extern OrgbConveyor orgbRGB2WTCConveyor;

// backward conveyor
extern OrgbConveyor orgbRGB2oRGB2LCCConveyor;
extern OrgbConveyor orgbRGB2oRGB2LCC2RGBConveyor;

#endif // ORGB_CONVEYOR_H
