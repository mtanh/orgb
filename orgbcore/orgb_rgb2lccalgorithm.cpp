#include <opencv2\core\core.hpp>
#include <opencv2\core\types_c.h>
#include <opencv2\imgproc\imgproc.hpp>
#include <QDebug>
#include "orgb_rgb2lccalgorithm.h"

OrgbRGB2LCCAlgorithm::OrgbRGB2LCCAlgorithm(void *data)
    : OrgbAlgorithm(data)
{

}

OrgbRGB2LCCAlgorithm::~OrgbRGB2LCCAlgorithm()
{

}

void OrgbRGB2LCCAlgorithm::operator()()
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

        cv::Mat lcc = cv::Mat::zeros(image->size(), image->type());
        for (int y = 0; y < image->rows; y++)
        {
            for (int x = 0; x < image->cols; x++)
            {
                lcc.at<cv::Vec3b>(y, x)[0] =
                        cv::saturate_cast<uchar>(image->at<cv::Vec3b>(y, x)[2] * 0.299f
                        + image->at<cv::Vec3b>(y, x)[1] * 0.5870f
                        + image->at<cv::Vec3b>(y, x)[0] * 0.1140f);

                lcc.at<cv::Vec3b>(y, x)[1] =
                        cv::saturate_cast<uchar>(image->at<cv::Vec3b>(y, x)[2] * 0.5f
                        + image->at<cv::Vec3b>(y, x)[1] * 0.5f
                        + image->at<cv::Vec3b>(y, x)[0] * (-1.0f));

                lcc.at<cv::Vec3b>(y, x)[2] =
                        cv::saturate_cast<uchar>(image->at<cv::Vec3b>(y, x)[2] * 0.866f
                        + image->at<cv::Vec3b>(y, x)[1] * (-0.866f)
                        + image->at<cv::Vec3b>(y, x)[0] * 0.f);
            }
        }
        lcc.copyTo(*image);

    } while(false);

    qDebug() << "Leave " << __FUNCTION__;
}
