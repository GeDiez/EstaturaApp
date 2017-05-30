#include "inicio.h"
#include "ui_inicio.h"
#include "stdio.h"

using namespace cv;
using namespace std;

ProcesadorImagenes *pim;

Inicio::Inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);
    pim = new ProcesadorImagenes();
    //ProcesadorImagenes *p = new ProcesadorImagenes();
    //p->tomarFoto();
}

Inicio::~Inicio()
{    
    delete ui;
}

void Inicio::on_btn_tomarFoto_clicked()
{
    pim->tomarFoto();
    ui->btn_toEscalaGrises->setEnabled(true);
}

void Inicio::on_btn_toEscalaGrises_clicked()
{
    pim->convertirEscalaGrises();
    pim->defHistograma();
    ui->btn_binaria->setEnabled(true);
}

void Inicio::on_btn_salir_clicked()
{
    destroyAllWindows();
}


void Inicio::on_btn_binaria_clicked()
{
    pim->otsu();
    pim->convertirBinario();
}
