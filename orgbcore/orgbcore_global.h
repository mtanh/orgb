#ifndef ORGBCORE_GLOBAL_H
#define ORGBCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ORGBCORE_LIBRARY)
#  define ORGBCORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define ORGBCORESHARED_EXPORT Q_DECL_IMPORT
#endif

#define CONVEYOR_OPERATOR_MAX 20
#define ORGB_RGB2oRGB2COOLINGDOWN

#include <opencv2\core\core.hpp>

typedef enum _ORGB_CONVEYOR_CODE {
    ORGB_CODE_UNKNOW = 0,
    ORGB_CODE_RGB2LCC,
    ORGB_CODE_RGB2oRGB,
    ORGB_CODE_RGB2oRGBCOOLINGDOWN,

    ORGB_CODE_RGB2oRGB2LCC = 100,
    ORGB_CODE_RGB2oRGB2LCC2RGB
} ORGB_CONVEYOR_CODE;

typedef struct st_processing_data {
    cv::Mat* image;
    double alpha;   // for warm to cool adjustment
} st_processing_data;

#endif // ORGBCORE_GLOBAL_H
