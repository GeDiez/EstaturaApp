#ifndef PROCESADORIMAGENES_H
#define PROCESADORIMAGENES_H
#include "opencv2/opencv.hpp"
#include "stdio.h"

using namespace cv;

class ProcesadorImagenes
{
private:
    Mat imagen;
    Mat EscalaGrises;
    Mat Binaria;
    int histograma[255];

public:
    ProcesadorImagenes();
    void tomarFoto();
    void convertirEscalaGrises();
    void defHistograma();
    int otsu();
    void convertirBinario();
};

#endif // PROCESADORIMAGENES_H
