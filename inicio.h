#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>
#include "opencv2/opencv.hpp"
#include "stdio.h"
#include "procesadorimagenes.h"

using namespace cv;

namespace Ui {
class Inicio;
}

class Inicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = 0);
    ~Inicio();
    void getChanelsRGB();

private slots:

    void on_btn_tomarFoto_clicked();

    void on_btn_toEscalaGrises_clicked();

    void on_btn_salir_clicked();

    void on_btn_binaria_clicked();

private:
    Ui::Inicio *ui;
};

#endif // INICIO_H
