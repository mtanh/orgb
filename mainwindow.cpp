#include <QVector>
#include <QImage>
#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "orgbcore.h"

static QImage* imageList[8];
static double alphaList[8] = { 4.2f, 3.7f, 3.2f, 2.7f, 2.2f, 1.7f, 1.2f, 0.7f };
static const int IMAGE_PADDING = 2;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/ico.png"));

    setButtonsState(false);
    ui->btnOpen->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::centerAndResize()
{
    // get the dimension available on this screen
    QSize availableSize = qApp->desktop()->availableGeometry().size();
    int width = availableSize.width();
    int height = availableSize.height();
    width *= PERCENT_OF_WHOLE_SCREEN;
    height *= PERCENT_OF_WHOLE_SCREEN;
    QSize newSize( width, height );

    setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    newSize,
                    qApp->desktop()->availableGeometry()
                    )
                );
}

void MainWindow::setButtonsState(bool state)
{
    ui->btnOpen->setEnabled(state);
    ui->btnRGB2LCC->setEnabled(state);
    ui->btnRotation->setEnabled(state);
    ui->btnWarm2Cool->setEnabled(state);
}

void MainWindow::clearAllImages()
{
    ui->lbOriginalImage->clear();
    ui->lbLCC->clear();
    ui->lbORGB->clear();
    ui->lbCoolingDown->clear();
}

void MainWindow::on_btnOpen_clicked()
{
    bool noProblem = true;
    do
    {
        clearAllImages();
        QString fileName =
                QFileDialog::getOpenFileName(this,
                                             tr("Open Image"), ".",
                                             tr("Image Files (*.png *.jpg *.jpeg)"));
        if(fileName.isEmpty())
        {
            noProblem = false;
            break;
        }

        if(!fileName.contains(QRegExp("[\\w\\-.]+\\.(png|jpg|jpeg)")))
        {
            noProblem = false;
            break;
        }

        image = cv::imread(fileName.toLatin1().data());
        if(!image.data)
        {
            noProblem = false;
            break;
        }

        cv::Mat rgb = image.clone();
        cv::cvtColor(rgb, rgb, CV_BGR2RGB);
        QImage img = QImage((const unsigned char*)(rgb.data),
                            rgb.cols, rgb.rows, QImage::Format_RGB888);
        ui->lbOriginalImage->setPixmap(QPixmap::fromImage(img));
        ui->lbOriginalImage->resize(ui->lbOriginalImage->pixmap()->size());

    } while (false);

    setButtonsState(noProblem);
    ui->btnOpen->setEnabled(true);
}

void MainWindow::on_btnRGB2LCC_clicked()
{
    do
    {
        setButtonsState(false);
        ui->pbProgress->setValue(40);

        cv::Mat lcc = image.clone();
        if(!lcc.data)
            break;

        st_processing_data processingdata;
        processingdata.image = &lcc;

        OrgbCore::getGlobalInstance()
                .pushData((void*)&processingdata, ORGB_CODE_RGB2LCC);

        processingdata = *((st_processing_data*)OrgbCore::getGlobalInstance().popData());
        cv::cvtColor(*processingdata.image, *processingdata.image, CV_BGR2RGB);
        QImage img = QImage((const unsigned char*)(lcc.data),
                            processingdata.image->cols,
                            processingdata.image->rows,
                            QImage::Format_RGB888);

        ui->lbLCC->setPixmap(QPixmap::fromImage(img));
        ui->lbLCC->resize(ui->lbLCC->pixmap()->size());

    } while(false);

    setButtonsState(true);
    ui->pbProgress->setValue(100);
}

void MainWindow::on_btnRotation_clicked()
{
    do
    {
        setButtonsState(false);
        ui->pbProgress->setValue(40);

        cv::Mat orgb = image.clone();
        if(!orgb.data)
            break;

        st_processing_data processingdata;
        processingdata.image = &orgb;

        OrgbCore::getGlobalInstance()
                .pushData((void*)&processingdata, ORGB_CODE_RGB2oRGB);

        processingdata = *((st_processing_data*)OrgbCore::getGlobalInstance().popData());
        cv::cvtColor(*processingdata.image, *processingdata.image, CV_BGR2RGB);
        QImage img = QImage((const unsigned char*)(orgb.data),
                            processingdata.image->cols,
                            processingdata.image->rows,
                            QImage::Format_RGB888);
        ui->lbORGB->setPixmap(QPixmap::fromImage(img));
        ui->lbORGB->resize(ui->lbORGB->pixmap()->size());

    } while(false);

    setButtonsState(true);
    ui->pbProgress->setValue(100);
}

void MainWindow::on_btnWarm2Cool_clicked()
{
    do
    {
        setButtonsState(false);
        ui->pbProgress->setValue(40);

        for(int idx = 0; idx < 8; ++idx)
        {
            cv::Mat coolingdown = image.clone();
            if(!coolingdown.data)
                break;

            st_processing_data processingdata;
            processingdata.image = &coolingdown;
            processingdata.alpha = alphaList[idx];

            OrgbCore::getGlobalInstance()
                    .pushData((void*)&processingdata, ORGB_CODE_RGB2oRGB2LCC2RGB);

            processingdata = *((st_processing_data*)OrgbCore::getGlobalInstance().popData());
            cv::cvtColor(*processingdata.image, *processingdata.image, CV_BGR2RGB);
            QImage* img = new QImage((const unsigned char*)(processingdata.image->data),
                                processingdata.image->cols, processingdata.image->rows,
                                QImage::Format_RGB888);
            QImage scaled = img->scaled(img->width()/3, img->height()/3, Qt::KeepAspectRatio);
            *img = scaled.copy();
            imageList[idx] = img;
        }

        cv::Mat cv_original = image.clone();
        cv::cvtColor(cv_original, cv_original, CV_BGR2RGB);
        QImage original = QImage((const unsigned char*)(cv_original.data),
                            cv_original.cols, cv_original.rows,
                            QImage::Format_RGB888);
        original = original.scaled(original.width()/3, original.height()/3, Qt::KeepAspectRatio);

        QImage result = QImage(image.cols + 2*IMAGE_PADDING,
                      image.rows + 2*IMAGE_PADDING,
                      QImage::Format_RGB888);
        QPainter painter;
        painter.begin(&result);
        painter.drawImage(0, 0, *imageList[0]);
        painter.drawImage(imageList[0]->width()+IMAGE_PADDING, 0, *imageList[1]);
        painter.drawImage(2*(imageList[0]->width()+IMAGE_PADDING), 0, *imageList[2]);
        painter.drawImage(0, imageList[0]->height()+IMAGE_PADDING, *imageList[3]);
        painter.drawImage(imageList[0]->width()+IMAGE_PADDING, imageList[0]->height()+IMAGE_PADDING, original);
        painter.drawImage(2*(imageList[0]->width()+IMAGE_PADDING), imageList[0]->height()+IMAGE_PADDING, *imageList[4]);
        painter.drawImage(0, 2*(imageList[0]->height()+IMAGE_PADDING), *imageList[5]);
        painter.drawImage(imageList[0]->width()+IMAGE_PADDING, 2*(imageList[0]->height()+IMAGE_PADDING), *imageList[6]);
        painter.drawImage(2*(imageList[0]->width()+IMAGE_PADDING), 2*(imageList[0]->height()+IMAGE_PADDING), *imageList[7]);
        painter.end();

        ui->lbCoolingDown->setPixmap(QPixmap::fromImage(result));
        ui->lbCoolingDown->resize(ui->lbCoolingDown->pixmap()->size());

        for(int idx = 0; idx < 8; ++idx)
        {
            delete imageList[idx];
            imageList[idx] = nullptr;
        }

    } while(false);

    setButtonsState(true);
    ui->pbProgress->setValue(100);
}
