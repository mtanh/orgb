#ifndef ORGBCORE_H
#define ORGBCORE_H

#include "orgbcore_global.h"

class cv::Mat;
class OrgbConveyor;

class ORGBCORESHARED_EXPORT OrgbCore
{
public:
    ~OrgbCore();

    static OrgbCore &getGlobalInstance();
    static bool initialize();
    static void terminate();

    void pushData(void* data, ORGB_CONVEYOR_CODE code);
    void* popData();

private:
    inline void setConveyor(OrgbConveyor* conveyor) { m_pConveyor = conveyor; }

    static OrgbCore* m_pGlobalInstance;
    OrgbConveyor* m_pConveyor;

    OrgbCore();
    OrgbCore(const OrgbCore&) = delete;
    OrgbCore& operator =(const OrgbCore&) = delete;
};

#endif // ORGBCORE_H
