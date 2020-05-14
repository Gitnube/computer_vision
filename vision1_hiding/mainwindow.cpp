#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dxcoregenerator.h"
#include "dycoregenerator.h"
#include "gausscoregenerator.h"
#include "emptyimageexpander.h"
#include "fillimageexpander.h"
#include "mirrorimageexpander.h"
#include "simplefilter.h"
#include "sobelfilter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTime time(0,0,0);
    qsrand(time.secsTo(QTime::currentTime()));
    sc=new QGraphicsScene();
    ui->graphicsView->setScene(sc);
    original = (new QImage("inp.jpg"))->convertToFormat(QImage::Format_Grayscale8);
    if(original.isNull())
        QMessageBox::critical(
                    this,
                    "Не удалось загрузить изображение",
                    "Пожалуйста, добавьте файл inp.jpg в каталог программы"
                );
    else
        sc->addPixmap(QPixmap::fromImage(original));
    imageFilters = new QMap<QString, IImageFilter *>();
    imageFilters->insert("DX", new SimpleFilter(new DXCoreGenerator()));
    imageFilters->insert("DY", new SimpleFilter(new DYCoreGenerator()));
    imageFilters->insert("Sobel", new SobelFilter());
    imageFilters->insert("Gauss", new SimpleFilter(new GaussCoreGenerator(2)));
    ui->imageFilterType->addItems(imageFilters->keys());
    imageExpanders = new QMap<QString, IImageExpander *>();
    imageExpanders->insert("Не заполнять", new EmptyImageExpander());
    imageExpanders->insert("Крайний пиксель", new FillImageExpander());
    imageExpanders->insert("Отражение", new MirrorImageExpander());
    ui->borderProcessType->addItems(imageExpanders->keys());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeImage()
{
    QString filterName = ui->imageFilterType->currentText();
    QString expanderName = ui->borderProcessType->currentText();
    IImageFilter *filter = imageFilters->value(filterName);
    QImage *img = filter->process(imageExpanders->value(expanderName), &original);
    sc->clear();
    sc->addPixmap(QPixmap::fromImage(*img));
    delete img;
}

void MainWindow::resetImage()
{
    sc->clear();
    sc->addPixmap(QPixmap::fromImage(original));
}
