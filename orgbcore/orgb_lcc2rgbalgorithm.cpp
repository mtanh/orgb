#include <opencv2\core\core.hpp>
#include <opencv2\core\types_c.h>
#include <opencv2\imgproc\imgproc.hpp>
#include <QDebug>
#include "orgb_lcc2rgbalgorithm.h"

OrgbLCC2RGBAlgorithm::OrgbLCC2RGBAlgorithm(void* data)
    : OrgbAlgorithm(data)
{

}

OrgbLCC2RGBAlgorithm::~OrgbLCC2RGBAlgorithm()
{

}

void OrgbLCC2RGBAlgorithm::operator()()
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

        cv::Mat rgb = cv::Mat::zeros(image->size(), image->type());
        for (int y = 0; y < image->rows; y++)
        {
            for (int x = 0; x < image->cols; x++)
            {
                rgb.at<cv::Vec3b>(y, x)[2] =
                        cv::saturate_cast<uchar>(image->at<cv::Vec3b>(y, x)[0] * 1.f
                        + image->at<cv::Vec3b>(y, x)[1] * 0.1140f
                        + image->at<cv::Vec3b>(y, x)[2] * 0.7436f);

                rgb.at<cv::Vec3b>(y, x)[1] =
                        cv::saturate_cast<uchar>(image->at<cv::Vec3b>(y, x)[0] * 1.f
                        + image->at<cv::Vec3b>(y, x)[1] * 0.1140f
                        + image->at<cv::Vec3b>(y, x)[2] * (-0.4111f));

                rgb.at<cv::Vec3b>(y, x)[0] =
                        cv::saturate_cast<uchar>(image->at<cv::Vec3b>(y, x)[0] * 1.f
                        + image->at<cv::Vec3b>(y, x)[1] * (-0.8860f)
                        + image->at<cv::Vec3b>(y, x)[2] * 0.1663f);
            }
        }
        rgb.copyTo(*image);

    } while(false);

    qDebug() << "Leave " << __FUNCTION__;
}
