#ifndef ORGB_ALGORITHM_H
#define ORGB_ALGORITHM_H

#include "orgbcore_global.h"

class OrgbAlgorithm
{
public:
    void* m_data;

    OrgbAlgorithm(void* data = nullptr);
    virtual ~OrgbAlgorithm();

    inline void setData(void* data) { m_data = data; }
    virtual void operator()() = 0;

private:
    OrgbAlgorithm(const OrgbAlgorithm&) = delete;
    OrgbAlgorithm& operator=(const OrgbAlgorithm&) = delete;
};

#endif // ORGB_ALGORITHM_H
