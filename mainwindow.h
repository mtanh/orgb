#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDesktopWidget>
#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QFileInfo>
#include <opencv2\core\core.hpp>
#include <opencv2\core\types_c.h>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

#define PERCENT_OF_WHOLE_SCREEN 0.9

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void centerAndResize();
    void setButtonsState(bool);
    void clearAllImages();

private slots:
    void on_btnOpen_clicked();

    void on_btnRGB2LCC_clicked();

    void on_btnRotation_clicked();

    void on_btnWarm2Cool_clicked();

private:
    Ui::MainWindow *ui;
    cv::Mat image;
};

#endif // MAINWINDOW_H
