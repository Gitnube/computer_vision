#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QGraphicsScene"
#include "QMessageBox"
#include "QTime"
#include "iimagefilter.h"
#include "iimageexpander.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void changeImage();
    void resetImage();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *sc;
    QImage original;
    QMap<QString, IImageFilter *> *imageFilters;
    QMap<QString, IImageExpander *> *imageExpanders;
};

#endif // MAINWINDOW_H
