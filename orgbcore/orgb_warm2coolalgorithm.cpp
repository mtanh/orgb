#include <QDebug>
#include "orgb_warm2coolalgorithm.h"

OrgbWarm2CoolAlgorithm::OrgbWarm2CoolAlgorithm(void *data)
    : OrgbAlgorithm(data)
{

}

OrgbWarm2CoolAlgorithm::~OrgbWarm2CoolAlgorithm()
{

}

void OrgbWarm2CoolAlgorithm::operator()()
{
    qDebug() << "Enter " << __FUNCTION__;

    do
    {
        st_processing_data* dt = (st_processing_data*)m_data;
        if(nullptr == dt)
            break;

        cv::Mat* image = dt->image;
        double alpha = dt->alpha;

        if(nullptr == image)
            break;

        if(!image->data)
            break;

        image->convertTo(*image, CV_32FC3);
        for (int y = 0; y < image->rows; y++)
        {
            for (int x = 0; x < image->cols; x++)
            {
                 image->at<cv::Vec3f>(y, x)[1] *= alpha;
                 //image->at<cv::Vec3f>(y, x)[2] /= alpha;
            }
        }
        image->convertTo(*image, CV_8UC3);

    } while(false);

    qDebug() << "Leave " << __FUNCTION__;
}
