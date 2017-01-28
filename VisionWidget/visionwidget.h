#ifndef VISIONWIDGET_H
#define VISIONWIDGET_H

#include <QtWidgets/QMainWindow>
#include "ui_visionwidget.h"
#include "FilterWidget.h"
#include "ThresholdWidget.h"
#include "GrayScaleWidget.h"
#include "CCWidget.h"
#include "EdgeDetectWidget.h"

class VisionWidget : public QMainWindow
{
    Q_OBJECT

public:
    VisionWidget(QWidget *parent = 0);
    ~VisionWidget();
private slots:
    void on_selectImageBtn_clicked();
    void on_checkBoxByerFormat_clicked(bool checked);
	void on_fitCircleBtn_clicked();
    void on_fitLineBtn_clicked();
    void on_fitParallelLineBtn_clicked();
    void on_fitRectBtn_clicked();
    void on_ocrBtn_clicked();
    void on_srchFiducialBtn_clicked();    
    void on_addPreProcessorBtn_clicked();    

protected:
    bool checkDisplayImage();
private:
    Ui::VisionWidgetClass               ui;
    std::string                         _sourceImagePath;
    cv::Mat                             _matOriginal;
    std::unique_ptr<QIntValidator>      _ptrIntValidator;
    std::unique_ptr<FilterWidget>       _ptrFilterWidget;
    std::unique_ptr<ThresholdWidget>    _ptrThresholdWidget;
    std::unique_ptr<GrayScaleWidget>    _ptrGrayScaleWidget;
    std::unique_ptr<CCWidget>           _ptrCcWidget;
    std::unique_ptr<EdgeDetectWidget>   _ptrEdgeDetectWidget;
};

#endif // VISIONWIDGET_H
