#include <opencv2\core\core.hpp>
#include <opencv2\core\types_c.h>
#include <opencv2\imgproc\imgproc.hpp>
#include <QDebug>
#include "orgb_orgb2lccalgorithm.h"

static double oRGBNewAngleInRadianInverse(const double& angleRadian);

OrgboRGB2LCCAlgorithm::OrgboRGB2LCCAlgorithm(void* data)
    : OrgbAlgorithm(data)
{

}

OrgboRGB2LCCAlgorithm::~OrgboRGB2LCCAlgorithm()
{

}

void OrgboRGB2LCCAlgorithm::operator()()
{
    qDebug() << "Enter " << __FUNCTION__;

    st_processing_data* dt = (st_processing_data*)m_data;
    cv::Mat* image = dt->image;

    do
    {
        if(nullptr == image)
            break;

        if(!image->data)
            break;

        image->convertTo(*image, CV_32FC3);
        for (int y = 0; y < image->rows; y++)
        {
            for (int x = 0; x < image->cols; x++)
            {
                double oldAngleRadian = atan2(image->at<cv::Vec3f>(y, x)[2], image->at<cv::Vec3f>(y, x)[1]);
                double newAngleRadian = oRGBNewAngleInRadianInverse(oldAngleRadian);
                double angleRadian = newAngleRadian - oldAngleRadian;

                //image->at<cv::Vec3f>(y, x)[0] = image->at<cv::Vec3f>(y, x)[0];
                image->at<cv::Vec3f>(y, x)[1] =
                        cv::saturate_cast<float>(image->at<cv::Vec3f>(y, x)[1] * cos(angleRadian) - image->at<cv::Vec3f>(y, x)[2] * sin(angleRadian));
                image->at<cv::Vec3f>(y, x)[2] =
                        cv::saturate_cast<float>(image->at<cv::Vec3f>(y, x)[1] * sin(angleRadian) + image->at<cv::Vec3f>(y, x)[2] * cos(angleRadian));
            }
        }
        image->convertTo(*image, CV_8UC3);

    } while(false);

    qDebug() << "Leave " << __FUNCTION__;
}

double oRGBNewAngleInRadianInverse(const double& angleRadian)
{
    if (angleRadian < (CV_PI / 2))
        return angleRadian * (2 / 3);
    else /*if (angleRadian >= (CV_PI / 2) && angleRadian <= CV_PI)*/
        return (CV_PI / 3) + (4 / 3) * (angleRadian - CV_PI / 2);
}
